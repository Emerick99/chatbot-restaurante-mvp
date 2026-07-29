# Registro de uso de asistentes de IA

## Herramientas utilizadas

- ChatGPT, de OpenAI: utilizado como apoyo para interpretar el enunciado, revisar la estructura de issues y Pull Requests, orientar el uso de Git y GitHub, y proponer borradores de documentación en Markdown.

- ChatGPT Codex y su conector de GitHub: utilizados con autorización del postulante para revisar el repositorio y ejecutar comentarios, asignaciones, ramas, cambios documentales, Pull Requests y fusiones hacia `develop`.

## Registro cronológico

| Fecha | Issue / PR | Para qué se usó | Qué devolvió | Cómo se verificó | Qué se modificó |
|---|---|---|---|---|---|
| 2026-07-29 | Issue #1 / PR #2 / PR #17 | Definir el flujo de ramas. | Una propuesta con `main`, `develop` y ramas por issue. | Se comparó con el Bloque A y se comprobó en GitHub. | Se adaptó al carácter individual del proyecto. |
| 2026-07-29 | Issue #3 / PR #4 / PR #17 | Preparar la plantilla de PR. | Una plantilla con descripción, prueba, issue, checklist y evidencia. | Se contrastó con el enunciado. | Se incorporó `Closes #NN` y se ajustó la checklist. |
| 2026-07-29 | Issues #1 y #3 / PR #17 | Orientar Projects y la protección de ramas. | Un flujo `Todo → In Progress → Done` y reglas de protección. | Se revisaron el tablero y los cierres en GitHub. | Se dejó el cierre de issues exclusivamente a los PR. |
| 2026-07-29 | Issue #5 | Crear el registro de IA. | La estructura de herramientas, tabla, exclusiones y declaración. | Se comparó con el formato obligatorio. | Se reemplazaron ejemplos por actividades reales. |
| 2026-07-29 | Issue #5 / PR #18 | Preparar y revisar el PR. | Título, descripción, prueba y checklist. | Se revisaron el alcance y el Markdown. | Se corrigió el formato y se marcaron solo casillas aplicables. |
| 2026-07-29 | Issue #6 / PR #19 | Revisar la declaración de autoría. | Verificación de criterios y propuesta de PR. | Se comparó con el Issue #6. | Se añadió el registro del PR y se mantuvieron los datos aportados por el postulante. |
| 2026-07-29 | Issue #7 / PR #20 | Documentar alcance y actores. | Objetivo, componentes, responsabilidades y límites del MVP. | Se comparó con el Issue #7. | El postulante pidió corregir una frase ambigua sobre repartidores y registrar solo cambios reales; se aplicó. |
| 2026-07-29 | Issue #8 / PR #21 | Redactar historias del cliente. | Doce historias con criterios verificables. | Se compararon con el Issue #8. | El postulante pidió declarar toda la ayuda de Codex, eliminar información ajena a esta columna y resumir el registro; se aplicaron esos cambios. |
| 2026-07-29 | Issue #9 / PR #22 | Redactar y revisar historias del repartidor. | Once historias y observaciones sobre requisitos omitidos. | Se contrastaron con el Issue #9, el Bloque D y los libros base. | El postulante hizo notar que debían incorporarse los requisitos exactos; se precisaron mensaje completo, `Location`, acuse, reasignación, intervalo, pérdida de señal, evidencia y notificaciones. |
| 2026-07-29 | Issue #10 / PR #23 | Redactar historias del administrador. | Doce historias con criterios verificables. | Se contrastaron con el Issue #10, el Bloque E y los libros base. | Se añadieron seguridad, CRUD, stock concurrente, tablero, pago, reparto, mapa, ficha de cliente y tres reportes. |
| 2026-07-29 | Issue #11 / PR #24 | Registrar decisiones técnicas iniciales. | Seis decisiones con alternativas y consecuencias. | Se contrastaron con el Issue #11, el enunciado y la documentación oficial. | El postulante indicó que conoce C++ y no podría defender Python; se cambió la propuesta a C++17, Drogon, tgbot-cpp y SQLite3. |
| 2026-07-29 | Issue #12 / PR #25 | Crear el README inicial. | Un borrador con propósito, alcance, componentes, actores y enlaces. | Se contrastó con el Issue #12 y `docs/requisitos.md`. | Se resumió el alcance y se enlazó únicamente la documentación existente. |
| 2026-07-29 | Issue #13 / PR #26 | Diseñar la máquina de estados. | Un modelo con once estados, tabla y diagrama. | Se contrastó con el Issue #13, el enunciado y `docs/requisitos.md`. | Se definieron actores, condiciones, estados finales, cancelación, incidencias e idempotencia; la pérdida de señal quedó como indicador, no como estado. |
| 2026-07-29 | Issue #14 / PR #27 | Documentar el flujo conversacional. | Flujos del cliente y repartidor con decisiones y diagrama. | Se contrastó con el Issue #14, `docs/requisitos.md` y la máquina de estados. | Se separaron conversación y pedido; se precisaron ubicación nativa y en vivo, cancelación, reinicio, reasignación, errores e idempotencia. |
| 2026-07-29 | Issue #15 / PR #28 | Crear el diagrama de casos de uso. | Un diagrama con tres actores y veintiún casos de uso. | Se contrastó con el Issue #15 y `docs/requisitos.md`. | Se agruparon las funciones por actor, se marcó el límite del sistema y se añadieron reglas de acceso y trazabilidad. |
| 2026-07-29 | Issue #16 / PR #29 | Diseñar el modelo entidad-relación. | Dieciséis entidades con claves, cardinalidades y diagrama. | Se contrastó con el Issue #16, los requisitos y la máquina de estados. | Se normalizaron los perfiles, se conservaron precios históricos y se separaron asignaciones, rastros, pagos y eventos de entrega. |
| 2026-07-29 | Issue #30 / PR #31 | Declarar dependencias C++ con vcpkg. | Un manifiesto con Drogon, SQLite3 y tgbot-cpp. | Se contrastó con las decisiones técnicas y los paquetes oficiales. | El postulante detectó que el PR agrupaba demasiados archivos; se redujo a las dependencias y este registro, dejando cada componente para un issue separado. |
| 2026-07-29 | Issue #32 / PR #33 | Proteger secretos y artefactos locales. | Un `.gitignore` para entorno, compilación, SQLite, cargas y editores. | Se contrastó con el enunciado y se probaron los patrones con `git check-ignore`. | El postulante indicó mantener el avance granular; se limitó el PR a `.gitignore` y este registro. |
| 2026-07-29 | Issue #34 / PR #35 | Documentar variables de entorno. | Una plantilla con siete valores de ejemplo. | Se verificaron nombres únicos, valores ficticios y ausencia de secretos. | El postulante indicó mantener el avance granular; se limitó el PR a `.env.example` y este registro. |

## Alcance de la asistencia de IA

ChatGPT Codex ayudó a interpretar el enunciado, planificar tareas, revisar criterios y redactar o corregir documentación. Mediante el conector autorizado también ejecutó comentarios, asignaciones, ramas, cambios de archivos, Pull Requests y fusiones solicitadas hacia `develop`.

El postulante indicó las acciones, realizó observaciones y conserva la responsabilidad de revisar, comprender y defender el contenido.

## Dónde NO se usó IA

La cuenta de GitHub, el repositorio y los comandos iniciales de Git Bash fueron creados o ejecutados manualmente por el postulante.

Hasta esta actualización no se implementó código funcional del bot, del panel ni de la base de datos.

## Declaración

Comprendo todo el código de este repositorio y puedo explicarlo, justificarlo y modificarlo sin asistencia.

También comprendo la documentación y la configuración realizadas hasta la fecha, y asumo la responsabilidad de verificar y adaptar cualquier propuesta obtenida mediante asistentes de IA antes de incorporarla al proyecto.
