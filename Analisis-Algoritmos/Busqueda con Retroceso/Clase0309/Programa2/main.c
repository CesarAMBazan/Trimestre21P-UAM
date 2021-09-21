/*
 * Objetivo: Programar una función recursiva que imprima las 2N cadenas binarias que existen.
 * (Cada llamada recursiva solamente pone un caracter; el caso base la imprime)
 * procesa(i): vamos a llenar la cadena de la posición i en adelane
 */

#include <stdio.h>
#define n 3

char cadena[n + 1] = {};

/*
* Vamos a llenar la cadena de la posición i en adelante
* la idea es que se generen las 2^N cadenas binarias
*/
void procesa(int i)
{
    if (i == n)
    {
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