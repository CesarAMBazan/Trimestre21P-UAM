/*
 * Examen 3A - Mejia Bazan Cesar Arturo 2182005565
 * Cadenas especiales de dígitos
 */

#include <stdio.h>
#include <algorithm>
int n;
int cadena[20];
long long contador;
void solve(int i)
{
    if (i == n)
    {
        //! Debug, imprimir cadenas
        // for (int o = 0; o < n; ++o)
        // {
        //     printf("%d", cadena[o]);
        // }
        contador++;
    }
    else
    {
        int pair_check = 0;
        for (int c = 0; c <= 9; c++)
        {
            cadena[i] = c;
            if (i < 2 || ((cadena[i - 2] * 10) + cadena[i - 1]) <= ((cadena[i - 1] * 10) + cadena[i]))
                solve(i + 1);
        }
    }
}
int main()
{
    scanf("%d", &n);
    solve(0);
    printf("%lld", contador);
    return 0;
}