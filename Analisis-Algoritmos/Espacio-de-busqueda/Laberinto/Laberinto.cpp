#include <stdio.h>
#include <vector>

struct posicion
{
    int i, j;
};

struct posicion_y_lobos
{
    int i, j, w;
};

int main()
{
    int lobos, n;
    scanf("%d%d", &lobos, &n);

    char tablero[n][n];
    posicion entrada, salida;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" %c", &tablero[i][j]);
            if (tablero[i][j] == 'E')
            {
                entrada = {i, j};
            }
            else if (tablero[i][j] == 'S')
            {
                salida = {i, j};
            }
        }
    }
    int vistos[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vistos[n][n] = 10e9;
        }
    }

    std::vector<posicion_y_lobos> actual = {{entrada.i, entrada.j, 0}};
    vistos[entrada.i][entrada.j] = 0;
    for (int pasos = 0; actual.size() > 0; ++pasos)
    {
        std::vector<posicion_y_lobos> siguiente;
        for (posicion_y_lobos p : actual)
        {
            if (p.i == salida.i && p.j == salida.j)
            {
                printf("%d\n", pasos);
                return 0;
            }
            posicion patitas[] = {{p.i - 1, p.j}, {p.i + 1, p.j}, {p.i, p.j - 1}, {p.i, p.j + 1}};
            for (posicion checar : patitas)
            {
                if (0 <= checar.i && checar.i < n && 0 <= checar.j && checar.j < n && tablero[checar.i][checar.j] != '#')
                {
                    int enfrentados = p.w + (tablero[checar.i][checar.j] == '*');
                    if (enfrentados <= lobos && enfrentados < vistos[checar.i][checar.j])
                    {
                        siguiente.push_back({checar.i, checar.j, enfrentados});
                        vistos[checar.i][checar.j] = enfrentados;
                    }
                }
            }
        }
        actual = siguiente;
    }
    printf("-1");
    return 0;
}