import java.util.ArrayList;
import java.util.Collections;

public class Viaje 
{
    private ArrayList viajePorCiudades = new ArrayList<Ciudad>();
    private int distancia = 0;
    
    // Construye un viaje por ciudades vacío
    public Viaje()
    {
        for (int i = 0; i < AdministradorViajes.numberOfCities(); i++) 
        {
            viajePorCiudades.add(null);
        }
    }
    
    // Construye un viaje a partir de otro viaje
    public Viaje(ArrayList tour)
    {
        this.viajePorCiudades = (ArrayList) tour.clone();
    }
    
    // Información del viaje
    public ArrayList getTour()
    {
        return viajePorCiudades;
    }

    // Crea un individuo aleatoriamente
    public void generateIndividual() 
    {
        // Ciclo que recorre todas las ciudades destino para añadirlas al viaje
        for (int cityIndex = 0; cityIndex < AdministradorViajes.numberOfCities(); cityIndex++) 
        {
          setCity(cityIndex, AdministradorViajes.getCity(cityIndex));
        }
        // Reordena el viaje
        Collections.shuffle(viajePorCiudades);
    }

    // Obtiene una ciudad del viaje
    public Ciudad getCity(int tourPosition) 
    {
        return (Ciudad)viajePorCiudades.get(tourPosition);
    }

    // Sets a city in a certain position within a tour
    public void setCity(int tourPosition, Ciudad city) 
    {
        viajePorCiudades.set(tourPosition, city);
        // If the tours been altered we need to reset the fitness and distance
        distancia = 0;
    }
    
    // Calcula la distancia total del viaje
    public int getDistance()
    {
    	
        if (distancia == 0) 
        {
            int distanciaDelViaje = 0;
            for (int cityIndex=0; cityIndex < tourSize(); cityIndex++) 
            {
                // Obtener la ciudad desde la que se parte
                Ciudad ciudadOrigen = getCity(cityIndex);
                // Ciudad destino
                Ciudad ciudadDestino;
                // Compruebe que no estamos en la última ciudad del recorrido
                if(cityIndex+1 < tourSize())
                {
                    ciudadDestino = getCity(cityIndex+1);
                }
                else
                {
                    ciudadDestino = getCity(0);
                }
                // Obtener la distancia entre las dos ciudades
                distanciaDelViaje += ciudadOrigen.distanceTo(ciudadDestino);
            }
            distancia = distanciaDelViaje;
        }

        return distancia;
    }

    public int tourSize() 
    {
        return viajePorCiudades.size();
    }
    
    @Override
    public String toString() 
    {
        String geneString = "|";
        for (int i = 0; i < tourSize(); i++) 
        {
            geneString += getCity(i)+"|";
        }
        return geneString;
    }
}
