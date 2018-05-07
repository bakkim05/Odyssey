import org.json.simple.JSONObject;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.nio.file.*;
import org.json.simple.JSONArray;

public class WriteJson {
	
	public void saveJson() {
		JSONObject obj = new JSONObject();

	      obj.put("name", "foo");
	      obj.put("lastname", "brenes");
	      obj.put("edad", new Integer(22));
	      obj.put("username", "bbrenes");
	      obj.put("Gender", "Femenino");
	      obj.put("password","beded");
	      obj.put("is_vip", new Boolean(true));
	      JSONArray lisMusica = new JSONArray();
	      lisMusica.add("How Long");
	      lisMusica.add("Friends");
	      lisMusica.add("Havana");
	      
	      obj.put("Musica", lisMusica);
	      try {
	    	  FileWriter file = new FileWriter("example.json");
	    	  file.write(obj.toJSONString());
	    	  file.flush();
	    	  file.close();
	      }catch(Exception ex) {
	    	  System.out.println("Errox:"+ ex.toString());
	      }
	      finally {
			System.out.println(obj);
		}

	      System.out.print(obj);
	}
}
