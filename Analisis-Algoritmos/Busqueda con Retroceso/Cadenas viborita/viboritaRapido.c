/*
 * Cadenas viborita
 * Estrategia 1 (Rapido): Generaremos solo validas y filtraremos al final
 */

#include <stdio.h>
#include <stdlib.h>

int n;
char cadena[25 + 1] = {};
long long contador;

//* Llenar la cadena de la posición i en adelante
void genera(int i)
{
    if (i == n)
    {
        if (cadena[0] != cadena[n - 1])
            return;
        contador++;
    }
    else
    {
        for (char c = '0'; c <= '9'; ++c)
        {
            cadena[i] = c;
            if (i == 0 || abs(cadena[i - 1] - cadena[i]) == 1)
                genera(i + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    genera(0);
    printf("%lld", contador);
    return 0;
}