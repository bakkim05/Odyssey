package factory;
import xml.*;

public class loadSong extends XMLFactory {
	public String encode = null;
	public String name = null;
	StaXParser hola = new StaXParser();
	@Override
	public double getImporteIva() {
		// TODO Auto-generated method stub
		return 0;
	}
	public String getMusic() {
	
		encode = hola.getEncoderMusic("config.xml");
		System.out.println("dentro: "+ encode);
		return encode;
	}
	@Override
	public String getSongName() {
		// TODO Auto-generated method stub
		name = hola.getSongMusic("config.xml");
		return name;
	}


}
