/**
 * Se tiene que resolver un rompecabezas de 8 piezas utilizando el
 * algoritmo de busqueda A*, se tiene un campo aleatorio y un objetivo
 * 
 *  - - -               1 2 3
 *  - - -               4 5 6
 *  - - -               7 8 0
 *  Estado inicial      Estado objetivo
 * 
 * donde los numeros del estado inicial son aleatorios, consideraremos el
 * espacio vacio con un 0, las condiciones son que los movimientos solo se
 * pueden realizar hacia:
 *  * Arriba
 *  * Abajo
 *  * Derecha
 *  * Izquierda
 * 
 * para el algoritmo, utilizaremos una funcion de evaluación
 *  f(n) = g(n) + h(n)
 * donde:
 *  * g(n) = distancia del nodo actual al nodo raiz (distancia que ha reccorrido
 *           el espacio vacio desde la ejecución)
 *  * h(n) = número de espacios no correspondientes comparando el estado
 *           inicial con el estado objetivo
 * 
 */
package com.zerolcamb.principal;
import com.zerolcamb.operaciones.Rompecabezas;
/**
 *
 * @author Mejia Bazan Cesar Arturo 2182005565
 * Tarea 2 problema a) Inteligencia Artificial
 */
public class principal {
    public static void main(String[] args) {
        Rompecabezas rompecabezas = new Rompecabezas();
        rompecabezas.inicio();
    }
}
