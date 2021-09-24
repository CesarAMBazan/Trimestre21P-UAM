/*
 * Tarea 4: Una recurrencia sencilla
 * Elaborado por Mejia Bazan César Arturo 2182005565
 */

#include <stdio.h>

int n;
bool calculado[30 + 1][30 + 1];
unsigned long long memoria[30 + 1][30 + 1];

unsigned long long f(int n, int k)
{
    if (calculado[n][k] == false)
    {
        if (n == 0)
            memoria[n][k] = k;
        else
            memoria[n][k] = f(n - 1, k) + 2 * f(n - k, 1 - k);
        calculado[n][k] = true;
    }
    return memoria[n][k];
}

int main()
{
    scanf("%d", &n);
    printf("%llu\n", f(n, 0));
    return 0;
}