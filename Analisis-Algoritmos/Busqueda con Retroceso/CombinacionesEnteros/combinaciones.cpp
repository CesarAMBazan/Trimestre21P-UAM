#include <stdio.h>
#include <algorithm>
int n, k;
int n_enteros[30];
int contador = 1;
void genera(int i)
{
    if (i == n - (k - 1))
    {
        return;
        // printf("%d\t\t", contador);
        // for (int i = 0; i < n; i++)
        //     printf("%d ", n_enteros[i]);
        // printf("\n");
        // contador++;
    }
    else
    {
        int aux = k - 1;
        int aux2 = 0;
        int suma = n_enteros[i];
        genera(i + 1);
        for (int j = i + 1; j < n; j++)
        {
            while (aux != 0)
            {
                suma += n_enteros[j];
                aux--;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &n_enteros[i]);
    }
    genera(0);
    return 0;
}