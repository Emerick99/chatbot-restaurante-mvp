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

## 7. Historias de usuario del repartidor

### HU-REP-01. Identificarse y acceder según el rol

Como repartidor, quiero autenticarme e identificarme mediante Telegram, para acceder únicamente a las funciones correspondientes a mi rol.

#### Criterios de aceptación

- El sistema reconoce como repartidor únicamente un chat_id previamente habilitado por el administrador.
- Un usuario sin el rol de repartidor no puede acceder a pedidos asignados ni a comandos de reparto.
- El bot muestra al repartidor solo los comandos permitidos para su rol.
- La identidad del repartidor queda asociada a cada acción realizada sobre un pedido.

### HU-REP-02. Recibir un pedido asignado

Como repartidor, quiero recibir los pedidos que me asigne el administrador, para iniciar oportunamente el proceso de entrega.

#### Criterios de aceptación

- La asignación realizada en el panel genera de inmediato un mensaje al repartidor seleccionado.
- El mensaje incluye el número de pedido, los platos y sus cantidades, el importe total, el estado del pago, la dirección y referencia, y el nombre y contacto del cliente.
- La ubicación de entrega se envía como objeto `Location` de Telegram y puede abrirse en el mapa del dispositivo.
- El mensaje incluye un botón de acuse de recibo mediante `InlineKeyboardMarkup`.
- Solo el repartidor con la asignación activa puede operar sobre el pedido.
- Un pedido no asignado no aparece entre los pedidos activos del repartidor.

### HU-REP-03. Consultar la información del pedido

Como repartidor, quiero consultar el detalle del pedido asignado, para verificar qué productos debo transportar y el estado del pago.

#### Criterios de aceptación

- El bot muestra el número del pedido, platos, cantidades y total.
- El bot informa si el pago está pendiente, observado o confirmado.
- La información coincide con los datos visibles en el panel de administración.
- Un cambio realizado en el pedido se refleja en la siguiente consulta del repartidor.

### HU-REP-04. Consultar los datos del cliente y del destino

Como repartidor, quiero consultar los datos del cliente y la ubicación de entrega, para comunicarme y llegar al destino correcto.

#### Criterios de aceptación

- El bot muestra el nombre y el contacto registrados del cliente.
- El bot muestra la dirección y la referencia de entrega cuando estén disponibles.
- El bot entrega la ubicación del destino como objeto `Location` de Telegram, abrible en el mapa del dispositivo.
- Los datos solo son visibles para el repartidor con la asignación activa.
- Un pedido sin ubicación válida no puede iniciar el trayecto de entrega.

### HU-REP-05. Confirmar la recepción del pedido asignado

Como repartidor, quiero confirmar que recibí el pedido asignado, para informar al administrador que iniciaré la entrega.

#### Criterios de aceptación

- El repartidor confirma únicamente un pedido que tenga asignado mediante el botón de acuse de recibo.
- La confirmación registra repartidor, pedido, fecha y hora.
- El panel refleja la confirmación sin necesidad de volver a asignar el pedido.
- Una segunda pulsación del botón no crea eventos duplicados.
- El administrador recibe una indicación de que el pedido fue aceptado.

### HU-REP-06. Mantener una reasignación consistente

Como repartidor, quiero que las reasignaciones se actualicen correctamente, para no operar sobre pedidos que ya corresponden a otro repartidor.

#### Criterios de aceptación

- Al reasignar un pedido, la asignación anterior deja de estar activa.
- El repartidor anterior ya no puede actualizar la ubicación ni confirmar eventos del pedido.
- El nuevo repartidor recibe de inmediato el mensaje completo del pedido, incluida la ubicación como objeto `Location`.
- Los puntos del rastro permanecen asociados al repartidor que los generó y nunca se mezclan entre ambos repartidores.
- El historial conserva quién realizó la asignación, el repartidor anterior, el nuevo repartidor y la fecha y hora.
- El pedido mantiene un único repartidor activo después de la reasignación.

### HU-REP-07. Compartir la ubicación en tiempo real

Como repartidor, quiero compartir mi ubicación en tiempo real durante el trayecto, para que el administrador pueda seguir la entrega.

#### Criterios de aceptación

- El seguimiento se inicia únicamente con la `live location` de Telegram; una ubicación estática enviada una sola vez no activa el rastreo.
- Cada actualización recibida se vincula al pedido y al repartidor activos.
- El mapa del panel se actualiza cada 15 segundos con la última ubicación recibida.
- Al iniciar el trayecto, el cliente recibe una notificación diferenciada de que su pedido está en camino.
- Una ubicación asociada a otro pedido o repartidor se rechaza.
- El seguimiento termina cuando se confirma la entrega o se cancela la asignación.

### HU-REP-08. Registrar el rastro de ubicación

Como repartidor, quiero que el sistema conserve el rastro de mi ubicación, para disponer de evidencia del trayecto realizado.

