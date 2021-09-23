/*
 * Rectangulo de domino (lento): No evita el trabajo repetido
 */

#include <stdio.h>
int n;

long long resuelve(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        return resuelve(n - 1) + resuelve(n - 2);
    }
}
int main()
{
    scanf("%d", &n);
    printf("%lld", resuelve(n));
    return 0;
}