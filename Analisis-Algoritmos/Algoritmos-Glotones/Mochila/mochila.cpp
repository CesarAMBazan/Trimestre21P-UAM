#include <stdio.h>
#include <algorithm>

struct objeto
{
    int peso, valor;
};

bool predicado(objeto a, objeto b)
{
    double vka = double(a.valor) / a.peso;
    double vkb = double(b.valor) / b.peso;
    return vka > vkb;
}
int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    objeto arr[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &arr[i].peso, &arr[i].valor);
    }

    std::sort(&arr[0], &arr[0] + n, predicado);

    double res = 0;
    for (int i = 0; i < n; i++)
    {
        int meter = std::min(c, arr[i].peso);
        c -= meter;
        double fraccion = double(meter) / arr[i].peso;
        res += fraccion * arr[i].valor;
    }

    printf("%.2f", res);
    return 0;
}