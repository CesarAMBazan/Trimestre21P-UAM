
public class AlgRecocidoSimulado 
{
	// Calcular la probabilidad de aceptación
    public static double probabilidadDeAceptacion(int energia, int energiaVecino, double temperatura) 
    {
        // Si la nueva solución es mejor, aceptarla
        if (energiaVecino < energia) 
        {
            return 1.0;
        }
        // Si la nueva solución es peor, calcular una probabilidad de aceptación
        return Math.exp((energia - energiaVecino) / temperatura);
    }

    public static void main(String[] args) 
    {
        // Crear y añadir ciudades
        Ciudad city = new Ciudad("Mexico", 60, 200);
        AdministradorViajes.addCity(city);
        Ciudad city2 = new Ciudad("USA",180, 200);
        AdministradorViajes.addCity(city2);
        Ciudad city3 = new Ciudad("Canada",80, 180);
        AdministradorViajes.addCity(city3);
        Ciudad city4 = new Ciudad("Rusia",140, 180);
        AdministradorViajes.addCity(city4);
        Ciudad city5 = new Ciudad("China",20, 160);
        AdministradorViajes.addCity(city5);
        Ciudad city6 = new Ciudad("Bangladesh",100, 160);
        AdministradorViajes.addCity(city6);
        Ciudad city7 = new Ciudad("Birmania",200, 160);
        AdministradorViajes.addCity(city7);
        Ciudad city8 = new Ciudad("Laos",140, 140);
        AdministradorViajes.addCity(city8);
        Ciudad city9 = new Ciudad("Tailandia",40, 120);
        AdministradorViajes.addCity(city9);
        Ciudad city10 = new Ciudad("Vietnam",100, 120);
        AdministradorViajes.addCity(city10);
        Ciudad city11 = new Ciudad("Ucrania",180, 100);
        AdministradorViajes.addCity(city11);
        Ciudad city12 = new Ciudad("Turquia",60, 80);
        AdministradorViajes.addCity(city12);
        Ciudad city13 = new Ciudad("Irak",120, 80);
        AdministradorViajes.addCity(city13);
        Ciudad city14 = new Ciudad("Iran",180, 60);
        AdministradorViajes.addCity(city14);
        Ciudad city15 = new Ciudad("Afganistan",20, 40);
        AdministradorViajes.addCity(city15);
        Ciudad city16 = new Ciudad("Pakistan",100, 40);
        AdministradorViajes.addCity(city16);
        Ciudad city17 = new Ciudad("India",200, 40);
        AdministradorViajes.addCity(city17);
        Ciudad city18 = new Ciudad("Indonesia",20, 20);
        AdministradorViajes.addCity(city18);
        Ciudad city19 = new Ciudad("Singapur",60, 20);
        AdministradorViajes.addCity(city19);
        Ciudad city20 = new Ciudad("Malasia",160, 20);
        AdministradorViajes.addCity(city20);

        // Establecer temperatura inicial
        double temp = 10000;

        // Tasa de enfriamiento
        double tasaDeEnfriamiento = 0.003;

        // Inicializar la solución actual
        Viaje solucionActual = new Viaje();
        solucionActual.generateIndividual();

        System.out.println("Distancia de la solución inicial: " + solucionActual.getDistance());

        // Establece el actual como el mejor
        Viaje elMejor = new Viaje(solucionActual.getTour());
        
        // Repetir hasta que el sistema se haya enfriado
        while (temp > 1) 
        {
            // Crear un nuevo viaje con el vecino
            Viaje nuevaSolucion = new Viaje(solucionActual.getTour());

            // Generar posiciones aletorias
            int tourPos1 = (int) (nuevaSolucion.tourSize() * Math.random());
            int tourPos2 = (int) (nuevaSolucion.tourSize() * Math.random());

            // Obtener las ciudades de las posiciones
            Ciudad citySwap1 = nuevaSolucion.getCity(tourPos1);
            Ciudad citySwap2 = nuevaSolucion.getCity(tourPos2);

            // Intercambiarlas
            nuevaSolucion.setCity(tourPos2, citySwap1);
            nuevaSolucion.setCity(tourPos1, citySwap2);
            
            // Obtener la energía de las soluciones
            int actualEnergia = solucionActual.getDistance();
            int vecinoEnergia = nuevaSolucion.getDistance();

            // Decidir si se acepta la solucion
            if (probabilidadDeAceptacion(actualEnergia, vecinoEnergia, temp) > Math.random()) 
            {
                solucionActual = new Viaje(nuevaSolucion.getTour());
            }

            // Mantener el registro de la mejor solución encontrada
            if (solucionActual.getDistance() < elMejor.getDistance()) 
            {
                elMejor = new Viaje(solucionActual.getTour());
            }
            
            // Enfriar el sistema
            temp *= 1-tasaDeEnfriamiento;
        }

        System.out.println("Solución, distancia final: " + elMejor.getDistance());
        System.out.println("Viaje: " + elMejor);
        System.out.println("Ciudad de origen: " + elMejor.getCity(0).getNombre());
    }
}
