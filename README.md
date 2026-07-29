# Chatbot Restaurante MVP

Producto mínimo viable para gestionar pedidos de un restaurante mediante un bot de Telegram y un panel web de administración integrados.

## Objetivo

Acompañar cada pedido desde la consulta del menú hasta la entrega, permitiendo que cliente, repartidor y administrador trabajen sobre la misma información.

## Alcance del MVP

El sistema comprende:

- Gestión de platos, menú por fecha, disponibilidad y stock.
- Creación y seguimiento de pedidos.
- Envío y validación manual del comprobante de pago.
- Asignación y seguimiento del repartidor.
- Confirmación de llegada y entrega.
- Consulta de información básica de clientes, ventas y entregas.
- Una única base de datos y un único modelo de estados compartidos por el bot y el panel.

## Componentes

### Bot de Telegram

Es el canal de interacción para clientes y repartidores.

- El cliente consulta el menú, arma su pedido, envía la ubicación, recibe el QR de pago, adjunta el comprobante y consulta el seguimiento.
- El repartidor recibe pedidos asignados, consulta los datos de entrega, comparte su ubicación en tiempo real y confirma la llegada y la entrega.

### Panel de administración web

Es el canal de trabajo del administrador. Permite gestionar platos y menús, controlar stock, administrar pedidos, validar pagos, asignar repartidores, supervisar entregas y consultar reportes básicos.

Ambos componentes comparten la misma lógica de negocio y persistencia para mantener consistentes los pedidos, pagos, estados, asignaciones y ubicaciones.

## Actores

| Actor | Canal principal | Responsabilidad |
|---|---|---|
| Cliente | Bot de Telegram | Consultar el menú, crear y pagar el pedido, y seguir su entrega. |
| Repartidor | Bot de Telegram | Recibir pedidos, compartir su ubicación y confirmar la entrega. |
| Administrador | Panel web | Configurar la operación y controlar pedidos, pagos y repartos. |

## Documentación

- [Requisitos y alcance](docs/requisitos.md)
- [Decisiones técnicas](docs/decisiones-tecnicas.md)
- [Registro de uso de IA](docs/uso-ia.md)
- [Declaración de autoría](docs/declaracion-autoria.md)
- [Flujo de colaboración](CONTRIBUTING.md)
