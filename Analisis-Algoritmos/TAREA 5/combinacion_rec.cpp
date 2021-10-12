//! ¡PRUEBA! ¡TAREA 5 CON BACKTRACKING!
#include <stdio.h>
#include <algorithm>
int n, p, m, v;
int calificaciones[300 + 1];
int conteo;
// //! Intentando divide y venceras
// int solve(int i, int k, int j, int points)
// {
//     if (i == n || k == p)
//         return points;
//     else if (i >= m && j > 0)
//     {
//         conteo = points + calificaciones[i];
//         return std::max(solve(i + 1, k + 1, j, conteo),
//                         std::max(solve(i + 1, k, j, points), solve(i + 1, k, j - 1, points)));
//     }
//     else
//     {
//         conteo = points + calificaciones[i];
//         return std::max(solve(i + 1, k + 1, j, conteo), solve(i + 1, k + 1, j, points));
//     }
// }
//! Backtracking
// void solve(int i, int k, int j, int points)
// {
//     if (i == n || k == p)
//         mejor = std::max(mejor, points);
//     else
//     {
//         if (i < n)
//         { // Se la come
//             points = points + calificaciones[i];
//             solve(i + 1, k + 1, j, points);
//             points = points - calificaciones[i];
//         }
//         // Regresa en el tiempo
//         if (i >= j && j > 0)
//             solve(i - m, k, j - 1, points);
//         // Se espera
//         solve(i + 1, k, j, points);
//     }
// }
int main()
{
    // int n0, p0, m, v0, mejor = 0;
    // int memoria[2][300 + 1];
    // int *actual = &memoria[0][0];
    // int *previa = &memoria[1][0];
    // int calificaciones[300 + 1];
    scanf("%d %d %d %d", &n, &p, &m, &v);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &calificaciones[i]);
    }
    // int v = v0;
    // for (int p = 0; p <= p0; p++, std::swap(actual, previa))
    // {
    //     for (int n = 0; n <= n0; n++)
    //     {
    //         if (p = 0)
    //             actual[n] = 0;
    //         else if (n >= m && v > 0)
    //         {
    //             // Regresa en el tiempo
    //             actual[n - m] = actual[n];
    //             v--;
    //         } else{
    //             // Come
    //             actual[n] = previa[n-1] + calificaciones[n];
    //             // Se espera
    //             actual[n]
    //         }
    //     }

    // printf("%d", solve(0, 0, v, 0));
    return 0;
}
