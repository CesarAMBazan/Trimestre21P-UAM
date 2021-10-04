/*
 * Programa realizado por Mejia Bazan Cesar Arturo
 */
#include <stdio.h>
#include <algorithm>

int n, k;
int elemento[30];
int posicion[30];

void sumas(int i)
{
    if (i == k)
    {
        //! DEBUG: Imprimir secuencias
        // for (int i = 0; i < k; ++i)
        // {
        //     printf("%d ", posicion[i]);
        // }
        // printf("\n");
        int suma = 0;
        for (int j = 0; j < k; j++)
        {
            suma += elemento[posicion[j]];
        }
        printf("%d\n", suma);
    }
    else
    {
        for (int c = i; c < n; c++)
        {
            std::swap(posicion[i], posicion[c]);
            if (i == 0 || posicion[i - 1] < posicion[i])
                sumas(i + 1);
            std::swap(posicion[i], posicion[c]);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elemento[i]);
        posicion[i] = i;
    }
    sumas(0);
    return 0;
}