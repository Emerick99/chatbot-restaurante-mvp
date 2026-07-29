# Bitácora de decisiones técnicas

## Propósito

Este documento registra las decisiones técnicas del MVP, las alternativas consideradas y las consecuencias conocidas. Las decisiones pueden revisarse cuando aparezca nueva información, pero los cambios se documentarán sin borrar el historial anterior.

## Estructura de cada decisión

Cada registro utiliza los mismos campos:

- **Fecha:** día en que se adopta o revisa la decisión.
- **Título de la decisión:** identificador y tema indicado en el encabezado de cada registro.
- **Estado:** propuesta, aceptada, sustituida o descartada.
- **Contexto o problema:** necesidad que origina la decisión.
- **Alternativas evaluadas:** opciones consideradas y su diferencia principal.
- **Decisión adoptada:** alternativa seleccionada.
- **Motivo:** razón de la elección para este MVP.
- **Ventajas:** beneficios esperados.
- **Desventajas o consecuencias:** costos, riesgos y restricciones aceptados.

---

## DT-001 — Lenguaje y herramientas de construcción

- **Fecha:** 2026-07-29
- **Estado:** Aceptada

### Contexto o problema

El sistema debe integrar un bot de Telegram y un panel web. Además de terminar el MVP, el postulante debe poder explicar, justificar y modificar el código durante la defensa.

### Alternativas evaluadas

- **Python 3 con Flask:** permite desarrollar rápidamente, pero el postulante indicó que no podría defender con seguridad una solución escrita en Python.
- **Node.js con Express:** facilita aplicaciones web, pero introduciría un lenguaje que el postulante no confirmó dominar.
- **C++17:** es el lenguaje conocido por el postulante y dispone de bibliotecas para HTTP, Telegram y SQLite.

### Decisión adoptada

Utilizar **C++17** como lenguaje principal, **CMake** para construir el proyecto y **vcpkg** para instalar dependencias.

### Motivo

Se prioriza que el postulante comprenda y pueda defender la solución. C++17 ofrece las características necesarias sin exigir funcionalidades más recientes del estándar y mantiene compatibilidad amplia con las bibliotecas elegidas.

### Ventajas

- El postulante trabaja con un lenguaje que conoce.
- Un solo lenguaje implementa el bot, el panel y la lógica de negocio.
- El tipado estático y RAII ayudan a controlar recursos y errores.
- CMake permite declarar una construcción reproducible.

### Desventajas o consecuencias

- La instalación inicial de dependencias es más trabajosa que en Python.
- Los tiempos de compilación y la cantidad de código son mayores.
- El manual de instalación deberá documentar compilador, CMake, vcpkg y comandos exactos.

---

## DT-002 — Tecnología del bot de Telegram

- **Fecha:** 2026-07-29
- **Estado:** Aceptada

### Contexto o problema

El bot debe usar funciones nativas de Telegram, entre ellas fotografías, objetos `Location`, `live location`, teclados inline y consultas por botón. Implementar manualmente toda la comunicación HTTP aumentaría el alcance.

### Alternativas evaluadas

- **Bot API directa mediante libcurl:** ofrece control completo, pero exige implementar peticiones, archivos, JSON, long polling y manejo de errores.
- **tgbot-cpp con long polling:** proporciona tipos y métodos C++ para la Bot API y funciona sin exponer una URL pública.
- **Webhook recibido por Drogon:** es apropiado para despliegue público, pero requiere HTTPS y una dirección accesible desde Internet.

### Decisión adoptada

Utilizar **tgbot-cpp** mediante **long polling** para el MVP local.

### Motivo

La biblioteca permite conservar C++ como único lenguaje y ya expone las operaciones obligatorias, como `sendPhoto`, ubicación, actualización de ubicación en vivo y teclados inline. El long polling reduce requisitos de infraestructura durante la defensa.

### Ventajas

- Evita construir manualmente un cliente completo de Telegram.
- Permite recibir mensajes, ubicaciones, fotografías y pulsaciones de botones.
- No requiere dominio, certificado ni servidor público para la demostración local.

