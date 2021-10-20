/*
 * -Criterios "intuitivos" que podemos probar
 * 1) Ir primero al evento que empieza primero
 * 2) Preferir eventos cortos (primero ir al evento de menor duración)
 * 3) Ir primero al evento que termina primero.
 */
#include <stdio.h>
#include <algorithm>

struct evento
{
    int ini, fin;
};

bool predicado(evento a, evento b)
{
    return a.fin < b.fin;
}
int main()
{
    int n;
    scanf("%d", &n);
    evento arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].ini, &arr[i].fin);
    }
    std::sort(&arr[0], &arr[0] + n, predicado);

    int cuenta = 0, hora = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].ini >= hora)
        {
            cuenta += 1;
            hora = arr[i].fin;
        }
    }
    printf("%d", cuenta);
    return 0;
}