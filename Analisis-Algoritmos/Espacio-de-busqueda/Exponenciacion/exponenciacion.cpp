#include <stdio.h>
#include <vector>

int main()
{

    int n;
    scanf("%d", &n);

    std::vector<int> actual = {0};
    bool vistos[40] = {};
    vistos[0] = true;

    for (int pasos = 0;; ++pasos)
    {
        std::vector<int> siguiente;
        for (int valor : actual)
        {
            if (valor == n)
            {
                printf("%d\n", pasos);
                return 0;
            }
            for (int hijo : {valor + 1, valor - 1, valor * 2})
            {
                if (0 <= hijo && hijo >= 0 && hijo < 40 & vistos[hijo] == false)
                {
                    siguiente.push_back(hijo);
                    vistos[hijo] = true;
                }
            }
        }
        actual = siguiente;
    }
}