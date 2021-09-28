/*
 * Secuencias crecientes
 * Elaborado por Mejia Bazan Cesar Arturo 2182005565
 */

#include <stdio.h>
#include <algorithm>

int contador, n, k;
int secuencias[15];
int choices[25];
void solve(int i)
{
    if (n >= k)
    {
        if (n == k)
            contador = 1;
        return;
    }
    else
    {
        if (i == n)
        {
            //! DEBUG: Imprimir secuencias
            // for (int i = 0; i < n; i++)
            //     printf("%d ", secuencias[i]);
            // printf("\n");
            contador++;
        }
        else
        {
            for (int c = 0; c < k; ++c)
            {
                std::swap(secuencias[i], choices[c]);
                if (i == 0 || (secuencias[i] - secuencias[i - 1]) >= 1)
                    solve(i + 1);
                std::swap(secuencias[i], choices[c]);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        secuencias[i] = i + 1;
        choices[i] = i + 1;
    }
    solve(0);
    printf("%d", contador);
    return 0;
}