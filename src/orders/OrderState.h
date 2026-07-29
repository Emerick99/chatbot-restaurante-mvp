#pragma once

#include <optional>
#include <string_view>

namespace restaurant::orders {

enum class OrderState {
    Created,
    PendingPayment,
    PaymentUnderReview,
    PaymentObserved,
    PaymentConfirmed,
    Assigned,
    EnRoute,
    AtDestination,
    Incident,
    Delivered,
    Cancelled,
};

enum class OrderEvent {
    SendQr,
    AttachPaymentProof,
    ObservePayment,
    ResubmitPaymentProof,
    ConfirmPayment,
    AssignCourier,
    AcknowledgeAssignment,
    ReassignCourier,
    StartTrip,
    UpdateLocation,
    ConfirmArrival,
    ConfirmDelivery,
    RegisterIncident,
    ResolveIncident,
    CancelOrder,
};

[[nodiscard]] std::string_view toString(OrderState state) noexcept;
[[nodiscard]] std::string_view toString(OrderEvent event) noexcept;
[[nodiscard]] std::optional<OrderState> orderStateFromString(
    std::string_view value) noexcept;
[[nodiscard]] bool isFinal(OrderState state) noexcept;
[[nodiscard]] bool isActive(OrderState state) noexcept;

class OrderStateMachine final {
  public:
    explicit OrderStateMachine(
        OrderState current = OrderState::Created,
        std::optional<OrderState> interruptedState = std::nullopt) noexcept;

    [[nodiscard]] OrderState current() const noexcept;
    [[nodiscard]] std::optional<OrderState> interruptedState() const noexcept;
    [[nodiscard]] bool canApply(OrderEvent event) const noexcept;

    // Returns false without changing the machine when the event is invalid.
    bool apply(OrderEvent event) noexcept;

  private:
    [[nodiscard]] std::optional<OrderState> nextState(
        OrderEvent event) const noexcept;

    OrderState current_;
    std::optional<OrderState> interruptedState_;
};

}  // namespace restaurant::orders
