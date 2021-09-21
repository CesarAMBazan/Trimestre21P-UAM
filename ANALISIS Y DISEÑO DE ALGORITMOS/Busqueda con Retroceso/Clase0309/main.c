/* 
 *  Objetivo: Programar una función recursiva que llene la cadena de '0' y que al final la imprima
 *  (cada llamada recursiva solamente pone un caracter; el caso base la imprime)
 */

#include <stdio.h>

const int n = 5;
char cadena[n + 1] = "XXXXX";

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
    }
}

int main()
{
    procesa(0);
}