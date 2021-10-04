#include <stdio.h>
#include <algorithm>
#include <iostream>

int n, k;
int elemento[30 + 1] = {};

void sumas(int i, int j, int e)
{

    for (int m = 0; m < e; m++)
    {

        //std :: cout << "\ni: " << i << "   j: " << j << "   e: " << e;
        std ::cout << "\n"
                   << elemento[i] << " + " << elemento[j + m] << " = " << elemento[i] + elemento[j + m];
        //std :: cout << elemento [ i ] + elemento [ j + m ] << "\n" ;
    }

    sumas(i + 1, j + 1, e - 1);
}

int main()
{

    std ::cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        std ::cin >> elemento[i];
    }

    std ::cout << "\nLos elementos que ingresaste son: ";

    for (int i = 0; i < n; i++)
    {
        std ::cout << elemento[i] << " ";
    }

    std ::cout << "\n\n";

    sumas(0, 1, n - 1);
}