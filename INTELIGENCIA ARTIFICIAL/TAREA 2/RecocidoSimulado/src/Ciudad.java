
public class Ciudad 
{
	String nombre;
	int x;
    int y;
    
    // Construye una ciudad colocada aleatoriamente
    public Ciudad()
    {
        this.x = (int)(Math.random()*200);
        this.y = (int)(Math.random()*200);
    }
    
    // Construye una ciudad en las posiciones x y y
    public Ciudad(String nombre, int x, int y)
    {
    	this.nombre = nombre;
        this.x = x;
        this.y = y;
    }
    
    
    public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	// Obtiene las coordenadas de la ciudad
    public int getX(){
        return this.x;
    }
    
    // Obtiene la coordenada y
    public int getY()
    {
        return this.y;
    }
    
    // Obtiene la distancia entre ciudades
    public double distanceTo(Ciudad city)
    {
        int xDistance = Math.abs(getX() - city.getX());
        int yDistance = Math.abs(getY() - city.getY());
        double distance = Math.sqrt( (xDistance*xDistance) + (yDistance*yDistance) );
        
        return distance;
    }
    
    @Override
    public String toString()
    {
        return getNombre() + ", " + getX() + ", " + getY();
    }
}
