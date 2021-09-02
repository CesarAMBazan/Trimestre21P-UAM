/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.zerolcamb.operaciones;

import com.zerolcamb.clases.Nodo;
import java.util.AbstractList;
import java.util.ArrayList;
import java.util.List;
import sun.tools.tree.ThisExpression;

/**
 *
 * @author Zerol
 */
public class Rompecabezas {
    public static List<Nodo> abiertos;
    public static List<Nodo> cerrados;
    public Rompecabezas() {
        abiertos = new ArrayList<Nodo>();
        cerrados = new ArrayList<Nodo>();
    }
    
    public static void inicio(){
        
        int[][] estado_inicial = construirRompecabezas();
        int[][] estado_objetivo = { {1,2,3},{4,5,6},{7,8,0} };
        
        Nodo inicio;
        Nodo objetivo;
        
        inicio = new Nodo (estado_inicial, 0, 0);
        inicio.fn = calcularFn(inicio, estado_objetivo);
        abiertos.add(inicio);
        System.out.println("\n");
        while (true) {            
            Nodo aux = abiertos.get(0);
            System.out.print("");
            System.out.println(" | ");
            System.out.println(" \\'/ \n");
            imprimirRompecabezas(aux.recibido);
            if(calcularHn(aux.recibido, estado_objetivo) == 0) break;
            
        }
        imprimirRompecabezas(estado_inicial);
        imprimirRompecabezas(estado_objetivo);
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
        return calcularHn(inicio.recibido, objetivo)+inicio.gn;
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
}
