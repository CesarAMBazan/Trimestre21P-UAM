//* Programación dinamica
//? ¿Cómo podemos modificar la implementación para usar programación dinámica?
/* 
 * - Antes de calcular f(n, k) sus dependencias ya deben estar calculadas.
 * - Quitar recursión
 */

#include <stdio.h>

struct resultado
{
    int valor;
    int llamadas;
};

resultado f(int n, int k)
{

    if (k == 0 || k == n)
        return {1, 1};
    else
    {
        resultado r1 = f(n - 1, k - 1);
        resultado r2 = f(n - 1, k);
        return {r1.valor + r2.valor, r1.llamadas + r2.llamadas + 1};
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    resultado r = f(n, k);
    printf("%d %d", r.valor, r.llamadas);
    return 0;
}