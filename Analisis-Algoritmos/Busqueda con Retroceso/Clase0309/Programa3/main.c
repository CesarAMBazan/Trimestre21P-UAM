/*
 * Ya tenemos un código (y tal vez entendamos cómo funciona) que imprime 2^N cadenas binarias de
 * longitud N. Ahora queremos un código que imprima únicamente las cadenas binarias palíndromas
 */

#include <stdio.h>
#define n 20

char cadena[n + 1] = {};

/*
* Vamos a llenar la cadena de la posición i en adelante
* la idea es que se generen las 2^N cadenas binarias
*/
void procesa(int i)
{
    if (i == n)
    {
        for (int i = 0, j = n - 1; i < j; ++i, --j)
            if (cadena[i] != cadena[j])
                return;
        printf("%s\n", cadena);
    }
    else
    {
        cadena[i] = '0';
        procesa(i + 1);

        cadena[i] = '1';
        procesa(i + 1);
    }
}

int main()
{
    procesa(0);
}