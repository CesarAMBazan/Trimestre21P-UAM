/*
 * Tarea 7A: Monedas volteadas en intervalos - Mejia Bazan Cesar Arturo 2182005565
 * Quiero explicar mi codigo porque no pense que fuera a ser aceptado en el OmegaUp
 * razón por la cual mi tiempo es de 0.80s comparado con el de los demas que es de
 * 0.15s
 */

#include <stdio.h>
#include <algorithm>

//* Se tiene un struct de intervalo de monedas, con el inicio y el final
struct monedas
{
    int i, j;
};
//* El comparador para ordenar en el arreglo las monedas que terminan primero en el
//* intervalo
bool predicado(monedas a, monedas b)
{
    return a.j < b.j;
}
int main()
{
    int m;
    scanf("%d", &m);
    monedas arr[m];
    //* mayor guarda hasta donde llegan los intervalos en la fila infinita de monedas
    int mayor = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &arr[i].i, &arr[i].j);
        if (mayor < arr[i].j)
            mayor = arr[i].j;
    }
    //* Se ordena el arreglo
    std::sort(&arr[0], &arr[0] + m, predicado);
    //* Se crea un arreglo booleano que corresponde hasta donde llegan los intervalos
    bool fila[mayor] = {};
    int cuenta = 0;
    for (int i = 0; i < m; i++)
    {
        //* booleano auxiliar check que siempre inicia en falso
        bool check = false;
        //* Se recorre el intervalo en busqueda de monedas volteadas
        for (int j = arr[i].i - 1; j < arr[i].j; j++)
        {
            //* si encuentra una moneda se acaba la busqueda
            if (check)
                break;
            //* si en la posición en la que esta el recorrido hay una moneda volteada
            if (fila[j] == true)
                check = true; //* el booleano check se hace true
        }
        //* Si no se encontro una moneda volteada en la busqueda del intervalo
        if (!check)
        {
            //* se voltea una moneda
            cuenta += 1;
            //* la posición en la que se voltea esa moneda es en la ultima posición
            //* del intervalo actual.
            fila[arr[i].j - 1] = true;
        }
    }
    //* Se imprime cuantas monedas se voltearon
    printf("%d", cuenta);
    return 0;
}