package factory;

public class XMLUser extends XMLFactory{
	 
@Override
 public double getImporteIva() {
 // TODO Auto-generated method stub
 return getImporte()*1.21;
 }
 
}
