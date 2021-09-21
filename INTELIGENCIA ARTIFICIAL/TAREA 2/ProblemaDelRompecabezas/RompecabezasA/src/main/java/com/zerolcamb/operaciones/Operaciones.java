/*
 * Esta clase se encarga de las operaciones del rompecabezas
 */
package com.zerolcamb.operaciones;

import com.zerolcamb.clases.Nodo;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

/**
 *
 * @author Zerol
 */

public class Operaciones {
    /*Inicio de las operaciones*/
    public static void inicio(){
        /*Listas que almacenan los nodos abiertos y cerrados*/
        List <Nodo> abiertos = new ArrayList<Nodo>();
        List <Nodo> cerrados = new ArrayList<Nodo>();
        /*Declaración del estado objetivo*/
        int[][] estado_objetivo = { {1,2,3},{4,5,6},{7,8,0} };
        System.out.println("Construyendo rompecabezas...");
        /*Construccion del rompecabezas aleatorio*/
        // int[][] estado_inicial = construirRompecabezas(estado_objetivo);
        int [][] estado_inicial = { {0,2,3},{1,4,6},{7,5,8} };
        /*Impresion de los dos rompecabezas*/
        System.out.println("El rompecabezas construido fue: ");
        imprimirRompecabezas(estado_inicial);
        System.out.println("El estado objetivo es: ");
        imprimirRompecabezas(estado_objetivo);
        
        System.out.println("-----------------------------");
        /*Se crea un nodo inicial*/
        Nodo inicio;
        inicio = new Nodo (null,estado_inicial, 0, 0);
        /*Se calcula el Fn del Nodo inicial*/
        inicio.setFn(calcularFn(inicio, estado_objetivo));
        /*Se añade el nodo inicial a la lista de los nodos abiertos*/
        abiertos.add(inicio);
        System.out.println("Resolviendo...");
        int max=0; /*Variable auxiliar para el número maximo de iteraciones*/
        while (max <= 3000) {
            /*Se borran los nodos que ya se hayan visto*/
            borrarVistos(abiertos, cerrados); 
            /*Se crea un nodo auxiliar a partir del primer nodo de la lista*/
            Nodo aux = abiertos.get(0);
            if(calcularHn(aux.getRecibido()) == 0){
                /*Si la distancia manhattan es 0, se acaba la iteración*/
                break;
            }
            /*Se genera una lista con los nodos de aux, es decir con los 
            posibles movimientos
            */
            
            List <Nodo> nodos = generar_nodo(aux);
            for (int i = 0; i < nodos.size(); i++){
                Nodo aux2 = nodos.get(i);
                /*Se calcula el fn de cada uno de los movimientos*/
                aux2.setFn(calcularFn(aux2, estado_objetivo));
                /*Y se agregan a la lista de abiertos*/
                abiertos.add(aux2);
            }
            /*Se añade el nodo auxiliar a cerrado, ya obtuvimos sus subnodos*/
            cerrados.add(aux);
            /*Se quita el nodo actual de abiertos*/
            abiertos.remove(0);
            /*Se ordena abiertos de manera en que el nodo con mejor
            fn es el siguiente en ser procesado
            */
            Collections.sort(abiertos);
            max++;
        }
        /*Se imprime la iteracion*/
        int pasos;
        pasos = imprimirIteracion(abiertos.get(0));
        if(max < 3000) System.out.println("Ya se acabo, se resolvio despues de: "+max
                            +" nodos expandidos\nY con un número de "+pasos+" pasos");
        else{
            System.out.println("No se encontro solución al rompecabezas");
        }
    }
    /*Esta funcion borra los nodos ya exporados en la lista de cerrados*/
    public static void borrarVistos(List<Nodo> abiertos,List<Nodo> cerrados){
        for (Nodo aux : cerrados) {
            for (int i = 0; i < abiertos.size(); i++) {
                if(abiertos.get(i).getRecibido() == aux.getRecibido()){
                    abiertos.remove(i);
                }
            }
        }    
    }
    /*Se construye el rompecabezas partiendo desde el objetivo realizando 
    un número determinado de pasos
    Nota: un número aleatorio de pasos > 100 hara que el programa no pueda encontrar
    una solución a muchos problemas
    */
    public static int[][] construirRompecabezas(int[][]Objetivo){ //Construccion del puzzle
        int pasos = 100; 
        Random rand = new Random();
        int mov;
        /*Se crea un nodo auxiliar a partir del objetivo*/
        Nodo auxiliar = new Nodo(null, Objetivo, 0, 0);
        int[][] movimiento = new int[3][3];
        int[] vacio;
        for (int i = 0; i <= pasos; i++) {
            /*Se busca el espacio vacio*/
            vacio = encontrarVacio(auxiliar);
            /*Se decide aleatoriamente que movimiento se va a hacer*/
            mov = rand.nextInt(4);
            switch (mov){
                case 0: // Arriba
                    movimiento = generar_movimiento(auxiliar, 
                            vacio[0], vacio[1], vacio[0], vacio[1]-1);
                    break;
                case 1: // Abajo
                    movimiento = generar_movimiento(auxiliar, 
                            vacio[0], vacio[1], vacio[0], vacio[1]+1);
                    break;
                case 2: // Izquierda
                    movimiento = generar_movimiento(auxiliar, 
                            vacio[0], vacio[1], vacio[0]-1, vacio[1]);
                    break;
                case 3: // Derecha
                    movimiento = generar_movimiento(auxiliar, 
                            vacio[0], vacio[1], vacio[0]+1, vacio[1]);
                    break;
                default:
                    break;
            }
            if (movimiento != null) auxiliar.setRecibido(movimiento);
        }
        return auxiliar.getRecibido();
    }
    /*Esta función calcula Fn*/
    public static int calcularFn(Nodo inicio, int[][] objetivo){
        /* Fn = Gn + Hn */
        return calcularHn(inicio.getRecibido())+inicio.getGn();
    }
    /*Está función calcula la distancia Manhattan de cada uno de los espacios
    con respecto al objetivo, en el caso de esta implementación solo sirve si
    el objetivo es 123456780, por ahora no se admiten objetivos diferentes
    */
    public static int calcularHn(int[][] inicio){
        int x, y, aux = 0;
         for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (inicio[i][j] != 0){
                    y = (inicio[i][j]-1)%3;
                    x = (inicio[i][j]-1)/3;
                    aux += Math.abs(y - j) + Math.abs(x - i);
                }
            }
        }
        return aux;
    }
    /*Esta funcion imprime un rompecabezas*/
    public static void imprimirRompecabezas(int[][] rompecabezas){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.printf("%-4d", rompecabezas[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
    }
    /*Esta función genera los nodos de un nodo, realizando los posibles movimientos
    */
    public static List<Nodo> generar_nodo(Nodo actual){
        int corde[] = encontrarVacio(actual);
        int posibles_movimientos[][] = {{corde[0]-1, corde[1]}, //izquierda
            {corde[0]+1, corde[1]}, // derecha
            {corde[0], corde[1]-1}, // arriba
            {corde[0], corde[1]+1}}; // abajo
        List<Nodo> generados = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int[][] movimiento;
            movimiento = generar_movimiento(actual, corde[0], corde[1],
                    posibles_movimientos[i][0], posibles_movimientos[i][1]);
            if (actual.getPadre() != null){
                /*Se revisa si el movimiento no es nulo (Es decir que se intento
                ir a un espacio fuera del tablero) o si el movimiento no crea un
                estado donde quedariamos en el mismo punto que el padre del Nodo
                */
                if (movimiento != null && actual.getPadre().getRecibido() != movimiento){
                    Nodo hoja_nueva = new Nodo (actual, movimiento, actual.getGn()+1, 0);
                    generados.add(hoja_nueva);
                }
            } else {
                if (movimiento != null){
                    Nodo hoja_nueva = new Nodo (actual, movimiento, actual.getGn()+1, 0);
                    generados.add(hoja_nueva);
                }
            }
                
        }
        return generados;
    }
    /*Función que genera el movimienot*/
    public static int[][] generar_movimiento(Nodo actual, int x, int y, int x2, int y2){
        if (x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3){
            int[][] estado_aux;
            estado_aux = copiar(actual);
            int aux = estado_aux[y2][x2];
            estado_aux[y2][x2] = estado_aux[y][x];
            estado_aux[y][x] = aux;
            return estado_aux;
        } else return null;
        
    }
    /*Se copia el rompecabezas del nodo actual para poder trabajar con el*/
    public static int[][] copiar(Nodo actual){
        int[][]copia = new int[3][3];
        int[][]auxiliar = actual.getRecibido();
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                copia[y][x] = auxiliar[y][x];
            }
        }
        return copia;
    }
    /*Esta función ubica en donde se encuentra el estado vacio*/
    public static int[] encontrarVacio(Nodo actual){
        int[][] recibido = actual.getRecibido();
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if (recibido[y][x] == 0){
                    int aux[] = {x, y};
                    return aux;
                }
            }
        }
        return null;
    }
    /*Esta función imprime las iteraciones realizadas de la solución*/
    public static int imprimirIteracion(Nodo iteracion) {
        List<Nodo>iteraciones = new ArrayList<Nodo>();
        iteraciones.add(iteracion);
        Nodo aux = iteracion;
        int pasos=0;
        while(aux.getPadre() != null){
            iteraciones.add(aux.getPadre());
            aux = aux.getPadre();
        }
        for (int i = iteraciones.size()-1; i >= 0 ; i--) {
            imprimirRompecabezas(iteraciones.get(i).getRecibido());
            pasos++;
        }
        return pasos;
    }
}