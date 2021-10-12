#include <stdio.h>
#include <algorithm>
#include <vector>
int n, p, m, v, suma = 0, Mgrande = 0;
int pizzas[300 + 1];
int memoria[300 + 1][300 + 1][300 + 1] = {};
int resuelve(int i, int p, int v)
{
    if (memoria[i][p][v] == 0)
    {
        if (p == 0 || i >= n)
        {
            memoria[i][p][v] = 0;
        }
        else
        {
            if (i >= m && v != 0)
            {
                int maxi = std ::max(resuelve(i + 1, p - 1, v) + pizzas[i], resuelve(i + 1, p, v));
                memoria[i][p][v] = std ::max(maxi, resuelve(i - m, p, v - 1));
            }
            else
            {
                memoria[i][p][v] = std::max(resuelve(i + 1, p - 1, v) + pizzas[i], resuelve(i + 1, p, v));
            }
        }
    }
    return memoria[i][p][v];
}
int main()
{
    scanf("%d %d %d %d", &n, &p, &m, &v);
    for (int i = 0; i < n; ++i)
    {
        int pizza;
        scanf("%d", &pizza);
        pizzas[i] = pizza;
    }

    // printf("%d ", resuelve(0, p, v));

    for (int i = n; i >= 0; --i)
    {
        for (int j = 0; j <= p; j++)
        {
            for (int u = 0; u <= v; u++)
            {

                if (p == 0 || i >= n)
                {
                    memoria[i][j][u] = 0;
                }
                else
                {
                    if (i >= m && v != 0)
                    {

                        int maxi = std::max(memoria[i + 1][p - 1][v] + pizzas[i], memoria[i + 1][p][v]);
                        memoria[i][j][u] = std ::max(maxi, memoria[i - m][p][v - 1]);
                    }
                    else
                    {
                        memoria[i][j][u] = std::max(memoria[i + 1][p - 1][v] + pizzas[i], memoria[i + 1][p][v]);
                    }
                }
            }
        }
    }

    printf("%d", memoria[0][p][v]);
}
