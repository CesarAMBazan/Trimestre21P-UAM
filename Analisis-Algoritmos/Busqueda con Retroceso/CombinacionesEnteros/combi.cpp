#include <stdio.h>
#include <algorithm>
struct dato
{
    int val;
    int pos;
};
dato arr[30];

int n, k;

void genera(int i)
{
    if (i == k)
    {
        //! DEBUG: Imprimir secuencias
        // for (int i = 0; i < k; ++i)
        // {
        //     printf("%d ", arr[i].val);
        // }
        // printf("\n");
        int suma = 0;
        for (int i = 0; i < k; ++i)
        {
            suma += arr[i].val;
        }
        printf("%d\n", suma);
    }
    else
    {
        for (int j = i; j < n; ++j)
        {
            std::swap(arr[i], arr[j]);
            if (i == 0 || arr[i - 1].pos < arr[i].pos)
                genera(i + 1);
            std::swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
    }
    genera(0);
}