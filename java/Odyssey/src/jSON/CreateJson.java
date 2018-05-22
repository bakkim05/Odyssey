package jSON;

import org.json.simple.JSONObject;

public class CreateJson {

	
	// THE KEYS FOR JSON INFO ARE:	10->CREATING A USER   11-> LOADING A USER    
	
	public JSONObject createUser(String UserName, String PassWord) {
		
		JSONObject theJson = new JSONObject();
		
		theJson.put("key", 10);
		theJson.put("username", UserName);
		theJson.put("password", PassWord);

		return theJson;
		
	}
	
	public JSONObject loadUser(String UserName, String Password) {
		
		JSONObject theJson = new JSONObject();
		
		theJson.put("key", 11);
		theJson.put("username", UserName);
		theJson.put("password", Password);
		
		return theJson;
	}
	
	
}
