/*Creado por Mejia Bazan Cesar Arturo 2182005565*/
#include <stdio.h>

int producto(int a, int b);
int contador = 0;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    producto(a,b);
    printf("%d", contador);
    return 0;
}

int producto(int a,  int b){
    if(a <= 0) return 0;
    else {
        if( a % 2) {
            contador += 3;
            return 2*producto(a/2, b) + b;
        } else {
            contador += 2;
            return 2*producto(a/2,b);
        }
    }
}