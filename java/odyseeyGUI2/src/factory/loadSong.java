package factory;
import xml.*;

public class loadSong extends XMLFactory {
	public String encode = null;
	@Override
	public double getImporteIva() {
		// TODO Auto-generated method stub
		return 0;
	}
	public String getMusic() {
		StaXParser hola = new StaXParser();
		encode = hola.getEncoderMusic("config.xml");
		System.out.println("dentro: "+ encode);
		return encode;
	}


}
