/*
 * Secuencias crecientes
 * Elaborado por Mejia Bazan Cesar Arturo 2182005565
 */

#include <stdio.h>
#include <algorithm>

/* ESP - ENG
 * contador = counter
 * secuencias = sequences
 * choices = choices
 */
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
            //! DEBUG: Print sequences
            // for (int i = 0; i < n; i++)
            //     printf("%d ", secuencias[i]);
            // printf("\n");
            contador++;
        }
        else
        {
            for (int c = 0; c < k; ++c)
            {
                // fill 'sequences' position with all of choices numbers
                std::swap(secuencias[i], choices[c]);
                // if the number in the current position is greater than the last one
                if (i == 0 || (secuencias[i] - secuencias[i - 1]) >= 1)
                    solve(i + 1);                     // go to the next position
                std::swap(secuencias[i], choices[c]); // reset
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        choices[i] = i + 1;
    }
    solve(0);
    printf("%d", contador);
    return 0;
}