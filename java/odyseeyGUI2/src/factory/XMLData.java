package factory;

public class XMLData extends XMLFactory{
	 
@Override
 public double getImporteIva() {
 // TODO Auto-generated method stub
 return getImporte()*1.07;
 }

@Override
public String getSongName() {
	// TODO Auto-generated method stub
	return null;
}
 
}
