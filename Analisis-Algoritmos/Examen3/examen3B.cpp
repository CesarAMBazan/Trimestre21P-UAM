/*
 * Examen 3B - Mejia Bazan Cesar Arturo 2182005565
 * Cadena de parentesis
 */

#include <stdio.h>
int n;
char cadena[32 + 1];
long long contador;
void solve(int i, int open)
{
    if (i == n)
    {
        if (open != 0)
            return;
        if (n <= 16)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%c", cadena[i]);
                contador++;
            }
            printf("\n");
        }
        else
        {
            contador++;
        }
    }
    else
    {
        for (char c = '('; c <= ')'; c++)
        {
            cadena[i] = c;
            if (i == 0 || n - open >= open && open >= 0)
            {
                if (c == '(')
                    solve(i + 1, open + 1);
                else
                    solve(i + 1, open - 1);
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    solve(0, 0);
    if (n > 16)
        printf("%lld", contador);
    return 0;
}