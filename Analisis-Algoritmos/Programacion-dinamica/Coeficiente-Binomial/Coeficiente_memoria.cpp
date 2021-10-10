//* Recurrencia con memorización

#include <stdio.h>

struct resultado
{
    int valor;
    int llamadas;
};
bool calculado[30 + 1][30 + 1];
resultado memoria[30 + 1][30 + 1];

resultado f(int n, int k)
{
    if (calculado[n][k] == false)
    {
        if (k == 0 || k == n)
            memoria[n][k] = {1, 1};
        else
        {
            resultado r1 = f(n - 1, k - 1);
            resultado r2 = f(n - 1, k);
            memoria[n][k] = {r1.valor + r2.valor, r1.llamadas + r2.llamadas + 1};
        }
        calculado[n][k] == true;
    }
    return memoria[n][k];
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    resultado r = f(n, k);
    printf("%d %d", r.valor, r.llamadas);
    return 0;
}