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

//* Estrategia 2 (rapidas): Generar unicamente las cadenas validas

#include <stdio.h>

int n;
char cadena[20 + 1] = {};
int contador = 0;

// Llenar la cadena de la posición i en adelante
void genera(int i)
{
    // vamos a usar la n global
    if (i == n)
    {
        // printf("%s\n", cadena);
        contador++;
    }
    else
    {
        for (char c = '1'; c <= '3'; c++)
        {
            cadena[i] = c;
            if (i < n / 2 || cadena[i] != cadena[n - 1 - i])
                genera(i + 1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    genera(0);
    printf("%d", contador);
    return 0;
}