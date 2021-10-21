#include <stdio.h>
bool calculado[100000 + 1][2] = {};
long long memoria[100000 + 1][2];
long long funcion(int x, int a)
{
    int doblea;
    if (a == -1)
    {
        doblea = 0;
    }
    else
    {
        doblea = 1;
    }
    if (calculado[x][doblea] == false)
    {
        if (x <= 3)
        {
            memoria[x][doblea] = x * a;
        }
        else if (x > 3)
        {
            memoria[x][doblea] = a * (funcion(x - 1, 1 * a) + funcion(x - 1, (-1) * a) + funcion(x - 2, 1 * (a)));
            calculado[x][doblea] = true;
        }
    }
    return memoria[x][doblea];
}
int main()
{
    int x, a;
    char signoa[2 + 1];
    scanf("%d %d", &x, &a);

    printf("%d", funcion(x, a));
    return 0;
}