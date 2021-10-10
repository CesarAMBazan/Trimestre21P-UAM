//* Unicamente recurrencia

#include <stdio.h>

int contador;

int f(int n, int k)
{
    contador++;
    if (k == 0 || k == n)
        return 1;
    else
        return f(n - 1, k - 1) + f(n - 1, k);
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int valor = f(n, k);
    printf("%d %d", valor, contador);
    return 0;
}