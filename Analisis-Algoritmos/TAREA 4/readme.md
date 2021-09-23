# Una recurrencia sencilla

### Descripción

Dada la siguiente recurrencia $f(n,k):$

- Si $n=0$ entonces $f(n,k) = k$
- Si $n>0$ entonces $f(n,k) = f(n-1,k)+2f(n-k,1-k)$

calcula el valor de $f(n,0)$.

### Entrada

Un entero $n$. Puedes suponer que $0<=n<=30$.

### Salida

un entero que sea el valor de $f(n,0)$ módulo $2^{64}$

### Creditos

Elaborado por Mejia Bazan César Arturo 2182005565

23 de Septiembre de 2021
