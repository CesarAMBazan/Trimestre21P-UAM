# Tarea 6A

# El ratón que salta chueco

### Descripción

Un ratón tiene lastimada su patita izquierda pero debe llegar a su madriguera lo más rápido posible antes de que el gato aparezca. La casa en la que viven los ratones y el gato es de dimensiones $M \times N$, el ratón se encuentra actualmente en la posición $(R_i,R_j)$ y la madriguera está en la posición $(H_i, H_j)$. Como al ratón le cuesta trabajo caminar, sólo puede ejecutar cierto tipo de salto que lo desplaza simultáneamente $F$ unidades al frente y $D$ unidades a la derecha. El ratón debe evitar chocar contra las paredes de la casa pero puede orientarse en cualquiera de las cuatro direcciones cardinales antes de dar cada salto. Escribe un programa que calcule cuál es la cantidad mínima de saltos que el ratón necesita para llegar a la madriguera.

### Entrada

Los ocho enteros $M, N, F, D, R_i, R_j, H_i, H_j$. Puedes suponer que $1 \leq M, N, F, D \leq 1000$, $0 \leq R_i, H_i < M$ y $0 \leq R_j, H_j < N$

### Salida

Un entero que sea el mínimo número de saltos que necesita dar el ratón para llegar a la madriguera o el entero -1 si no existe solución.
