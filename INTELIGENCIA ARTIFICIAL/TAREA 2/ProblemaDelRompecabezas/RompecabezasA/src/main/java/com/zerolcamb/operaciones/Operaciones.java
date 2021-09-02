/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zerolcamb.operaciones;

import static com.sun.tools.doclint.Entity.lambda;
import com.zerolcamb.clases.Nodo;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 *
 * @author Zerol
 */
public class Operaciones {

  
    public static void inicio(){
        List <Nodo> abiertos = new ArrayList<Nodo>();
        List <Nodo> cerrados = new ArrayList<Nodo>();
        // int[][] estado_inicial = construirRompecabezas();
        int[][] estado_inicial = { {2,3,6}, {5,0,8}, {1,4,7}};
        int[][] estado_objetivo = { {1,2,3},{4,5,6},{7,8,0} };
        
        Nodo inicio;
        Nodo objetivo;
        
        inicio = new Nodo (estado_inicial, 0, 0);
        inicio.setFn(calcularFn(inicio, estado_objetivo));
        abiertos.add(inicio);
        System.out.println("\n");
        int max=0;
        while (max <= 10000) {
            max++;
            Nodo aux = abiertos.get(0);
            imprimirRompecabezas(aux.getRecibido());
            if(calcularHn(aux.getRecibido(), estado_objetivo) == 0){
                break;
            }
            
            List <Nodo> nodos = generar_nodo(aux);
            for (int i = 0; i < nodos.size(); i++){
                Nodo aux2 = nodos.get(i);
                aux2.setFn(calcularFn(aux2, estado_objetivo));
                abiertos.add(aux2);
            }
            
            cerrados.add(aux);
            abiertos.remove(0);
            Collections.sort(abiertos);
        }
        //mprimirRompecabezas(estado_inicial);
        //imprimirRompecabezas(estado_objetivo);
        if(max < 10000) System.out.println("Ya se acabo, se resolvio despues de: "+max
                            +" iteraciones");
        else{
            System.out.println("No se encontro solución al rompecabezas");
        }
    }
    
    public static int[][] construirRompecabezas(){
        int [][] estado_inicial = new int[3][3];
        System.out.println("");
        ArrayList<Integer> usado = new ArrayList<Integer>();
        
        int espacioVacio = (int) (1 + Math.random() * 9);
        
        for (int fila = 0; fila < 3; fila++) {
            for(int columna = 0; columna < 3; columna++){
                if(fila*3 + columna == espacioVacio){
                    estado_inicial[fila][columna] = 0;
                    continue;
                }
                int numero;
                while(usado.contains(numero = (int) (1 + Math.random() * 8)));
                usado.add(numero);
                estado_inicial[fila][columna] = numero;
            }
        }
        return estado_inicial;
    }
    public static int calcularFn(Nodo inicio, int[][] objetivo){
        return calcularHn(inicio.getRecibido(), objetivo)+inicio.getGn();
    }
    public static int calcularHn(int[][] inicio, int[][] objetivo){
        int aux = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (inicio[i][j] != objetivo[i][j] && inicio[i][j] != 0) {
                    aux +=1;
                }
            }
        }
        return aux;
    }
    public static void imprimirRompecabezas(int[][] rompecabezas){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.printf("%-4d", rompecabezas[i][j]);
            }
            System.out.println("");
        }
        System.out.println("");
    }
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
            if (movimiento != null){
                Nodo hoja_nueva = new Nodo (movimiento, actual.getGn()+1, 0);
                generados.add(hoja_nueva);
            }
        }
        return generados;
    }
    
    public static int[][] generar_movimiento(Nodo actual, int x, int y, int x2, int y2){
        if (x2 >= 0 && x2 < 3 && y2 >= 0 && y2 < 3){
            int[][] estado_aux = new int[3][3];
            estado_aux = copiar(actual);
            int aux = estado_aux[y2][x2];
            estado_aux[y2][x2] = estado_aux[y][x];
            estado_aux[y][x] = aux;
            return estado_aux;
        } else return null;
        
    }
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
}