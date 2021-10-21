#include <stdio.h>
bool calculado[100000 + 1][2];
long memoria[100000 + 1][2];

long f(int x, int a)
{
    int aux = a < 0 ? 0 : 1;
    if (calculado[x][aux] == false)
    {
        if (x <= 3)
            memoria[x][aux] = a * x;
        else
            memoria[x][aux] = a * (f(x - 1, +a) + f(x - 1, -a) + f(x - 2, +a));
        calculado[x][aux] = true;
    }
    return memoria[x][aux];
}
int main()
{
    int x, a;
    scanf("%d%d", &x, &a);
    printf("%ld", f(x, a));
    return 0;
}