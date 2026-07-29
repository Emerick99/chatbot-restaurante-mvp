# Requisitos del sistema

## 1. Objetivo general

Desarrollar un producto mínimo viable (MVP) para gestionar pedidos de un restaurante mediante dos partes obligatorias e integradas: un bot de Telegram y un panel web de administración.

El sistema debe acompañar el pedido desde la consulta del menú hasta la entrega, permitiendo que cliente, repartidor y administrador trabajen sobre la misma información.

## 2. Alcance del MVP

El MVP comprende la gestión del menú, la creación y seguimiento de pedidos, la validación manual del pago, la asignación del reparto y la confirmación de la entrega.

### 2.1. Bot de Telegram

El bot será el canal de interacción para clientes y repartidores.

Para el cliente permitirá:

- Identificarse mediante su cuenta de Telegram.
- Consultar el menú disponible.
- Seleccionar platos y cantidades para armar un pedido.
- Enviar la ubicación de entrega.
- Recibir el código QR de pago.
- Enviar el comprobante de pago.
- Recibir un código de seguimiento.
- Consultar el estado del pedido y recibir notificaciones.

Para el repartidor permitirá:

- Identificarse según su rol.
- Recibir los pedidos asignados.
- Consultar la información necesaria para realizar la entrega.
- Compartir su ubicación en tiempo real.
- Confirmar la llegada al destino.
- Confirmar la entrega y adjuntar la evidencia requerida.

### 2.2. Panel web de administración

El panel será el canal de trabajo del administrador y permitirá:

- Autenticarse de forma segura.
- Gestionar platos y configurar el menú por fecha.
- Controlar disponibilidad y stock.
- Consultar y administrar el tablero de pedidos.
- Revisar comprobantes y confirmar pagos manualmente.
- Asignar y reasignar repartidores.
- Consultar la ubicación del repartidor y verificar su llegada.
- Realizar seguimiento de clientes y pedidos.
- Consultar información básica de ventas y entregas.

### 2.3. Integración entre bot y panel

El bot y el panel forman un único sistema y deben:

- Utilizar una única base de datos.
- Compartir un único modelo de pedido.
- Compartir el mismo catálogo, menú, stock, clientes, pagos, repartidores y ubicaciones.
- Utilizar un único modelo de estados del pedido.
- Reflejar de forma consistente en ambos canales cada cambio realizado sobre un pedido.

## 3. Actores del sistema

| Actor | Canal principal | Propósito |
|---|---|---|
| Cliente | Bot de Telegram | Consultar el menú, crear el pedido, completar el pago y seguir la entrega. |
| Repartidor o delivery | Bot de Telegram | Recibir pedidos asignados, compartir su ubicación y confirmar la entrega. |
| Administrador | Panel web | Configurar la operación del restaurante y controlar pedidos, pagos y repartos. |

### 3.1. Cliente

Responsabilidades principales:

- Consultar el menú disponible.
- Armar un pedido seleccionando platos y cantidades.
- Enviar su ubicación y los datos necesarios para la entrega.
- Recibir el código QR de pago.
- Enviar el comprobante de pago.
- Consultar el estado del pedido mediante su código de seguimiento.
- Atender las notificaciones relacionadas con el pedido.

### 3.2. Repartidor o delivery

Responsabilidades principales:

- Recibir los pedidos que le asigne el administrador.
- Consultar los datos necesarios del pedido y del cliente.
- Compartir su ubicación en tiempo real durante el trayecto.
- Confirmar por separado la llegada al destino y la entrega.
- Adjuntar la evidencia solicitada para completar la entrega.

### 3.3. Administrador

Responsabilidades principales:

- Configurar el menú para cada fecha.
- Controlar la disponibilidad y el stock de los platos.
- Administrar el tablero y los estados de los pedidos.
- Revisar comprobantes y confirmar pagos.
- Distribuir los pedidos entre uno o dos repartidores registrados.
- Asignar o reasignar un único repartidor activo a cada pedido.
- Consultar el seguimiento del repartidor y verificar su llegada al destino.
- Realizar seguimiento de clientes y pedidos.
- Consultar información operativa y reportes básicos del MVP.

## 4. Reglas y límites iniciales

- El sistema atenderá a un solo restaurante.
- El menú se configurará por fecha y solo mostrará platos disponibles.
- El pago se validará manualmente mediante un código QR y un comprobante enviado por el cliente.
- El sistema trabajará con uno o dos repartidores registrados.
- Cada pedido tendrá como máximo un repartidor activo a la vez; una reasignación reemplazará la asignación anterior.
- La ubicación se obtendrá mediante las funciones de Telegram y se utilizará para el seguimiento de la entrega.
- Los cambios de estado deberán respetar el modelo de estados compartido por bot y panel.
- La entrega se completará únicamente después de registrar la confirmación y la evidencia requerida.

## 5. Fuera del alcance inicial

No forman parte de esta primera versión:

- Una aplicación móvil nativa independiente de Telegram.
- La integración automática con pasarelas bancarias o cobros con tarjeta.
- La operación simultánea de varias sucursales o restaurantes.
- La optimización automática de rutas.
- La integración con plataformas externas de reparto.
- Un sistema contable, de facturación o de compras a proveedores.
- Funciones adicionales que no sean necesarias para demostrar el flujo completo del pedido.
