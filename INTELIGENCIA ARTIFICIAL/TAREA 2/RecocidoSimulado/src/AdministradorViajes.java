import java.util.ArrayList;

public class AdministradorViajes 
{
	// Lista de las ciudades
    private static ArrayList ciudadesDestino = new ArrayList<Ciudad>();

    public static void addCity(Ciudad city) 
    {
        ciudadesDestino.add(city);
    }
    
    // Obtener una ciudad dado su indice
    public static Ciudad getCity(int index)
    {
        return (Ciudad)ciudadesDestino.get(index);
    }
    
    // Obtener el número de ciudades destino
    public static int numberOfCities()
    {
        return ciudadesDestino.size();
    }
    
}
