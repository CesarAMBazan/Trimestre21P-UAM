/*
 * ¡Repito! - Elaborado por Mejia Bazan Cesar Arturo
 */
#include <stdio.h>
//? Realizarlo primero con divide y venceras
int n, p, v, m;
int calificaciones[300];

int solve(int i, int p, int v)
{
    if (p == 0)
        return 0;
    else if (i >= m && v != 0)
        return solve(i + 1, p - 1, v) + solve(i - m, p, v - 1) + calificaciones[i];
    else if (i <= n)
        return solve(i + 1, p - 1, v) + solve(i + 1, p, v) + calificaciones[i];
    else
    {
        return 0;
    }
}
int main()
{
    scanf("%d %d %d %d", &n, &p, &v, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &calificaciones[i]);
    }
    printf("%d", solve(0, p, v));
    return 0;
}