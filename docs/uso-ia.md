# Registro de uso de asistentes de IA

## Herramientas utilizadas

- ChatGPT, de OpenAI: utilizado como apoyo para interpretar el enunciado, revisar la estructura de issues y Pull Requests, orientar el uso de Git y GitHub, y proponer borradores de documentación en Markdown.

## Registro cronológico

| Fecha | Issue / PR | Para qué se usó | Qué devolvió | Cómo se verificó | Qué se modificó |
|---|---|---|---|---|---|
| 2026-07-29 | Issue #1 / PR #2 / PR #17 | Revisar los requisitos del modelo de ramas y apoyar la elaboración de `CONTRIBUTING.md`. | Una propuesta de flujo con `main`, `develop` y ramas de trabajo asociadas a issues. | Se comparó la propuesta con el Bloque A del enunciado y se verificó el flujo resultante en GitHub. | Se adaptó el flujo al carácter individual del examen y no se aplicaron fork, repositorio `upstream` ni revisión externa. |
| 2026-07-29 | Issue #3 / PR #4 / PR #17 | Apoyar la definición de la plantilla estándar para Pull Requests. | Una estructura con las secciones qué cambia, por qué se realiza, cómo probarlo, issues relacionados, tipo de cambio, checklist y evidencia. | Se contrastó con los requisitos obligatorios del Pull Request indicados en el enunciado. | Se ajustó la plantilla al proyecto individual y se estableció el uso de `Closes #NN` para vincular y cerrar issues mediante el merge correspondiente. |
| 2026-07-29 | Issues #1 y #3 / PR #17 | Orientar la configuración inicial de GitHub Projects y la protección de ramas. | Una propuesta de flujo entre los estados `Todo`, `In Progress` y `Done`, junto con reglas para evitar cambios directos. | Se comprobó en GitHub que los issues fueran cerrados por el PR y que las tarjetas reflejaran el movimiento real. | Se desactivó la automatización que cerraba issues al moverlos a `Done` y se dejó que el cierre ocurriera mediante el Pull Request. |
| 2026-07-29 | Issue #5 | Revisar la estructura del issue y preparar el contenido inicial de `docs/uso-ia.md`. | Una plantilla con herramientas utilizadas, tabla cronológica, sección sobre uso no realizado y declaración de comprensión. | Se comparó cada sección y columna con el formato exigido expresamente por el enunciado. | Se reemplazaron los ejemplos genéricos por actividades reales realizadas en este repositorio. |
| 2026-07-29 | Issue #5 / PR #18 | Preparar y revisar el Pull Request del registro inicial de uso de IA. | Una propuesta de título, descripción, pasos de comprobación y checklist para el PR. | Se revisó el contenido según el alcance documental del issue y se comprobó su visualización en GitHub. | Se dejaron sin marcar las casillas correspondientes a código y pruebas porque no aplican a un cambio exclusivamente documental. También se eliminaron caracteres de escape que impedían que GitHub interpretara correctamente el formato Markdown. |
| 2026-07-29 | Issue #6 / PR #19 | Revisar la declaración de autoría, comprobar sus criterios y preparar el Pull Request. | Una verificación de cobertura del documento y una propuesta de PR vinculada al issue. | Se contrastó el archivo con cada criterio de aceptación del Issue #6 y se comprobó que la rama solo estuviera un commit por delante de `develop`. | Se conservaron el nombre y la asignatura reales, se limitó el cambio al alcance documental y se abrió el PR en borrador contra `develop`, sin fusionarlo. |

## Dónde NO se usó IA

Hasta la creación de este documento todavía no se ha implementado código funcional del bot de Telegram, del panel de administración ni del modelo de base de datos. Por tanto, no existe código de esos componentes que pueda atribuirse al uso de IA.

La creación de la cuenta y del repositorio, la ejecución de los comandos en Git Bash, las operaciones realizadas en GitHub y la comprobación visual de sus resultados fueron realizadas manualmente por el postulante.

## Declaración

Comprendo todo el código de este repositorio y puedo explicarlo, justificarlo y modificarlo sin asistencia.

También comprendo la documentación y la configuración realizadas hasta la fecha, y asumo la responsabilidad de verificar y adaptar cualquier propuesta obtenida mediante asistentes de IA antes de incorporarla al proyecto.