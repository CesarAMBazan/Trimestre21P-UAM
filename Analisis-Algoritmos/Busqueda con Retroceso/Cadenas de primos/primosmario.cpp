#include <stdio.h>
#include <algorithm>
#include <math.h>
int arr[16];
int n, k;
int contador = 0;
bool es_primo(int n)
{
    if (n <= 1)
    {
        return false;
    }

    int tope = sqrt(n);
    for (int i = 2; i <= tope; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void genera(int i)
{
    if (i == n)
    {
        //   for(int i = 0; i < n; ++i){
        //      printf("%d ", arr[i]);
        //   }
        ++contador;
        //   printf("\n") ;
    }
    else
    {
        for (int j = 0; j <= 9; ++j)
        {
            arr[i] = j;
            if (i == 0 || es_primo((arr[i - 1] * 10) + arr[i]))
            {
                genera(i + 1);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    genera(0);
    printf("%d", contador);
}