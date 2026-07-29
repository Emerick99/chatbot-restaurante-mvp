# Registro de uso de asistentes de IA

## Herramientas utilizadas

- ChatGPT, de OpenAI: utilizado como apoyo para interpretar el enunciado, revisar la estructura de issues y Pull Requests, orientar el uso de Git y GitHub, y proponer borradores de documentación en Markdown.

- ChatGPT Codex Connector, de OpenAI: utilizado con autorización del postulante para inspeccionar el repositorio y ejecutar acciones en GitHub, incluidas la creación de comentarios, asignaciones, ramas, cambios documentales, Pull Requests y fusiones solicitadas.

## Registro cronológico

| Fecha | Issue / PR | Para qué se usó | Qué devolvió | Cómo se verificó | Qué se modificó |
|---|---|---|---|---|---|
| 2026-07-29 | Issue #1 / PR #2 / PR #17 | Revisar los requisitos del modelo de ramas y apoyar la elaboración de `CONTRIBUTING.md`. | Una propuesta de flujo con `main`, `develop` y ramas de trabajo asociadas a issues. | Se comparó la propuesta con el Bloque A del enunciado y se verificó el flujo resultante en GitHub. | Se adaptó el flujo al carácter individual del examen y no se aplicaron fork, repositorio `upstream` ni revisión externa. |
| 2026-07-29 | Issue #3 / PR #4 / PR #17 | Apoyar la definición de la plantilla estándar para Pull Requests. | Una estructura con las secciones qué cambia, por qué se realiza, cómo probarlo, issues relacionados, tipo de cambio, checklist y evidencia. | Se contrastó con los requisitos obligatorios del Pull Request indicados en el enunciado. | Se ajustó la plantilla al proyecto individual y se estableció el uso de `Closes #NN` para vincular y cerrar issues mediante el merge correspondiente. |
| 2026-07-29 | Issues #1 y #3 / PR #17 | Orientar la configuración inicial de GitHub Projects y la protección de ramas. | Una propuesta de flujo entre los estados `Todo`, `In Progress` y `Done`, junto con reglas para evitar cambios directos. | Se comprobó en GitHub que los issues fueran cerrados por el PR y que las tarjetas reflejaran el movimiento real. | Se desactivó la automatización que cerraba issues al moverlos a `Done` y se dejó que el cierre ocurriera mediante el Pull Request. |
| 2026-07-29 | Issue #5 | Revisar la estructura del issue y preparar el contenido inicial de `docs/uso-ia.md`. | Una plantilla con herramientas utilizadas, tabla cronológica, sección sobre uso no realizado y declaración de comprensión. | Se comparó cada sección y columna con el formato exigido expresamente por el enunciado. | Se reemplazaron los ejemplos genéricos por actividades reales realizadas en este repositorio. |
| 2026-07-29 | Issue #5 / PR #18 | Preparar y revisar el Pull Request del registro inicial de uso de IA. | Una propuesta de título, descripción, pasos de comprobación y checklist para el PR. | Se revisó el contenido según el alcance documental del issue y se comprobó su visualización en GitHub. | Se dejaron sin marcar las casillas correspondientes a código y pruebas porque no aplican a un cambio exclusivamente documental. También se eliminaron caracteres de escape que impedían que GitHub interpretara correctamente el formato Markdown. |
| 2026-07-29 | Issue #6 / PR #19 | Revisar la declaración de autoría, comprobar sus criterios y preparar el Pull Request. | Una verificación de cobertura del documento y una propuesta de PR vinculada al issue. | Se contrastó el archivo con cada criterio de aceptación del Issue #6 y se comprobó que la rama solo estuviera un commit por delante de `develop`. | Se conservaron el nombre y la asignatura reales, se limitó el cambio al alcance documental y se abrió el PR en borrador contra `develop`, sin fusionarlo. |
| 2026-07-29 | Issue #7 / PR #20 | Estructurar y revisar el alcance, los componentes y los actores del sistema para `docs/requisitos.md`. | Una propuesta organizada con objetivo, alcance del bot y panel, integración, responsabilidades y límites iniciales. | Se contrastó cada sección con los criterios de aceptación del Issue #7 y con las funciones obligatorias del bot y del panel. | El postulante observó que la frase «se aclaró el trabajo con uno o dos repartidores» podía interpretarse como una conversación con repartidores reales. Se reemplazó por una redacción que indica expresamente que no hubo entrevistas y que la definición se obtuvo del enunciado. |
| 2026-07-29 | Issue #8 / PR #21 | Redactar y revisar las historias de usuario del cliente y sus criterios de aceptación. | Una propuesta de doce historias sobre identificación, menú, carrito, stock, ubicación, pago, seguimiento, notificaciones y manejo del flujo. | Se contrastó cada historia con la lista obligatoria y los criterios de aceptación del Issue #8, comprobando que todas utilizaran el formato solicitado. | La propuesta queda pendiente de revisión del postulante. Hasta esta actualización no se solicitaron modificaciones al contenido de las historias de usuario; cuando exista una observación, se registrará aquí el cambio exacto realizado. |

## Alcance de la asistencia de IA

ChatGPT Codex ayudó a interpretar el enunciado, planificar el trabajo, revisar criterios de aceptación, redactar y corregir documentación, y preparar textos para issues y Pull Requests.

Mediante el conector de GitHub autorizado por el postulante, ChatGPT Codex también realizó lecturas del repositorio y ejecutó acciones solicitadas: publicación de comentarios, asignación de issues, creación de ramas, creación o actualización de archivos, apertura y actualización de Pull Requests, cambio de borrador a listo para revisión y fusiones mediante squash hacia `develop`.

El postulante indicó las acciones que debían realizarse, formuló observaciones sobre los resultados y conserva la responsabilidad de revisar, comprender, explicar y defender todo el contenido incorporado.

## Dónde NO se usó IA

Hasta esta actualización todavía no se ha implementado código funcional del bot de Telegram, del panel de administración ni del modelo de base de datos. Por tanto, aún no existe código funcional de esos componentes que pueda atribuirse al uso de IA.

La creación de la cuenta de GitHub, la creación inicial del repositorio y los comandos iniciales ejecutados en Git Bash fueron realizados manualmente por el postulante.

No se realizaron entrevistas, encuestas ni pruebas de usabilidad con clientes o repartidores reales. Los requisitos documentados hasta este punto provienen del enunciado del examen y de las observaciones realizadas por el postulante durante la revisión.

## Declaración

Comprendo todo el código de este repositorio y puedo explicarlo, justificarlo y modificarlo sin asistencia.

También comprendo la documentación y la configuración realizadas hasta la fecha, y asumo la responsabilidad de verificar y adaptar cualquier propuesta obtenida mediante asistentes de IA antes de incorporarla al proyecto.