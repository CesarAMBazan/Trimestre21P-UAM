/*
 * Una función algo rara
 */

#include <stdio.h>

int n;

bool calculado[10000 + 1];
unsigned long long memoria[10000 + 1];

unsigned long long f(int x, int y)
{
    if (calculado[y] == false)
    {
        if (y <= 2)
        {
            memoria[y] = x + y;
        }
        else
        {
            memoria[y] = x + f(x, y - 1) + 5 * f(x, y - 2);
        }
        calculado[y] = true;
    }
    return memoria[y];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%llu\n", f(x, y));
        for (int i = 0; i < 10000; i++)
        {
            calculado[i] = false;
            memoria[i] = 0;
        }
    }
    return 0;
}