### Desventajas o consecuencias

- El proyecto depende de una biblioteca externa y de sus versiones soportadas.
- Si una función futura de Telegram no estuviera disponible, deberá aislarse una llamada directa a la Bot API.
- La integración quedará detrás de un adaptador `TelegramGateway` para no acoplar la lógica de negocio a la biblioteca.

---

## DT-003 — Tecnología del panel web

- **Fecha:** 2026-07-29
- **Estado:** Aceptada

### Contexto o problema

El administrador necesita un panel web con autenticación, formularios CRUD, tablero, reportes y un mapa actualizado. Se busca mantener C++ y evitar una arquitectura de frontend separada.

### Alternativas evaluadas

- **Drogon:** framework web C++ con rutas, filtros, sesiones, contenido estático y acceso a datos.
- **Crow:** microframework C++ liviano, pero requeriría integrar más componentes para sesiones y persistencia.
- **Aplicación de escritorio con Qt:** permitiría usar C++, pero no cumpliría el requisito de panel web.
- **Flask:** simplificaría el panel, pero introduciría Python, que el postulante indicó que no podría defender con seguridad.

### Decisión adoptada

Utilizar **Drogon** para servir el panel mediante HTML generado en el servidor, rutas protegidas y endpoints JSON puntuales.

### Motivo

Drogon concentra las capacidades web necesarias en un framework C++ y permite compartir directamente los servicios de aplicación con el bot.

### Ventajas

- Mantiene un único lenguaje en el servidor.
- Permite organizar rutas, filtros de autenticación y sesiones.
- Sirve HTML, CSS, JavaScript y respuestas JSON desde la misma aplicación.
- Es compatible con Windows y con C++17.

### Desventajas o consecuencias

- El postulante debe instalar y comprender un framework web C++.
- El mapa requiere JavaScript mínimo en el navegador.
- La interfaz se limitará a lo necesario para el MVP; no se añadirá un framework SPA.

---

## DT-004 — Sistema de gestión de base de datos

- **Fecha:** 2026-07-29
- **Estado:** Aceptada para el MVP

### Contexto o problema

El bot y el panel deben compartir una sola base de datos y un único modelo de pedido. La defensa se realizará localmente y debe poder iniciarse sin instalar un servidor adicional.

### Alternativas evaluadas

- **PostgreSQL:** ofrece mayor concurrencia y capacidades de servidor, pero exige instalación y configuración adicional.
- **MySQL o MariaDB:** son opciones conocidas de servidor, pero añaden el mismo costo operativo para el MVP local.
- **SQLite3:** almacena la base en un archivo local y no requiere un servicio independiente.

### Decisión adoptada

Utilizar **SQLite3** y encapsular el acceso mediante repositorios C++ con sentencias preparadas.

### Motivo

SQLite reduce los pasos de instalación y permite que bot y panel trabajen sobre el mismo archivo. Su capacidad es suficiente para uno o dos repartidores y el volumen esperado de una demostración.

### Ventajas

- No requiere instalar ni administrar un servidor de base de datos.
- Facilita una ejecución reproducible y copias de seguridad locales.
- Permite escribir consultas SQL explícitas y defendibles.
- Soporta transacciones para proteger cambios de estado y stock.

### Desventajas o consecuencias

- La concurrencia de escritura es menor que en PostgreSQL.
- No se considera apropiada para múltiples servidores escribiendo sobre el mismo archivo.
- Se habilitarán claves foráneas, modo WAL y un tiempo de espera de bloqueo.
- La confirmación del pedido y el descuento de stock se ejecutarán en una transacción atómica para impedir stock negativo.

---

## DT-005 — Integración entre bot y panel

- **Fecha:** 2026-07-29
- **Estado:** Aceptada

### Contexto o problema

Las dos partes obligatorias deben reflejar los mismos clientes, menús, pedidos, pagos, estados, asignaciones y ubicaciones. Duplicar reglas o usar bases separadas produciría inconsistencias.

