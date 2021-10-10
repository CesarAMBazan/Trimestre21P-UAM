# Transiciones en cadenas binarias

### Descripción

El número de transiciones de una cadena binaria $b_1, b_2, \dots, b_N$ es el npumero de parejas $b_i, b_{i + 1}$ tales que $b_i \not = b_{i + 1}$. Por ejemplo, en la cadena $001011$ existen tres transiciones: la cadena comienza con 0 y luego cambia a 1, luego cambia otra vez a 0 y luego cambia otra vez a 1, escribe un programa que sume el número de transiciones que ocurren en las $2^N$ cadenas binarias de longitud $N$ e imprima el valor de dicha suma.

### Entrada

Un entero $N$. Puedes suponer que $0 \leq N \leq 50$.

### Salida

Un entero que es la suma del número de transiciones que ocurren en las $2^N$ cadenas binarias de longitud $N$.
