/*
 * Recorrido del principe
 */

#include <stdio.h>

int n;
long long contador = 0;
bool visitadas[6][6] = {};

void resuelve(int i, int j, int s)
{
    if (s == n * n - 1)
    { //? Ya acabamos de recorrer todo el tablero
        ++contador;
    }
    else
    {
        if (i - 1 >= 0 && visitadas[i - 1][j] == false)
        {
            visitadas[i - 1][j] = true;
            resuelve(i - 1, j, s + 1);
            visitadas[i - 1][j] = false;
        }

        if (i + 1 < n && visitadas[i + 1][j] == false)
        {
            visitadas[i + 1][j] == true;
            resuelve(i + 1, j, s + 1);
            visitadas[i + 1][j] == false;
        }
        if (j - 1 >= 0 && visitadas[i][j - 1] == false)
        {
            visitadas[i][j - 1] == true;
            resuelve(i, j - 1, s + 1);
            visitadas[i][j - 1] == false;
        }
        if (j + 1 < n && visitadas[i][j + 1] == false)
        {
            visitadas[i][j + 1] == true;
            resuelve(i, j + 1, s + 1);
            visitadas[i][j + 1] == false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    visitadas[0][0] = true;
    resuelve(0, 0, 0);
    printf("%lld", contador);
}