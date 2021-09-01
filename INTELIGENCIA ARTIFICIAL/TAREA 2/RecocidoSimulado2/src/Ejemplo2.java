
public class Ejemplo2 
{
	public static void main(String[] args) 
	{
		int temp = 1000;
		int tempFinal = 10;

		// Solución inicial aleatoria
		int sol[] = { 0, 0, 0, 0, 0 };
		while (temp > tempFinal) 
		{
			boolean encontrado = false;

			// Copiamos la solución de sol en mejorVecino
			int[] mejorVecino = new int[sol.length];
			System.arraycopy(sol, 0, mejorVecino, 0, sol.length);
			
			// Calculo el costo de la funcion con el vecino actual
			int costoActual = costeFuncion(binarioADecimal(mejorVecino));

			// Copiamos el vecino actual para ir modificándolo
			int[] copiaVecino = new int[sol.length];
			System.arraycopy(sol, 0, copiaVecino, 0, sol.length);

			for (int i = 0; i < sol.length && !encontrado; i++) 
			{
				// Hallamos los vecinos con una función que altera los bits
				// Por ejemplo los vecinos de {0,0,1,0,1} serían:
				// {1,0,1,0,1}, {0,1,1,0,1}, {0,0,0,0,1}, {0,0,1,1,1} y {0,0,1,0,0}

				if (copiaVecino[i] == 1) 
				{
					copiaVecino[i] = 0;
				} 
				else 
				{
					copiaVecino[i] = 1;
				}
				// Comparamos el costo del vecino actual con el nuevo vecino
				// y lo aceptamos si el coste es mayor o la probabilidad
				// de aceptación es mayor, lo aceptamos

				if (costoActual < costeFuncion(binarioADecimal(copiaVecino)) || probabilidadAceptacion(costoActual,
						costeFuncion(binarioADecimal(copiaVecino)), temp) > Math.random()) 
				{

					mejorVecino = copiaVecino;
					costoActual = costeFuncion(binarioADecimal(copiaVecino));
					encontrado = true;
				}

				copiaVecino = new int[sol.length];
				System.arraycopy(sol, 0, copiaVecino, 0, sol.length);
			}

			sol = mejorVecino;

			// Enfriamos la temperatura en cada iteración
			temp *= 0.90;

		}

		// Mostramos los resultados por pantalla

		System.out.print("Número binario: [");
		for (int i = 0; i < sol.length; i++) 
		{
			System.out.print(sol[i]);
		}
		System.out.print("]");

		int dec = binarioADecimal(sol);
		System.out.println(", Valor en decimal: " + dec + " ,Coste: " + costeFuncion(dec));
	}

	public static int costeFuncion(int x) 
	{
		// Realizamos el coste según la operación propuesta
		int v = 0;
		v = (int) Math.pow(x, 3) - 60 * (int) Math.pow(x, 2) + (900 * x) + 100;
		return v;
	}

	public static int binarioADecimal(int[] binario) 
	{
		// Realizamos una función para convertir el array de binarios en un valor
		// decimal

		int v = 0;
		int cont = 0;

		for (int i = binario.length - 1; i >= 0; i--) 
		{
			if (binario[i] == 1) 
			{
				v += (int) Math.pow((double) 2, (double) cont);
			}
			cont++;
		}
		return v;
	}

	public static double probabilidadAceptacion(int costeActual, int costeVecino, double temperatura) 
	{
		// Si la nueva solucion es peor se calcula una probabilidad de aceptación
		return Math.exp((costeVecino - costeActual) / temperatura);
	}

}
