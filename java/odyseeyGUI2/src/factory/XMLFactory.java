package factory;

public abstract class XMLFactory {
	 
private String name;
private String encode;
private double importe;

public String getMusic() {
	return encode;
}

 public double getImporte() {
 return importe;
 }
 public void setImporte(double importe) {
 this.importe = importe;
 }
 
 public abstract double getImporteIva();
}
