/*
 * Saltando hacia la pared
 */
#include <stdio.h>
#include <vector>

int main()
{
    int corto, largo, distancia;
    scanf("%d%d%d", &corto, &largo, &distancia);

    std::vector<int> actual = {0};
    int visitadas[distancia + 1] = {};
    for (int i = 0; i <= distancia; i++)
    {
        visitadas[i] = -1;
    }
    visitadas[0] = 0;
    for (int pasos = 0;; ++pasos)
    {
        std::vector<int> siguiente;
        for (int posicion : actual)
        {
            if (posicion == distancia)
            {
                printf("%d\n", pasos);
                // Reconstruir la solución
                int trabajo = distancia;
                std::vector<int> saltos;
                do
                {
                    saltos.push_back(trabajo - visitadas[trabajo]);
                    trabajo = visitadas[trabajo];
                } while (trabajo != 0);
                for (int i = saltos.size() - 1; i >= 0; --i)
                {
                    printf("%d ", saltos[i]);
                }
                return 0;
            }
            for (int hijo : {posicion + corto, posicion - corto, posicion + largo, posicion - largo})
            {
                if (0 <= hijo && hijo <= distancia && visitadas[hijo] == -1)
                {
                    visitadas[hijo] = posicion;
                    siguiente.push_back(hijo);
                }
            }
        }
        actual = siguiente;
    }

    return 0;
}
