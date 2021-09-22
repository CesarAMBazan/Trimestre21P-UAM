# Una recurrencia y la altura de su árbol recursivo

### Descripción

Dada la siguiente recurrencia <!-- $f(n)$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=f(n)">

- Si <!-- $n <= 5$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=n%20%3C%3D%205"> entonces <!-- $f(n) = 1$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=f(n)%20%3D%201">
- Si <!-- $n > 5$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=n%20%3E%205"> entonces <!-- $f(n-5)+f(\frac{3n}{4})$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=f(n-5)%2Bf(%5Cfrac%7B3n%7D%7B4%7D)">

Calcula el valor de <!-- $f(n)$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=f(n)"> y la altura máxima del árbol recursivo.

### Entrada

un entero <!-- $n$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=n">. Puedes suponer que <!-- $0<=n<=300$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=0%3C%3Dn%3C%3D300">.

### Salida

Dos enteros que correspondan con el valor de <!-- $f(n)$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=f(n)"> y con la altura del árbol recursivo, respectivamente.

### Creditos

Elaborado por Mejia Bazan Cesar Arturo 2182005565
