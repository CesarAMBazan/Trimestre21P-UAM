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

// resultado f(int n, int k)
// {

//     if (k == 0 || k == n)
//         return {1, 1};
//     else
//     {
//         resultado r1 = f(n - 1, k - 1);
//         resultado r2 = f(n - 1, k);
//         return {r1.valor + r2.valor, r1.llamadas + r2.llamadas + 1};
//     }
// }

int main()
{
    int n0, k0;
    scanf("%d %d", &n0, &k0);
    resultado memoria[n0 + 1][k0 + 1];
    for (int n = 0; n <= n0; n++)
    {
        for (int k = 0; k <= k0; k++)
        {
            if (k == 0 || k == n)
                memoria[n][k] = {1, 1};
            else
            {
                resultado r1 = memoria[n - 1][k - 1];
                resultado r2 = memoria[n - 1][k];
                memoria[n][k] = {r1.valor + r2.valor, r1.llamadas + r2.llamadas + 1};
            }
        }
    }
    printf("%d %d", memoria[n0][k0].valor, memoria[n0][k0].llamadas);
}