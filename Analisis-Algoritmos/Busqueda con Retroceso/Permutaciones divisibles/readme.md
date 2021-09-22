# Permutaciones divisibles

### Descripción

Escribe un programa que encuentre todas las permutaciones <!-- $A_1,A_2,...,A_N$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=A_1%2CA_2%2C...%2CA_N"> del conjunto de simbolos <!-- $1,2,...,N$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=1%2C2%2C...%2CN"> tales que <!-- $A_{i-1}+A_i$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=A_%7Bi-1%7D%2BA_i"> sea divisible entre <!-- $i$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=i"> para toda <!-- $1<i<=N$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=1%3Ci%3C%3DN">. Por ejemplo, para <!-- $N=3$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=N%3D3"> la única permutación de <!-- $1,2,3$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=1%2C2%2C3"> que cumple con estas condiciones es <!-- $(3,1,2)$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=(3%2C1%2C2)"> puesto que <!-- $3+1$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=3%2B1"> es divisible entre <!-- $2$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=2"> y <!-- $1+2$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=1%2B2"> es divisible entre <!-- $3$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=3">.

### Entrada

Un entero <!-- $N$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=N">. Puedes suponer que <!-- $2<=N<=20$ --> <img style="transform: translateY(0.1em); background: white;" src="https://render.githubusercontent.com/render/math?math=2%3C%3DN%3C%3D20">.

### Salida

Las permutaciones que cumplan la condición, una por linea y con sus elementos separados por un espacio.

### Creditos

Elaborado por Mejia Bazan Cesar Arturo 2182005565

22 de Septiembre del 2021
