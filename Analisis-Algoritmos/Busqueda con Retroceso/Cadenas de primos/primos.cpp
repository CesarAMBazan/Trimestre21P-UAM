/*
 * Cadenas de primos
 * Elaborado por Mejia Bazan Cesar Arturo
 */

#include <stdio.h>

int n;
int cadena[15];
int contador;

bool prime(int p)
{
    if (p < 2)
        return false;
    int prime = 1;
    for (int loop = 2; loop < p; loop++)
        if ((p % loop) == 0)
            prime = 0;
    if (prime == 1)
        return true;
    else
        return false;
}
void solve(int i)
{
    if (i == n)
    {
        contador++;
    }
    else
    {
        for (int c = 1; c <= 9; ++c)
        {
            cadena[i] = c;
            if (i == 0 || prime(cadena[i - 1] + cadena[i]))
                solve(i + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    solve(0);
    printf("%d", contador);
    return 0;
}