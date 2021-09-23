# Evaluando una función algo rara

### Descripción

Escribe un programa que evalúe $f(x,y)$ definida como sigue:

- Si $y<=2, f(x,y)=x+y$
- Si $y>2, f(x,y) = x + f(x,y-1)+5*f(x,y-2)$

### Entrada

Un entero $N$ seguido de $N$ parejas de enteros $x,y$. Puedes suponer que $0<=N<=5$ y que $0<=x,y<=10^4$.

### Salida

El valor de $f(x,y)$ para cada una de las $N$ parejas. Como el valor de $f(x,y)$ puede ser muy grande, deberás imprimirlo en módulo $2^{64}$

### Creditos

Elaborado por Mejia Bazan Cesar Arturo 2182005565

23 de Septiembre de 2021
