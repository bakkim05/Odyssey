package factory;
import xml.StaXParser;

public class XMLData extends XMLFactory{
	public String ans;	 
	public StaXParser parser;
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

	@Override
	public boolean getAnswer(String xmlFile) {
		// TODO Auto-generated method stub
		parser = new StaXParser();
		ans = parser.getAnswer(xmlFile);
		System.out.println("ni entre aqui"+ans);
		if(ans.equals("Success")) {
			return true;
		}else {
			return false;
		}
	}
}
