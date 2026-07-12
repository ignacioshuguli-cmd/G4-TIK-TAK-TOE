## Nombre del juego

# ***G4-TicTacToe***

## Integrantes:

   -Federico Proanho
    -Francis Alcarraz
    -Josthin Moreira
    -Jorge Shuguli

## Descripción de la Lógica

El programa implementa el juego “Tres en Raya” utilizando una matriz de 3x3 almacenada mediante un **vector** bidimensional de tipo **char**. Cada posición de la matriz representa una casilla del tablero, inicialmente marcada con el carácter **'-'**, el cual indica que el espacio está vacío.

El funcionamiento principal del juego se basa en un bucle **do-while**, el cual mantiene la ejecución activa hasta que ocurra una de las siguientes condiciones:

   - Un jugador complete una línea ganadora.
    - El tablero se llene completamente, produciendo un empate.

La variable **turno** se utiliza para controlar qué jugador debe participar. Mediante la condición **turno % 2 == 0**, el programa determina cuándo juega el jugador **O**; en caso contrario, juega **X**.

Durante cada iteración del bucle:

   1. El jugador ingresa la fila y la columna donde desea colocar su símbolo.
    2. El programa verifica si el movimiento es válido mediante una estructura **if**, comprobando:
        - Que la fila y columna estén dentro del rango **0-2**;
        - Que la casilla seleccionada no esté ocupada.
    3. Si el movimiento es inválido, se muestra un mensaje de error y se utiliza **continue** para reiniciar el turno actual.
    4. Si el movimiento es válido, se coloca el símbolo correspondiente (**X** u **O**) dentro de la matriz.
    5. El tablero se vuelve a imprimir mostrando el estado actualizado del juego.

La condición del **do-while** contiene varias expresiones lógicas encargadas de detectar si existe una victoria. Estas condiciones revisan:

   - Las 3 filas,
    - Las 3 columnas,
    - La diagonal principal,
    - La diagonal secundaria.

Si alguna de estas conbinaciones contiene tres símbolos iguales y distintos de **'-'**, el juego finaliza.

Finalmente, una vez terminado el bucle, el programa utiliza estructuras **if**, **else if** y **else** para determinar el resultado final:

   - Mostrar el mensaje de victoria para **X**,
    - Mostrar el mensaje de victoria para **O**,
    - O declarar un empate mediante la función **empate()**.

## Uso de estructuras

### Control de turnos

Para determinar qué jugador participa en cada turno, se utiliza la estructura:

    if (turno % 2 == 0)

Donde:
- Si el turno es par, juega **O**.
- Si el turno es impar, juega **X**.

Esto permite alternar automáticamente entre ambos jugadores durante toda la partida.

### Validación de movimientos

El programa utiliza una condición **if** para comprobar si un movimiento es válido:

    if (i < 0 || i > 2 || j < 0 || j > 2 || matriz[i][j] != '-')

Esta estructura verifica:

- Que las coordenadas ingresadas estén dentro del tablero;
- Que la casilla elegida esté vacía.

Si alguna condición no se cumple:

- Se muestra un mensaje de error;
- Se utiliza **continue** para repetir el turno.

### Determinación del ganador

Al finalizar el bucle principal, el programa utiliza estructuras **if** y **else if** para determinar quién ganó:

    if (turno % 2 != 0)

o

    else if (turno % 2 == 0)

Dependiendo del valor del turno, se llama a:

- **ganarX()**;
- **ganarO()**;

### Detección de empate

El programa utiliza una estructura **else** para determinar cuándo no existe un ganador y el tablero está lleno:

    else
    {
        empate();
    }

Esto ocurre cuando se alcanza el turno 10 y ninguna condición de victoria se cumple.

### Uso de bucles

El programa utiliza principalmente un bucle **do-while** como estructura principal de repetición.

    do
    {
       ...
    } while (...);

Este bucle permite que el juego continúe ejecutándose hasta que exista una combinación ganadora o se alcance el límite máximo de turnos.

El uso de **do-while** es importante porque garantiza que el juego se ejecute al menos una vez antes de comprobar la condición de finalización.

### Uso de estructuras anidadas

Se emplea una estructura condicional anidada en la comprobación del resultado final:

    if (turno == 10)
    {
        if (condicion_de_victoria)
        {
            ...
        }
        else
        {
            empate();
        }
    }

Aquí, un **if** se encuentra dentro de otro **if** para diferenciar entre:

- Una victoria conseguida en el último turno;
- Un empate verdadero.

## Conclusiones

# Conclusiones

- Como conclusión, desarrollar este proyecto permitió aplicar conceptos fundamentales de programación en C++, especialmente el uso de estructuras condicionales, estructuras repetitivas y vectores bidimensionales para representar un tablero de juego.

- Al programar este juego, “Tres en Raya”, se logró comprender cómo controlar el flujo de un programa utilizando un bucle principal encargado de mantener la ejecución hasta que exista un ganador o un empate.

- Usar condicionees lógicas permitió validar movimientos, controlar turnos y detectar automáticamente combinaciones ganadoras en filas, columnas y diagonales.

- El proyecto ayudó a fortalecer la lógica de programación al organizar correctamente las reglas del juego y gestionar diferentes escenarios posibles durante la partida.

- Aunque el código puede optimizarse y simplificarse en algunos apartados, el programa cumple correctamente con la funcionalidad principal del juego y demuestra una aplicación práctica de los temas estudiados.

- Finalmente, el trabajo permitió adquirir una mejor comprensión sobre la importancia de estructurar adecuadamente un programa y mantener una lógica clara para facilitar futuras mejoras o ampliaciones.