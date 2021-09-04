/*Creado por Mejia Bazan Cesar Arturo 2182005565*/
#include <stdio.h>
#include <math.h>

int main(){
    int b, c, n, k, t, w, x, y, z;
    scanf("%d %d %d", &b, &c, &n);
    k= (log10(n)/log10(b));
    t= n;
    w= k;
    x= b;
    y= k-1;
    z= c;
    printf("%d %d %d %d %d", t, w, x, y, z);
    return 0;
}