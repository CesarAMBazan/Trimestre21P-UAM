/*
 * A cada moneda sólo tiene caso considerar el efecto de aplicarle el movimiento o no aplicarle el movimiento
 * Si a una moneda se le aplican 2 veces un movimiento, se queda como estaba originalmente. Si a una moneda se
 * le aplican 4 veces un movimiento, se queda como estaba originalmente...
 * Eso quiere decir que no tiene caso aplicar una operación de intervalo 2 o más veces
 * en el mismo lugar. Tiene caso aplicarla 0 veces o tiene caso aplicarla 1 vez, pero sólo eso.
 * Como no tiene caso aplicar una operación de intervalo más de una vez en el mismo lugar,
 * entonces conviene preguntarnos, ¿debo aplicar la operación aqui, si o no?
 */

#include <stdio.h>
#include <algorithm>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int cuenta = 0;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (arr[i] == 0)
        {
            cuenta += 1;
            for (int j = 0; j < m; j++)
            {
                arr[i + j] = !arr[i + j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            printf("%d\n", -1);
            return 0;
        }
    }

    printf("%d", cuenta);
    return 0;
}