#### Criterios de aceptación

- Cada punto válido almacena latitud, longitud, fecha y hora.
- Cada punto queda asociado al pedido y al repartidor correspondientes.
- Los puntos se consultan en orden cronológico.
- Una actualización repetida con la misma marca temporal no crea un punto duplicado.
- El historial permanece disponible después de finalizar la entrega.

### HU-REP-09. Continuar después de una pérdida de señal

Como repartidor, quiero que el seguimiento se recupere después de una pérdida de señal, para continuar la entrega sin perder el rastro anterior.

#### Criterios de aceptación

- Si transcurren 60 segundos sin una nueva actualización, el sistema considera que existe pérdida de señal y conserva la última ubicación válida.
- El panel muestra el estado `Sin señal`, la última ubicación y la hora de su recepción.
- La pérdida de señal no marca automáticamente el pedido como entregado ni cancelado.
- Al recuperar la conexión, las nuevas ubicaciones continúan el rastro del mismo pedido y repartidor.
- El bot informa al repartidor si una actualización no pudo registrarse y permite reintentar.

### HU-REP-10. Confirmar la llegada al destino

Como repartidor, quiero confirmar mi llegada al destino, para informar que estoy en el punto de entrega.

#### Criterios de aceptación

- Solo el repartidor asignado puede confirmar la llegada.
- La llegada registra pedido, repartidor, fecha, hora y ubicación disponible.
- El evento de llegada se refleja en el panel y el cliente recibe la notificación diferenciada `El repartidor llegó`.
- La llegada y la entrega se almacenan como eventos distintos.
- La llegada debe registrarse antes de confirmar la entrega.

### HU-REP-11. Confirmar la entrega con evidencia

Como repartidor, quiero confirmar la entrega adjuntando evidencia, para dejar constancia verificable de que el pedido fue recibido.

#### Criterios de aceptación

- Solo el repartidor asignado puede confirmar la entrega.
- La confirmación exige como evidencia una fotografía o un código proporcionado por el cliente.
- La evidencia queda asociada al pedido junto con la fecha, hora y repartidor.
- Sin evidencia válida, el pedido no cambia al estado de entregado.
- Al confirmar la entrega, el panel se actualiza y el cliente recibe la notificación diferenciada `Pedido entregado`.
- Una entrega ya confirmada no puede registrarse nuevamente.

## 8. Historias de usuario del administrador

### HU-ADM-01. Acceder de forma segura al panel

Como administrador, quiero autenticarme de forma segura, para impedir el acceso no autorizado a la gestión del restaurante.

#### Criterios de aceptación

- El panel permite iniciar sesión únicamente con credenciales válidas.
- Las contraseñas se almacenan mediante hash y no se muestran en respuestas ni registros.
- Un intento con credenciales inválidas muestra un error sin revelar cuál dato falló.
- Todas las rutas internas rechazan o redirigen a quien no tenga una sesión válida.
- Al cerrar sesión o expirar la sesión, el acceso interno vuelve a requerir autenticación.

### HU-ADM-02. Gestionar los platos

Como administrador, quiero crear, consultar, editar y eliminar platos, para mantener actualizado el catálogo del restaurante.

#### Criterios de aceptación

- El administrador puede crear un plato con sus datos obligatorios y un precio mayor que cero.
- El panel lista los platos registrados con su precio, disponibilidad y stock.
- La edición persiste los cambios y los muestra al volver a consultar el plato.
- Al eliminar un plato, deja de aparecer en el catálogo operativo y en menús futuros sin alterar pedidos históricos.
- Los datos inválidos se rechazan con un mensaje y no generan cambios parciales.

### HU-ADM-03. Configurar el menú por fecha

Como administrador, quiero configurar los platos disponibles para cada fecha, para publicar el menú correspondiente al día de atención.

#### Criterios de aceptación

- El administrador puede asociar o retirar platos de una fecha seleccionada.
- El bot muestra únicamente el menú configurado para la fecha actual.
- Un cambio guardado en el panel se refleja en la siguiente consulta del menú desde el bot.
- Un plato no asociado a la fecha actual no puede agregarse al carrito.
- Si no existe menú para la fecha actual, el bot informa que no hay opciones disponibles.

### HU-ADM-04. Controlar disponibilidad y stock

Como administrador, quiero controlar la disponibilidad y el stock de los platos, para evitar pedidos que el restaurante no puede preparar.

#### Criterios de aceptación

- El administrador puede habilitar o deshabilitar un plato y registrar un stock entero no negativo.
- El bot ofrece únicamente platos habilitados y con stock mayor que cero.
- Al confirmarse un pedido, el stock de cada plato se descuenta exactamente una vez.
- Cuando el stock llega a cero, el plato deja de aparecer en el menú del bot sin intervención manual.
- Dos confirmaciones concurrentes no pueden producir stock negativo; si no alcanza, una operación se rechaza sin afectar a la otra.

