/*
 * Rectangulo de domino (rapido): Evita el trabajo repetido
 */

#include <stdio.h>
int n;
long long memoria[50 + 1];

long long resuelve(int n)
{
    if (memoria[n] == 0)
    {
        if (n == 1)
            memoria[n] = 1;
        else if (n == 2)
            memoria[n] = 2;
        else
        {
            memoria[n] = resuelve(n - 1) + resuelve(n - 2);
        }
    }
    return memoria[n];
}
int main()
{
    scanf("%d", &n);
    printf("%lld", resuelve(n));
    return 0;
}