/*
 * Permutaciones divisibles
 */

#include <stdio.h>
#include <algorithm>

int n, contador;
int arreglo[20];

void genera(int i)
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arreglo[i]);
        printf("\n");
    }
    else
    {
        for (int j = i; j < n; j++)
        {
            std::swap(arreglo[i], arreglo[j]);
            if (i == 0 || (arreglo[i] + arreglo[i - 1]) % (i + 1) == 0)
                genera(i + 1);
            std::swap(arreglo[i], arreglo[j]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        arreglo[i] = i + 1;
    genera(0);
    return 0;
}