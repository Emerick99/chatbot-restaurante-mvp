# Guía de contribución



## Propósito



Este documento define el modelo de ramas y las reglas de trabajo utilizadas

en el proyecto Chatbot de Pedidos para Restaurante.



Todo cambio debe comenzar con un issue, desarrollarse en una rama de trabajo

y ser integrado mediante un Pull Request.



## Modelo de ramas



### `main`



Es la rama estable y entregable del proyecto.

La rama `main` debe configurarse como rama protegida en GitHub.



- No se permiten commits directos.

- No se permiten force-push.

- Solo recibe cambios mediante Pull Requests.

- Debe contener únicamente versiones funcionales.



> Excepción de inicialización: el repositorio contiene un único commit raíz

> técnico y vacío, necesario para establecer las ramas base. Este commit no

> contiene código ni documentación. Después de su creación, ningún cambio

> puede realizarse directamente sobre `main`.



### `develop`



Es la rama de integración del proyecto.



- Recibe los cambios terminados desde las ramas de trabajo.

- No se permiten commits directos.

- Los cambios ingresan mediante Pull Requests.

- Sirve como base para crear nuevas ramas de trabajo.



Cuando `develop` contiene una versión estable y verificada, se abre un Pull

Request desde `develop` hacia `main`. No se realizan merges directos ni

commits manuales sobre `main`.



## Ramas de trabajo



Cada tarea debe desarrollarse en una rama propia creada desde `develop`.



La convención de nombres es:



```text

tipo/NN-descripcion-corta

```



Donde:



- `tipo` puede ser `feature`, `fix` o `docs`.

- `NN` es el número del issue asociado.

- `descripcion-corta` resume el objetivo de la tarea.



Ejemplos:



```text

feature/08-menu-cliente

fix/21-validacion-stock

docs/01-modelo-ramas

```



Las ramas de trabajo se eliminan después de fusionarse.



## Requisitos de los issues



Cada issue debe incluir:



- Un título accionable redactado como verbo más objeto.

- Una descripción con el contexto y el alcance del cambio.

- Criterios de aceptación verificables.

- Una label de tipo: `feat`, `bug` o `docs`.

- Una o ambas labels de parte, según el alcance: `parte:bot` y/o `parte:panel`.

- El milestone correspondiente.

- Una rama asociada con el formato `tipo/NN-descripcion-corta`.

- Un Pull Request vinculado mediante `Closes #NN`.



Los issues deben cerrarse automáticamente mediante el merge del Pull Request

asociado y nunca de forma manual.



## Flujo de trabajo por issue



Cada cambio debe seguir este orden:



1. Crear un issue antes de comenzar el trabajo.

2. Definir el contexto, alcance y criterios de aceptación.

3. Asignar labels y milestone.

4. Indicar la rama asociada.

5. Crear la rama desde `develop`.

6. Implementar únicamente el alcance del issue.

7. Crear commits con mensajes claros.

8. Abrir un Pull Request hacia `develop`.

9. Vincular el Pull Request mediante `Closes #NN`.

10. Revisar los criterios de aceptación.

11. Realizar el merge mediante squash.

12. Eliminar la rama de trabajo después del merge.



Los issues no deben cerrarse manualmente. Su cierre debe producirse mediante el merge del Pull Request asociado.



## Convención de commits



Los mensajes de los commits deben ser breves, claros y describir el cambio realizado.



Se utilizarán los siguientes prefijos:



- `feat:` para nuevas funcionalidades.

- `fix:` para correcciones de errores.

- `docs:` para cambios de documentación.

- `refactor:` para reorganizar código sin cambiar su comportamiento.

- `test:` para agregar o modificar pruebas.



Ejemplos:



```text

feat: agregar selección de platos

fix: corregir cálculo del total

docs: documentar modelo de ramas

refactor: separar lógica de pedidos

test: agregar pruebas de validación de stock

```



## Pull Requests y revisión



Todo cambio debe integrarse mediante un Pull Request.



Cada Pull Request debe incluir:



- Una explicación de qué cambia.

- La razón del cambio.

- Instrucciones para probarlo.

- Evidencia visual cuando corresponda.

- La referencia `Closes #NN` al issue asociado.

- Una checklist de revisión completada por el autor.



El tamaño de cada Pull Request debe mantenerse acotado, procurando no superar

aproximadamente quince archivos modificados.



Como el proyecto es individual, el autor también realiza la revisión del cambio antes del merge.



El merge se realiza mediante **Squash and merge**, utilizando un mensaje limpio y descriptivo.