/*
 * Agente viajero
 */

#include <stdio.h>
#include <algorithm>
#include <limits.h>

int n, mejor_costo = INT_MAX;
int permutacion[15];
int matriz[15][15];

void genera(int i, int c)
{
    if (i == n)
    {
        mejor_costo = std::min(mejor_costo, c);
    }
    else if (c < mejor_costo)
    {
        for (int j = i; j < n; j++)
        {
            std::swap(permutacion[i], permutacion[j]);
            genera(i + 1, c + (i == 0 ? 0 : matriz[permutacion[i - 1]][permutacion[i]]));
            std::swap(permutacion[i], permutacion[j]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        permutacion[i] = i;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matriz[i][j]);
    genera(0, 0);
    printf("%d\n", mejor_costo);
    return 0;
}