### HU-ADM-05. Administrar el tablero y los estados

Como administrador, quiero consultar el tablero y cambiar el estado de los pedidos, para controlar su avance desde la recepción hasta la entrega.

#### Criterios de aceptación

- El tablero muestra para cada pedido su número, cliente, estado, pago y repartidor activo.
- El administrador puede realizar únicamente cambios permitidos por el modelo de estados.
- Una transición inválida se rechaza sin alterar el pedido.
- Cada cambio registra el estado anterior, el nuevo estado, el administrador, la fecha y la hora.
- El nuevo estado se refleja en el bot y genera la notificación correspondiente al cliente.

### HU-ADM-06. Revisar y confirmar pagos manualmente

Como administrador, quiero visualizar el comprobante y confirmar manualmente el pago, para validar que el pedido fue pagado antes de continuar.

#### Criterios de aceptación

- El panel permite abrir el comprobante asociado al pedido correcto.
- La recepción del comprobante no marca automáticamente el pedido como pagado.
- El administrador puede confirmar el pago o marcarlo como observado.
- La decisión registra el administrador, la fecha y la hora y se refleja en el bot.
- Una segunda confirmación del mismo pago no duplica eventos ni efectos.

### HU-ADM-07. Asignar y reasignar repartidores

Como administrador, quiero asignar o reasignar un repartidor registrado, para decidir quién realizará cada entrega.

#### Criterios de aceptación

- El pedido ofrece un selector con los repartidores registrados.
- Al asignar, el pedido conserva un único repartidor activo y el bot le envía de inmediato el mensaje completo.
- Al reasignar, el repartidor anterior pierde el acceso operativo al pedido.
- El nuevo repartidor recibe el mensaje completo y el rastro no mezcla ubicaciones de ambos.
- El historial registra quién asignó, el repartidor anterior, el nuevo repartidor, la fecha y la hora.

### HU-ADM-08. Seguir la entrega en el mapa

Como administrador, quiero visualizar al repartidor y el destino en un mapa, para supervisar el trayecto y reconocer su llegada.

#### Criterios de aceptación

- El mapa muestra la ubicación de destino y la última posición válida del repartidor asignado.
- Durante el trayecto, el mapa se actualiza cada 15 segundos con la última `live location` recibida.
- El panel muestra la hora de la última actualización y el estado de señal.
- La confirmación de llegada aparece como un evento distinto de la entrega.
- Una reasignación hace que el mapa continúe con la ubicación del nuevo repartidor sin mezclar rastros.

### HU-ADM-09. Consultar la ficha y frecuencia del cliente

Como administrador, quiero consultar la ficha y el historial de un cliente, para conocer su relación con el restaurante.

#### Criterios de aceptación

- La ficha muestra los datos registrados del cliente sin mezclar información de otros perfiles.
- El historial lista sus pedidos en orden cronológico con fecha, total y estado.
- La frecuencia se calcula con la cantidad de pedidos no cancelados dentro del período consultado.
- El período utilizado y el total de pedidos considerados se muestran junto al resultado.
- Los datos coinciden con los pedidos almacenados para ese cliente.

### HU-ADM-10. Consultar las ventas del día

Como administrador, quiero consultar las ventas del día, para conocer el resultado diario del restaurante.

#### Criterios de aceptación

- El reporte utiliza la fecha local seleccionada y muestra la cantidad de pedidos con pago confirmado.
- El total de ventas es la suma de los importes de esos pedidos.
- Los pedidos pendientes, observados o cancelados no se incluyen como ventas.
- El reporte evita contar dos veces un mismo pedido.
- La cantidad y el total coinciden con los registros de la base de datos.

### HU-ADM-11. Consultar los platos más pedidos

Como administrador, quiero consultar los platos más pedidos, para identificar las preferencias de los clientes.

#### Criterios de aceptación

- El reporte suma las cantidades vendidas de cada plato durante el período seleccionado.
- Solo considera pedidos con pago confirmado y excluye los cancelados.
- Los platos se ordenan de mayor a menor cantidad vendida.
- El reporte muestra el período y la cantidad total de cada plato.
- Los resultados coinciden con el detalle de los pedidos almacenados.

### HU-ADM-12. Consultar el tiempo promedio de entrega

Como administrador, quiero consultar el tiempo promedio de entrega, para evaluar la duración de los repartos completados.

#### Criterios de aceptación

- El tiempo de cada entrega se calcula desde el evento `En camino` hasta el evento `Entregado`.
- El promedio considera únicamente pedidos entregados dentro del período seleccionado.
- El resultado se muestra en minutos junto con la cantidad de entregas consideradas.
- Un pedido sin ambos eventos no altera el promedio.
- Si no existen entregas válidas, el panel informa que no hay datos suficientes.
