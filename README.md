# ***G4 - TicTacToe***

Proyecto desarrollado en **C++**. El objetivo fue implementar un juego funcional de **Tres en Raya (Tic-Tac-Toe)** aplicando, en un mismo programa, los conceptos aprendidos durante el desarrollo de la asignatura.

## Descripción

G4-TicTacToe es una aplicación de consola que reúne tres modalidades de juego diferentes dentro de un único programa:

    - Modo **1 vs 1 (Mejor de 3)**.
    - Modo **Jugador contra la computadora**.
    - Modo **Ultimate Tic-Tac-Toe**,.

Además, el programa registra automáticamente los resultados de las partidas en un archivo de historial para conservar los resultados entre ejecuciones.

## Objetivos del proyecto

El propósito principal del proyecto fue integrar en un solo programa los conocimientos adquiridos durante el curso de Programación, tales como:

    - Uso de funciones.
    - Estructuras (`struct`).
    - Vectores (`vector`).
    - Manejo de archivos.
    - Modularización del código.
    - Uso de parámetros por referencia.
    - Condicionales.
    - Ciclos repetitivos.
    - Generación de números aleatorios.
    - Organización del programa mediante procedimientos.

Más que desarrollar únicamente un juego, el proyecto busca demostrar la aplicación conjunta de diferentes herramientas del lenguaje C++.

## Características

    - Menú principal interactivo.
    - Tres modos de juego diferentes.
    - Selección aleatoria del jugador inicial.
    - Sistema "Mejor de 3" para partidas entre jugadores.
    - Modo contra la computadora.
    - Implementación de Ultimate Tic-Tac-Toe.
    - Registro automático del historial de partidas.
    - Lectura del historial desde un archivo de texto.
    - Representación gráfica del tablero mediante caracteres ASCII.
    - Mensajes de victoria y empate.

## Tecnologías utilizadas

    - Lenguaje **C++**
    - Biblioteca estándar de C++

Librerías utilizadas:

    - `<iostream>`
    - `<vector>`
    - `<fstream>`
    - `<cstdlib>`
    - `<ctime>`
    - `<string>`

## Requisitos

El proyecto puede compilarse con cualquier compilador moderno compatible con C++.
No requiere instalación de librerías adicionales, ya que únicamente utiliza bibliotecas pertenecientes a la biblioteca estándar de C++.

## Ejecución

    1. Abrir el proyecto.
    2. Compilar el código.
    3. Ejecutar el programa.
    4. Seleccionar el modo de juego desde el menú principal.

Si el archivo **historial.txt** no existe, el programa lo creará automáticamente cuando se registre la primera partida.

## Modos de juego

### 1. Mejor de 3

Dos jugadores compiten en varias rondas.

    - El primer jugador en obtener dos victorias gana la partida.
    - El turno inicial cambia entre rondas.
    - El resultado queda almacenado en el historial.

### 2. Ultimate Tic-Tac-Toe

Versión avanzada del Tres en Raya.

Características:

    - El tablero principal está formado por nueve tableros pequeños.
    - Cada movimiento determina el tablero donde deberá jugar el siguiente jugador.
    - Cuando un jugador gana un tablero pequeño, conquista esa posición del tablero principal.
    - El ganador será quien consiga tres tableros consecutivos en el tablero principal.

### 3️. Contra la computadora

Modo para un solo jugador.

Características:

    - La computadora realiza movimientos aleatorios.
    - Se juega una única partida.
    - El resultado queda almacenado en el historial.

## Historial de partidas

El programa guarda automáticamente cada partida en el archivo:

```
historial.txt
```

Cada registro contiene:

    - Modo de juego
    - Nombre de los jugadores
    - Cantidad de victorias obtenidas

Mientras el archivo exista, el historial podrá consultarse desde el menú principal.

## Funcionamiento del programa

El código se encuentra dividido en cuatro grandes secciones.

### 1. Estructuras y manejo de archivos

Se define la estructura `Jugador`, encargada de almacenar el nombres, el símbolo y el número de victorias.
También se implementan funciones para guardar y leer el historial de partidas utilizando archivos de texto.

### 2. Procedimientos auxiliares

Incluye funciones encargadas de:

    - Verificar si existe un ganador
    - Comprobar si el tablero está lleno
    - Imprimir el tablero
    - Mostrar arte ASCII para representar al ganador

### 3. Lógica del juego

Se implementan las reglas correspondientes a:

    - Partidas normales
    - Partidas contra la computadora
    - Ultimate Tic-Tac-Toe

También se controla:

    - Cambio de turnos
    - Validación de movimientos
    - Conteo de victorias
    - Detección de empates

### 4. Menú principal

El programa inicia mostrando un menú desde el cual el usuario puede acceder a cualquiera de los modos de juego o consultar el historial de partidas.

## Autores

**Grupo 4**
    
    -Francis Alcarraz
    -Josthin Moreira
    -Federico Proaño
    -Jorge Shuguli

## Concluciones

    1. El desarrollo de G4-TicTacToe permitió integrar en una sola aplicación diversos conceptos fundamentales de programación en C++, como el uso de funciones, estructuras, vectores, manejo de archivos, condicionales y ciclos. Esto demostró la importancia de combinar diferentes herramientas para construir un programa funcional y organizado.

    2. La implementación de varios modos de juego, representó un desafío que fortaleció las habilidades de análisis, planificación y resolución de problemas. Además, evidenció cómo una correcta modularización del código facilita el mantenimiento, la reutilización de funciones y la comprensión del programa.
    
    3. Finalmente, este proyecto permitió reforzar el trabajo colaborativo y la aplicación práctica de los conocimientos adquiridos durante el curso, que sienta asi una base sólida para el desarrollo de proyectos más complejos en el futuro y motivando la incorporación de nuevas funcionalidades y mejoras.
