/*
 * Los simios marcianos
 * Elaborado por Mejia Bazan Cesar Arturo 2182005565
 */

#include <stdio.h>
#include <algorithm>

int n, s1, s2, c, mejor = 0;
bool mejor_ventana;
bool ventanas[51] = {};

void salto(int i, int s)
{
    if (mejor_ventana)
    {
        //? Se acabo de recorrer el mayor numero de ventanas
        mejor = std::max(mejor, s);
    }
    else
    {
        // Existen 3 posibilidades, Se da un salto largo, un salto corto o se deja caer
        // Salto corto
        if ((i + s1) <= 50 && ventanas[i + s1] == true)
        {
            ventanas[i + s1] = false;
            salto(i + s1, s + 1);
            ventanas[i + s1] = true;
        }
        // Salto largo
        if ((i + s2) <= 50 && ventanas[i + s2] == true)
        {
            ventanas[i + s2] = false;
            salto(i + s2, s + 1);
            ventanas[i + s2] = true;
        }
        // Dejarse caer
        for (int j = 1; j <= c; j++)
        {
            if ((i - j) > 0 && (i - j) <= 50 && ventanas[i - j] == true)
            {
                ventanas[i - j] = false;
                salto(i - j, s + 1);
                ventanas[i - j] = true;
            }
        }
        // No puede dar ningun salto
        mejor_ventana = true;
        salto(i, s);
        mejor_ventana = false;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ventana;
        scanf("%d", &ventana);
        ventanas[ventana] = true;
    }
    scanf("%d %d %d", &s1, &s2, &c);
    salto(0, 0);
    printf("%d", mejor);
    return 0;
}
