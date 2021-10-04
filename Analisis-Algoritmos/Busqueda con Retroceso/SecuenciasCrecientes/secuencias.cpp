/*
 * Secuencias crecientes
 * Elaborado por Mejia Bazan Cesar Arturo 2182005565
 */

#include <stdio.h>

int contador, n, k;
int secuencias[15];
void solve(int i)
{
    if (i == n)
    {
        //! DEBUG: Imprimir secuencias
        for (int i = 0; i < n; i++)
            printf("%d ", secuencias[i]);
        printf("\n");
        contador++;
    }
    else
    {
        for (int c = i + 1; c <= k; ++c)
        {
            secuencias[i] = c;
            if (i == 0 || (secuencias[i] - secuencias[i - 1]) >= 1)
                solve(i + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    solve(0);
    printf("%d", contador);
    return 0;
}