


# Push Swap (42cursus)

#### 📌 Descripción


Push Swap es un proyecto del programa 42 que consiste en ordenar una pila de números enteros utilizando un conjunto limitado de operaciones y una pila auxiliar. El objetivo principal es lograr la menor cantidad posible de movimientos, lo que lo convierte en un problema de optimización algorítmica.

Este repositorio contiene una implementación completa del proyecto Push Swap, desarrollada en lenguaje C, haciendo uso del conocido algoritmo turco, una estrategia heurística diseñada para alcanzar un equilibrio entre rendimiento y eficiencia en número de operaciones.

#### 🚀 Objetivos del proyecto

Manipular estructuras de datos (listas enlazadas).

Desarrollar un algoritmo de ordenación personalizado.

Optimizar el número de instrucciones (movimientos).

Cumplir con las restricciones del conjunto de operaciones permitido.

Aplicar el algoritmo turco de manera efectiva para obtener buenos resultados en sets de prueba medianos y grandes.

#### 🧠 ¿Qué es el algoritmo turco?

El algoritmo turco es una estrategia heurística para ordenar eficientemente utilizando un enfoque similar a la técnica de chunking. Se divide la pila en fragmentos (chunks) de valores, moviendo inteligentemente los elementos entre las pilas A y B para minimizar los movimientos de rotación, empuje y retorno. Su implementación balancea simplicidad con eficiencia, siendo ideal para casos donde el número de elementos es mediano o grande (100–500 números).

Principios básicos:
- Se mandan todos los números menos tres a la pila b y se ordenan los trés números que quedan en la pila a.
- En cada iteración vamos a calcular:<br>
    1 - El tárget de cada número, que sería el número sobre el que debe colocarse (el mayor de los menores del número analizado).<br>
    2 - Tras conocer el target de cada número vamos a calcular su "precio" que será el numero de movimientos que necesitamos para colocar el mismo y su target al principio de la pila.<br>
    3 - Una vez que calculamos el precio de todos vamos a hacer el movimiento del más "barato" y volveremos a recalcular targets y precios<br>

Cómo Usarlo
Compilación:

```c
make
```
Ejecución:

```c
./push_swap <número1> <número2> <número3> ... <br>
```

Ejemplo:

```c
./push_swap 5 34 6 -7 233
```

Salida esperada:

El programa imprimirá en stdout la secuencia de movimientos necesaria para ordenar la pila de la manera más eficiente posible.
Si la entrada no es válida (valores no numéricos, duplicados, etc.), imprimirá "Error" en la salida de error estándar.

Operaciones Permitidas
El programa solo puede utilizar las siguientes operaciones sobre las pilas:

`sa` / `sb` / `ss` – Intercambia los dos primeros elementos de una pila. <br>
`pa` / `pb` – Mueve el primer elemento de una pila a la otra. <br>
`ra` / `rb` / `rr` – Rota la pila hacia arriba. <br>
`rra` / `rrb` / `rrr` – Rota la pila hacia abajo. <br>