### Alternativas evaluadas

- **Dos servicios con bases separadas:** aumenta el aislamiento, pero obliga a sincronizar información y contradice la base única requerida.
- **Dos procesos comunicados por una API REST:** permite despliegues independientes, pero añade red, autenticación interna y coordinación.
- **Monolito modular en un proceso:** bot y panel comparten servicios, repositorios, modelo de estados y base de datos.

### Decisión adoptada

Construir un **monolito modular** en un solo proceso: Drogon ejecutará el servidor web y el long polling del bot se ejecutará en un hilo de trabajo. Ambos utilizarán la misma capa de aplicación y SQLite.

### Motivo

Esta estructura satisface la integración obligatoria con menos componentes operativos y mantiene una única implementación de cada regla de negocio.

### Ventajas

- Los cambios del panel y del bot consultan la misma fuente de verdad.
- Evita duplicar validaciones de stock, pago, asignación y estados.
- Simplifica el inicio local y la demostración del flujo completo.
- Permite separar el código por módulos sin desplegar microservicios.

### Desventajas o consecuencias

- Una falla del proceso puede afectar simultáneamente al bot y al panel.
- El hilo del bot debe detenerse de forma ordenada al cerrar la aplicación.
- Las operaciones críticas usarán transacciones; no se compartirá estado mutable sin sincronización.
- Las dependencias externas permanecerán detrás de adaptadores para permitir cambios posteriores.

---

## DT-006 — Configuración sensible y variables de entorno

- **Fecha:** 2026-07-29
- **Estado:** Aceptada

### Contexto o problema

El token de Telegram, las credenciales administrativas y la clave de sesión no deben aparecer en el código, el historial Git, los mensajes de error ni los registros.

### Alternativas evaluadas

- **Valores escritos en el código:** es sencillo, pero expone secretos y obliga a recompilar.
- **Archivo de configuración versionado:** facilita el inicio, pero puede publicar credenciales accidentalmente.
- **Variables de entorno:** separan la configuración del código y permiten valores distintos por entorno.
- **Gestor externo de secretos:** ofrece mayor control, pero excede el alcance del MVP local.

### Decisión adoptada

Leer la configuración mediante variables de entorno con `std::getenv`. Versionar únicamente `.env.example` con nombres y ejemplos no sensibles, mantener `.env` en `.gitignore` y detener el inicio si falta una variable obligatoria.

### Motivo

La alternativa evita versionar secretos sin incorporar infraestructura adicional.

### Ventajas

- Los secretos no forman parte del código ni de los commits.
- Cada entorno puede usar valores diferentes.
- La configuración requerida queda documentada en `.env.example`.
- La aplicación puede validar la configuración antes de aceptar pedidos.

### Desventajas o consecuencias

- El usuario debe definir las variables antes de iniciar la aplicación.
- El programa no imprimirá valores secretos al informar errores.
- Como mínimo se definirán `BOT_TOKEN`, `ADMIN_USERNAME`, `ADMIN_PASSWORD_HASH`, `SESSION_SECRET`, `DATABASE_PATH`, `APP_HOST` y `APP_PORT`.
- Las credenciales reales y los archivos locales de entorno nunca se subirán al repositorio.

## Referencias técnicas

- [Drogon](https://github.com/drogonframework/drogon)
- [Instalación de Drogon](https://github.com/drogonframework/drogon/wiki/ENG-02-Installation)
- [tgbot-cpp](https://github.com/reo7sp/tgbot-cpp)
- [API de tgbot-cpp](https://reo7sp.github.io/tgbot-cpp/class_tg_bot_1_1_api.html)
- [Telegram Bot API](https://core.telegram.org/bots/api)
- [SQLite](https://www.sqlite.org/docs.html)
- [Transacciones de SQLite](https://www.sqlite.org/lang_transaction.html)
- [CMake](https://cmake.org/documentation/)
- [vcpkg](https://learn.microsoft.com/vcpkg/)
