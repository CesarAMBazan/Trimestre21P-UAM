
package com.zerolcamb.clases;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Zerol
 */
public class Nodo implements Comparable<Nodo>{
    
    private int[][] recibido;
    private int gn;
    private int fn;

    public Nodo(int[][] recibido, int gn, int fn) {
        this.recibido = recibido;
        this.gn = gn;
        this.fn = fn;
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
    
    public int[][] getRecibido() {
        return recibido;
    }

    public int getGn() {
        return gn;
    }

    public int getFn() {
        return fn;
    }

    @Override
    public int compareTo(Nodo o) {
        if(this.getFn() > o.getFn()) return 1;
        if(this.getFn() < o.getFn()) return -1;
        else return 0;
    }
    
}
