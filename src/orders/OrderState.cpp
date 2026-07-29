#include "OrderState.h"

namespace restaurant::orders {

std::string_view toString(const OrderState state) noexcept {
    switch (state) {
        case OrderState::Created:
            return "CREADO";
        case OrderState::PendingPayment:
            return "PENDIENTE_PAGO";
        case OrderState::PaymentUnderReview:
            return "PAGO_EN_REVISION";
        case OrderState::PaymentObserved:
            return "PAGO_OBSERVADO";
        case OrderState::PaymentConfirmed:
            return "PAGO_CONFIRMADO";
        case OrderState::Assigned:
            return "ASIGNADO";
        case OrderState::EnRoute:
            return "EN_CAMINO";
        case OrderState::AtDestination:
            return "EN_DESTINO";
        case OrderState::Incident:
            return "EN_INCIDENCIA";
        case OrderState::Delivered:
            return "ENTREGADO";
        case OrderState::Cancelled:
            return "CANCELADO";
    }

    return "DESCONOCIDO";
}

std::string_view toString(const OrderEvent event) noexcept {
    switch (event) {
        case OrderEvent::SendQr:
            return "ENVIAR_QR";
        case OrderEvent::AttachPaymentProof:
            return "ADJUNTAR_COMPROBANTE";
        case OrderEvent::ObservePayment:
            return "OBSERVAR_PAGO";
        case OrderEvent::ResubmitPaymentProof:
            return "REENVIAR_COMPROBANTE";
        case OrderEvent::ConfirmPayment:
            return "CONFIRMAR_PAGO";
        case OrderEvent::AssignCourier:
            return "ASIGNAR_REPARTIDOR";
        case OrderEvent::AcknowledgeAssignment:
            return "CONFIRMAR_RECEPCION";
        case OrderEvent::ReassignCourier:
            return "REASIGNAR_REPARTIDOR";
        case OrderEvent::StartTrip:
            return "INICIAR_TRAYECTO";
        case OrderEvent::UpdateLocation:
            return "ACTUALIZAR_UBICACION";
        case OrderEvent::ConfirmArrival:
            return "CONFIRMAR_LLEGADA";
        case OrderEvent::ConfirmDelivery:
            return "CONFIRMAR_ENTREGA";
        case OrderEvent::RegisterIncident:
            return "REGISTRAR_INCIDENCIA";
        case OrderEvent::ResolveIncident:
            return "RESOLVER_INCIDENCIA";
        case OrderEvent::CancelOrder:
            return "CANCELAR_PEDIDO";
    }

    return "DESCONOCIDO";
}

std::optional<OrderState> orderStateFromString(
    const std::string_view value) noexcept {
    if (value == "CREADO") {
        return OrderState::Created;
    }
    if (value == "PENDIENTE_PAGO") {
        return OrderState::PendingPayment;
    }
    if (value == "PAGO_EN_REVISION") {
        return OrderState::PaymentUnderReview;
    }
    if (value == "PAGO_OBSERVADO") {
        return OrderState::PaymentObserved;
    }
    if (value == "PAGO_CONFIRMADO") {
        return OrderState::PaymentConfirmed;
    }
    if (value == "ASIGNADO") {
        return OrderState::Assigned;
    }
    if (value == "EN_CAMINO") {
        return OrderState::EnRoute;
    }
    if (value == "EN_DESTINO") {
        return OrderState::AtDestination;
    }
    if (value == "EN_INCIDENCIA") {
        return OrderState::Incident;
    }
    if (value == "ENTREGADO") {
        return OrderState::Delivered;
    }
    if (value == "CANCELADO") {
        return OrderState::Cancelled;
    }

    return std::nullopt;
}

bool isFinal(const OrderState state) noexcept {
    return state == OrderState::Delivered || state == OrderState::Cancelled;
}

bool isActive(const OrderState state) noexcept {
    return !isFinal(state) && state != OrderState::Incident;
}

OrderStateMachine::OrderStateMachine(
    const OrderState current,
    std::optional<OrderState> interruptedState) noexcept
    : current_(current), interruptedState_(interruptedState) {
    if (current_ != OrderState::Incident || !interruptedState_.has_value() ||
        !isActive(*interruptedState_)) {
        interruptedState_.reset();
    }
}

OrderState OrderStateMachine::current() const noexcept {
    return current_;
}

std::optional<OrderState> OrderStateMachine::interruptedState() const noexcept {
    return interruptedState_;
}

bool OrderStateMachine::canApply(const OrderEvent event) const noexcept {
    return nextState(event).has_value();
}

bool OrderStateMachine::apply(const OrderEvent event) noexcept {
    const auto next = nextState(event);
    if (!next.has_value()) {
        return false;
    }

    if (event == OrderEvent::RegisterIncident) {
        interruptedState_ = current_;
    } else if (event == OrderEvent::ResolveIncident ||
               event == OrderEvent::CancelOrder) {
        interruptedState_.reset();
    }

    current_ = *next;
    return true;
}

std::optional<OrderState> OrderStateMachine::nextState(
    const OrderEvent event) const noexcept {
    if (event == OrderEvent::CancelOrder &&
        (isActive(current_) || current_ == OrderState::Incident)) {
        return OrderState::Cancelled;
    }

    if (event == OrderEvent::RegisterIncident && isActive(current_)) {
        return OrderState::Incident;
    }

    if (event == OrderEvent::ResolveIncident &&
        current_ == OrderState::Incident && interruptedState_.has_value() &&
        isActive(*interruptedState_)) {
        return interruptedState_;
    }

    switch (current_) {
        case OrderState::Created:
            if (event == OrderEvent::SendQr) {
                return OrderState::PendingPayment;
            }
            break;

        case OrderState::PendingPayment:
            if (event == OrderEvent::AttachPaymentProof) {
                return OrderState::PaymentUnderReview;
            }
            break;

        case OrderState::PaymentUnderReview:
            if (event == OrderEvent::ObservePayment) {
                return OrderState::PaymentObserved;
            }
            if (event == OrderEvent::ConfirmPayment) {
                return OrderState::PaymentConfirmed;
            }
            break;

        case OrderState::PaymentObserved:
            if (event == OrderEvent::ResubmitPaymentProof) {
                return OrderState::PaymentUnderReview;
            }
            break;

        case OrderState::PaymentConfirmed:
            if (event == OrderEvent::AssignCourier) {
                return OrderState::Assigned;
            }
            break;

        case OrderState::Assigned:
            if (event == OrderEvent::AcknowledgeAssignment ||
                event == OrderEvent::ReassignCourier) {
                return OrderState::Assigned;
            }
            if (event == OrderEvent::StartTrip) {
                return OrderState::EnRoute;
            }
            break;

        case OrderState::EnRoute:
            if (event == OrderEvent::UpdateLocation) {
                return OrderState::EnRoute;
            }
            if (event == OrderEvent::ReassignCourier) {
                return OrderState::Assigned;
            }
            if (event == OrderEvent::ConfirmArrival) {
                return OrderState::AtDestination;
            }
            break;

        case OrderState::AtDestination:
            if (event == OrderEvent::ConfirmDelivery) {
                return OrderState::Delivered;
            }
            break;

        case OrderState::Incident:
        case OrderState::Delivered:
        case OrderState::Cancelled:
            break;
    }

    return std::nullopt;
}

}  // namespace restaurant::orders
