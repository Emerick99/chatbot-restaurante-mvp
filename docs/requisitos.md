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

## 6. Historias de usuario del cliente

### HU-CLI-01. Identificar y conservar el perfil

Como cliente, quiero que el bot me identifique mediante mi chat_id, para conservar mis datos y asociar correctamente mis pedidos.

#### Criterios de aceptación

- Al iniciar una conversación por primera vez, el sistema crea un único perfil asociado al chat_id de Telegram.
- Si el mismo chat_id vuelve a interactuar, el sistema recupera el perfil existente y no crea un duplicado.
- Los pedidos creados desde el bot quedan asociados al perfil identificado.
- Un chat_id no puede consultar pedidos pertenecientes a otro cliente.

### HU-CLI-02. Consultar el menú disponible

Como cliente, quiero consultar el menú disponible para la fecha actual, para elegir únicamente platos que el restaurante puede preparar.

#### Criterios de aceptación

- El bot muestra solo el menú configurado para la fecha actual.
- Cada opción informa como mínimo el nombre, precio y disponibilidad del plato.
- Los platos sin disponibilidad no pueden agregarse al carrito.
- Si no existe un menú disponible para la fecha actual, el bot informa la situación y no permite iniciar un pedido.

### HU-CLI-03. Seleccionar platos y cantidades

Como cliente, quiero seleccionar platos y cantidades, para construir un pedido según mis necesidades.

#### Criterios de aceptación

- El bot permite seleccionar únicamente platos pertenecientes al menú disponible.
- La cantidad debe ser un número entero mayor que cero.
- Cada selección válida se agrega al carrito con su precio y subtotal.
- Después de agregar un plato, el bot permite continuar comprando o revisar el carrito.
- Una cantidad inválida no modifica el carrito.

### HU-CLI-04. Visualizar y modificar el carrito

Como cliente, quiero visualizar y modificar mi carrito, para corregir el pedido antes de confirmarlo.

#### Criterios de aceptación

- El carrito muestra cada plato, su cantidad, precio unitario y subtotal.
- El bot calcula y muestra el total actualizado del pedido.
- El cliente puede cambiar la cantidad de un plato ya agregado.
- El cliente puede eliminar un plato del carrito.
- Si se elimina el último plato, el sistema informa que el carrito está vacío y no permite continuar al pago.

### HU-CLI-05. Validar cantidades contra el stock

Como cliente, quiero que las cantidades solicitadas se validen contra el stock disponible, para evitar confirmar productos que no pueden prepararse.

#### Criterios de aceptación

- El sistema compara la cantidad solicitada con el stock disponible antes de agregar o actualizar un plato.
- Si la cantidad supera el stock, el bot rechaza la operación e informa la cantidad máxima disponible.
- El sistema vuelve a validar el stock antes de confirmar el pedido.
- Ninguna operación puede dejar el stock con un valor negativo.
- Un rechazo por falta de stock conserva sin cambios las demás opciones válidas del carrito.

### HU-CLI-06. Enviar la ubicación de entrega

Como cliente, quiero enviar mi ubicación de entrega, para que el restaurante y el repartidor conozcan el destino del pedido.

#### Criterios de aceptación

- El bot solicita una ubicación compartida mediante Telegram antes de completar el pedido.
- El sistema almacena la latitud y longitud recibidas y las asocia al pedido en curso.
- El cliente puede agregar una dirección o referencia textual complementaria.
- Si el mensaje no contiene una ubicación válida, el bot explica cómo enviarla y mantiene el flujo en el mismo paso.
- El pedido no avanza al pago mientras no exista una ubicación válida.

### HU-CLI-07. Recibir el código QR de pago

Como cliente, quiero recibir el código QR de pago, para realizar el pago del total de mi pedido.

#### Criterios de aceptación

- El bot envía el QR únicamente después de validar el carrito, el stock y la ubicación.
- El mensaje del QR informa el monto total que debe pagarse.
- El QR enviado corresponde a la configuración activa del restaurante.
- Si el QR no está configurado, el bot informa que el pago no puede continuar y conserva el pedido pendiente.
- El envío del QR no confirma automáticamente el pago.

### HU-CLI-08. Enviar el comprobante de pago

Como cliente, quiero enviar mi comprobante de pago, para que el administrador pueda revisarlo y confirmar el pago.

#### Criterios de aceptación

- El bot acepta el comprobante en un formato de imagen o documento permitido.
- El archivo recibido se almacena y queda asociado al pedido correcto.
- Después de recibirlo, el pedido queda pendiente de verificación manual.
- El bot confirma al cliente que el comprobante fue recibido, sin afirmar que el pago ya fue aprobado.
- Un archivo vacío o con formato no permitido se rechaza con una instrucción para volver a enviarlo.

### HU-CLI-09. Recibir y usar el código de seguimiento

Como cliente, quiero recibir un código de seguimiento, para consultar mi pedido sin confundirlo con otros pedidos.

#### Criterios de aceptación

- Cada pedido confirmado recibe un código de seguimiento único.
- El bot comunica el código al cliente y lo asocia al pedido correspondiente.
- Al consultar un código válido, el bot muestra el estado actual del pedido.
- Un código inexistente o perteneciente a otro cliente no revela información del pedido.
- El código se mantiene sin cambios durante todo el ciclo de vida del pedido.

### HU-CLI-10. Recibir notificaciones de estado

Como cliente, quiero recibir notificaciones cuando cambie el estado de mi pedido, para conocer su avance hasta la entrega.

#### Criterios de aceptación

- El bot notifica cada cambio de estado relevante después de que el cambio se registra.
- La notificación incluye el código de seguimiento y el nuevo estado.
- Si el estado no cambió, el sistema no envía una notificación duplicada.
- Las notificaciones se envían únicamente al chat_id asociado al pedido.
- El estado informado por el bot coincide con el mostrado en el panel de administración.

### HU-CLI-11. Cancelar y reiniciar el flujo

Como cliente, quiero cancelar o reiniciar la conversación de pedido, para corregir un flujo que ya no deseo continuar.

#### Criterios de aceptación

- Antes de confirmar el pedido, el cliente puede cancelar el flujo mediante la opción o comando definido.
- La cancelación elimina los datos temporales del carrito y de la ubicación del flujo actual.
- La cancelación no elimina el perfil ni el historial de pedidos anteriores.
- Al reiniciar, el bot vuelve al menú principal y permite comenzar un carrito vacío.
- Un pedido ya confirmado no se cancela silenciosamente mediante el reinicio de la conversación.

### HU-CLI-12. Manejar entradas inválidas o fuera de contexto

Como cliente, quiero recibir orientación ante entradas inválidas o fuera de contexto, para continuar el pedido sin perder la información válida.

#### Criterios de aceptación

- Ante una entrada inválida, el bot informa qué dato esperaba y ofrece una forma válida de continuar.
- La entrada inválida no crea pedidos, pagos ni registros duplicados.
- El sistema conserva el último paso válido y no avanza hasta recibir una respuesta aceptable.
- Un comando global permitido, como ayuda o cancelación, funciona desde cualquier paso del flujo.
- Después del error, el cliente puede continuar sin reiniciar obligatoriamente toda la conversación.

