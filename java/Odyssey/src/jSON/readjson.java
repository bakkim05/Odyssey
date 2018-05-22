package jSON;

import java.io.FileReader;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.File;
import java.io.BufferedReader;
import java.io.FileWriter; 
import java.util.Iterator;

public class readjson {

	public void read() {
		JSONParser parser = new JSONParser();
		try{
			Object obj = parser.parse(new FileReader("example.json"));
			 
			JSONObject jsonObject = (JSONObject) obj;
	 
			String nombre = (String) jsonObject.get("name");
			System.out.println("nombre:"+nombre);
	 
			long edad = (Long) jsonObject.get("edad");
			System.out.println("edad:"+edad);
	 
			// recorrer arreglo
			JSONArray leng= (JSONArray) jsonObject.get("Musica");
			System.out.println("Musica_favoritos:");
			Iterator iterator =leng.iterator();
			while (iterator.hasNext()) {
				System.out.println(iterator.next());
			}
			
		}catch(Exception ex){
			System.err.println("Error: "+ex.toString());
		}finally{
			
}
	}
	
	
	
}
