package factory;
import java.io.FileWriter;
import java.io.PrintWriter;

import xml.StaXParser;

public class XMLInterface {

	public static XMLFactory getXML(String tipo) {
		//tomo el valor de la entrada del cliente y le quito la palabra bull
		String strOut = tipo;
		String result = strOut.substring(4, tipo.length());// inicia en la posicion 4 hasta el largo del string
		System.out.println(result);
		StaXParser hola = new StaXParser();
		FileWriter fichero = null;
        PrintWriter pw = null;
        try
        {
            fichero = new FileWriter("config.xml");
            pw = new PrintWriter(fichero);
            pw.println(result);

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
           try {
           // Nuevamente aprovechamos el finally para 
           // asegurarnos que se cierra el fichero.
           if (null != fichero)
              fichero.close();
           } catch (Exception e2) {
              e2.printStackTrace();
           }
        }
        //Aqui agarro el valor del XML en el xml para saber que tipo de datos es
		String tipoXml = hola.getXMLName("config1.xml");
		if (tipoXml.equals("loadSong")) {
			return new loadSong();
		}
		if(tipoXml.equals("InfoUser")) {
			return new XMLUser();
		}
		if(tipoXml.equals("Data")) {
			return new XMLData();
		}
		return null;

	}
}

