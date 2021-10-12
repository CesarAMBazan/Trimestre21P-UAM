/*
 * ¡Repito! - Elaborado por Mejia Bazan Cesar Arturo
 */
#include <stdio.h>
#include <algorithm>

//? Realizarlo primero con divide y venceras
int n, p, v, m;
int calificaciones[300];

int solve(int i, int p, int v)
{
    if (p == 0 || i > n)
        return 0;
    else if (i >= m && v != 0)
        return std::max(solve(1 - m, p, v - 1), solve(i + 1, p - 1, v) + calificaciones[i]);
    else if (i < n)
        return std::max(solve(i + 1, p - 1, v) + calificaciones[i], solve(i + 1, p, v));
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