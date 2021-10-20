/*
 * El ratón que salta chueco - elaborado por Mejia Bazan Cesar Arturo
 * Posición del raton: (R_i, R_j)
 * Posición de la madriguera: (H_i, H_j)
 * Posibles movimientos del raton (x, y) = (M, N)
 * NORTE: (M - F, N + D)
 * SUR:   (M + F, N - D)
 * ESTE:  (M + D, N + F)
 * OESTE: (M - D, N - F)
 */
#include <stdio.h>
#include <vector>
struct posicion
{
    int i, j;
};

int main()
{
    int m, n, frente, derecha, ri, rj, hi, hj;
    scanf("%d%d%d%d%d%d%d%d", &m, &n, &frente, &derecha, &ri, &rj, &hi, &hj);
    bool tablero[m][n] = {};
    posicion raton_inicial = {ri, rj};
    posicion madriguera = {hi, hj};
    std::vector<posicion> actual = {raton_inicial};
    tablero[raton_inicial.i][raton_inicial.j] = true;
    for (int pasos = 0; actual.size() > 0; pasos++)
    {
        std::vector<posicion> siguiente;
        for (posicion p : actual)
        {
            if (p.i == madriguera.i && p.j == madriguera.j)
            {
                printf("%d\n", pasos);
                return 0;
            }
            //* PATITAS = NORTE, SUR, ESTE, OESTE
            posicion patitas[] = {{p.i - frente, p.j + derecha},
                                  {p.i + frente, p.j - derecha},
                                  {p.i + derecha, p.j + frente},
                                  {p.i - derecha, p.j - frente}};
            for (posicion checar : patitas)
            {
                if (0 <= checar.i && checar.i < m && 0 <= checar.j && checar.j < n && tablero[checar.i][checar.j] == false)
                {
                    siguiente.push_back(checar);
                    tablero[checar.i][checar.j] = true;
                }
            }
        }
        actual = siguiente;
    }
    printf("-1");
    return 0;
}