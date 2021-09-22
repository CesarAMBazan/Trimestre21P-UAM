/*
 * Antipalindromos formados por digitos
 * Sea c una cadena de longitud par y r su reverso. diremos que c es un antipalindromo si C_i != r_i para todo i
 * por ejemplo, si c = "gato" entonces r = "otag" y ningún caracter coincide, por lo que es un antipalíndromo.
 * Escribe un programa que calcule la cantidad de antipalíndromos de longitud n formados por dígitos del 1 al 3
 * 
 * Entrada:
 * Un entero n. puedes suponer que n es par y que 0<=N<=20
 * 
 * salida:
 * Un entero que sea la cantidad de cadenas que cumplen la condición
 */

//* Estrategia 1 (lenta): Generar todas las cadenas y revisar cuáles si son validas

#include <stdio.h>

int n;
char cadena[20 + 1] = {};
int contador;

// Llenar la cadena de la posición i en adelante
void genera(int i)
{
    // vamos a usar la n global
    if (i == n)
    {
        for (int i = 0, j = n - 1; i < j; i++, j--)
            if (cadena[i] == cadena[j])
                return;
        contador++;
    }
    else
    {
        cadena[i] = '1';
        genera(i + 1);
        cadena[i] = '2';
        genera(i + 1);
        cadena[i] = '3';
        genera(i + 1);
    }
}

int main()
{
    scanf("%d", &n);
    genera(0);
    printf("%d", contador);
    return 0;
}