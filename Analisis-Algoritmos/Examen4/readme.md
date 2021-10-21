# La función cuerda

### Descripción

El dia de hoy te has topado con la no tan famosa función cuerda y necesitas un programa que sea capaz de evaluarla. La función cuerda toma dos enteros $x,a$ y se define como sigue:

- Si $x \leq 3$, entonces $f(x, a) = a * x$
- Si $x > 3$, entonces $f(x, a) = a * (f(x - 1, +a) + f(x - 1, -a) + f(x - 2, +a))$

### Entrada

Dos enteros $x,a$. Puedes suponer que $0 \leq x \leq 10^5$ y que $a$ vale $-1$ o $+1$

### Salida

Un entero que corresponda con la evaluación de la función cuerda si se usan enteros de 64 bits con signo.
