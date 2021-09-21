/*Programa elaborado por Mejia Bazan Cesar Arturo 2182005565*/

/*Cadena con restricciones sin sentido
* Supongamos el caso más pequelo N(1) = 9 Cadenas [0,1,2,3,5,6,7,8,9]
* el siguiente caso sera 
* N(2) = [01] + {1,2,3,4,6,7,8,9}*N(1) + [5]*[{6,7,8,9}]
* y el siguiente caso sera
* N(3) = [01]*N(1) + {1,2,3,4,6,7,8,9}*N(2) + [5]*[{6,7,8,9}]*N[1]
* y el siguiente caso sera
* N(4) = [01]*N(2) + {1,2,3,4,6,7,8,9}*N(3) + ([56]+[57]+[58]+[59])*N[2]
* entonces se llega a la conclusión de que
* N(n) = [01]*N(n-2) + 8*N(n-1) + [{6,7,8,9}]*N(n-2)
* es decir
* N(n) = 5*N(n-2) + 8*N(n-1)
*/

#include <stdio.h>

long operaciones(int n);

int main(){
    int n;
    scanf("%d", &n);
    printf("%ld", operaciones(n));
}

long operaciones(int n){
    if(n == 0) return 1; //Caso de [01] o 5
    else if (n == 1) return 9; //Caso más pequeño
    else return 8*operaciones(n-1) + 5*operaciones(n-2);
}