/*
 * ¡Repito! - Elaborado por Mejia Bazan Cesar Arturo
 */
#include <stdio.h>
#include <algorithm>

// //? Realizarlo con memoria
// //? ¿Estoy usando mucha memoria?
// int n, p0, v0, m;
// int calificaciones[300];
// //? Intentando no gastar memoria
// //? ¿Es necesario un booleano calculando?
// // bool calculado[300][300][300]; //! 300*300*300 = 27000000 bytes? = 27MB?
// int memoria[300 + 1][300 + 1][300 + 1]; //! 300*300*300*4 = 108000000 btyes? = 108MB?
//                                         //! 27+108 = 135 MB > 128 MB
// int solve(int i, int p, int v)
// {
//     //? Suponiendo que cuando memoria[i][p][v] = 0 no se ha calculado nada;
//     //? ¿Jalara?
//     if (memoria[i][p][v] == 0)
//     {
//         if (p == 0 || i >= n)
//         {
//             memoria[i][p][v] = 0;
//         }
//         else if (i >= m && v > 0)
//         { //* Escoge el mejor si viaja en el tiempo o el mejor de si come o espera
//             memoria[i][p][v] = std::max(solve(i - m, p, v - 1), std::max(solve(i + 1, p - 1, v) + calificaciones[i], solve(i + 1, p, v)));
//         }
//         else
//         {
//             memoria[i][p][v] = std::max(solve(i + 1, p - 1, v) + calificaciones[i], solve(i + 1, p, v));
//         }
//     }
//     return memoria[i][p][v];
// }
int main()
{

    int n0, p0, v0, m;

    //! Profesor, si lee esto, su alumno Mejia Bazan Cesar Arturo cometio el error de:
    /*
     * leer &n, &p0, &m, &v0
     * en lugar de &n, &p0, &v0, &m
     * Por si se preguntaba porque hay tantos envios con 49% en el omegaup :(
     */
    scanf("%d %d %d %d", &n0, &p0, &m, &v0);
    int calificaciones[n0];
    int memoria[n0 + 1][p0 + 1][v0 + 1];
    for (int i = 0; i < n0; i++)
    {
        scanf("%d", &calificaciones[i]);
    }
    //* Empieza programación dinamica
    for (int v = 0; v <= v0; v++)
    {
        for (int n = n0; n >= 0; n--)
        {
            for (int p = 0; p <= p0; p++)
            {
                if (p == 0 || n >= n0)
                    memoria[n][p][v] = 0;
                else if (n >= m && v > 0)
                {
                    //* No tiene caso que se espere si esta en la ultima fila
                    if (n == n0 - 1)
                        memoria[n][p][v] = std::max(memoria[n - m][p][v - 1], memoria[n + 1][p - 1][v] + calificaciones[n]);
                    else
                        memoria[n][p][v] = std::max(memoria[n - m][p][v - 1], std::max(memoria[n + 1][p - 1][v] + calificaciones[n], memoria[n + 1][p][v]));
                }
                else
                    memoria[n][p][v] = std::max(memoria[n + 1][p - 1][v] + calificaciones[n], memoria[n + 1][p][v]);
            }
        }
    }
    //* Aqui estaba haciendo el recorrido mal, el viaje en el tiempo es el movimiento más "costoso" y aqui lo estoy haciendo constantemente
    // for (int n = n0; n <= n0; n++)
    // {
    //     for (int p = p0; p >= 0; p--)
    //     {
    //         for (int v = v0; v >= 0; v--)
    //         {
    //             if (p == 0 || n >= n0)
    //                 memoria[n][p][v] = 0;
    //             else if (n >= m && v > 0)
    //                 memoria[n][p][v] = std::max(memoria[n - m][p][v - 1], std::max(memoria[n + 1][p - 1][v] + calificaciones[n], memoria[n + 1][p][v]));
    //             else
    //                 memoria[n][p][v] = std::max(memoria[n + 1][p - 1][v] + calificaciones[n], memoria[n + 1][p][v]);
    //         }
    //     }
    // }
    printf("%d", memoria[0][p0][v0]);
    return 0;
}