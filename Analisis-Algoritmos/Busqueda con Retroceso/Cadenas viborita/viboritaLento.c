/*
 * Cadenas viborita
 * Estrategia 1 (Lenta): Generaremos todo y luego filtramos
 */

#include <stdio.h>
#include <stdlib.h>

int n;
char cadena[25 + 1] = {};
int contador;

//* Llenar la cadena de la posición i en adelante
void genera(int i)
{
    if (i == n)
    {
        if (cadena[0] != cadena[n - 1])
            return;
        for (int i = 1; i < n; ++i)
            if (abs(cadena[i] - cadena[i - 1]) != 1)
                return;

        printf("%s\n", cadena);
        contador++;
    }
    else
    {
        for (char c = '0'; c <= '9'; ++c)
        {
            cadena[i] = c;
            genera(i + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    genera(0);
    printf("Contador: %d", contador);
    return 0;
}