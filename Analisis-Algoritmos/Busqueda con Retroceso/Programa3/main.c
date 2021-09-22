/*
 * Ya tenemos un código (y tal vez entendamos cómo funciona) que imprime 2^N cadenas binarias de
 * longitud N. Ahora queremos un código que imprima únicamente las cadenas binarias palíndromas
 * Estrategia 2 (rapida): genera únicamente las validas
 */

#include <stdio.h>
#define n 5

char cadena[n + 1] = {};

/*
* Vamos a llenar la cadena de la posición i en adelante
* la idea es que se generen las 2^N cadenas binarias
*/
void procesa(int i)
{
    if (i == n) //* Suposición: Si terminamos de llenar la cadena valida
    {
        printf("%s\n", cadena);
    }
    else
    {
        if (i < n / 2 + n % 2)
        {
            cadena[i] = '0';
            procesa(i + 1);
            cadena[i] = '1';
            procesa(i + 1);
        }
        else
        {
            cadena[i] = cadena[n - 1 - i];
            procesa(i + 1);
        }
    }
}

int main()
{
    procesa(0);
}