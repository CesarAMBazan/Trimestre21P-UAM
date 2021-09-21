/*Clase Nodo: en esta clase se define lo que es un nodo de cada iteración*/
package com.zerolcamb.clases;


/**
 *
 * @author Zerol
 */
public class Nodo implements Comparable<Nodo>{
    /*Un nodo apunta a su padre, almacena el estado del rompecabezas y tambien
    el gn y el fn
    */
    private Nodo padre;
    private int[][] recibido;
    private int gn;
    private int fn;

    /*Constructor*/
    public Nodo(Nodo padre,int[][] recibido, int gn, int fn) {
        this.padre = padre;
        this.recibido = recibido;
        this.gn = gn;
        this.fn = fn;
    }
    /*Setters*/
    public void setPadre(Nodo padre) {
        this.padre = padre;
    }

    public void setRecibido(int[][] recibido) {
        this.recibido = recibido;
    }

    public void setGn(int gn) {
        this.gn = gn;
    }

    public void setFn(int fn) {
        this.fn = fn;
    }
    /*Getters*/
    public Nodo getPadre() {
        return padre;
    }
    
    public int[][] getRecibido() {
        return recibido;
    }

    public int getGn() {
        return gn;
    }

    public int getFn() {
        return fn;
    }
    /*comparador del Nodo
    */
    @Override
    public int compareTo(Nodo o) {
        if(this.getFn() > o.getFn()) return 1;
        if(this.getFn() < o.getFn()) return -1;
        else return 0;
    }    
}
