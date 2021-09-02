
package com.zerolcamb.clases;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Zerol
 */
public class Nodo {
    
    public static int[][] recibido;
    public int gn;
    public int fn;

    public Nodo(int[][] recibido, int gn, int fn) {
        this.recibido = recibido;
        this.gn = gn;
        this.fn = fn;
    }
    
    public static int[][] generar_nodo(){
        int corde[] = encontrarVacio();
        int posibles_movimientos[][] = {{corde[0], corde[1]-1},
            {corde[0], corde[1]+1},
            {corde[0]-1, corde[1]},
            {corde[0]+1, corde[1]}};
        List<Nodo> generados = new ArrayList<Nodo>();
        for (int i = 0; i < 4; i++) {
            
            
        }
    }
    
    public static int[] encontrarVacio(){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (recibido[i][j] == 0){
                    int aux[] = {i, j};
                    return aux;
                }
            }
            
        }
    }
}
