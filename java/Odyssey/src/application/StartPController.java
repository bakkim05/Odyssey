package application;

import org.json.simple.JSONObject;

import jSON.CreateJson;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import other.ErrorHandlersK;

public class StartPController {

	ErrorHandlersK errorHands = new ErrorHandlersK();
	public TextField txt_createUser;
	public TextField txt_createPass;
	public TextField txt_repeatPass;
	public TextField txt_password;
	public TextField txt_username;
	
	
	public void LogInButtonClicked() {
		
		CreateJson createJson = new CreateJson();
		
		String err = errorHands.loadUserError(txt_username.getText().toString(), txt_password.getText().toString());
		if(err == "good") {
			JSONObject js = createJson.loadUser(txt_username.getText().toString(), txt_password.getText().toString());
			System.out.println(js);
		}else {
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Odyssey Help!");
			alert.setHeaderText("Error logging in");
			alert.setContentText(err);
			alert.show();
		}
		
		
	}
	
	
	
	public void SignInButtonClicked() {
			
		CreateJson createJson = new CreateJson();
		
		String err = null;
		 err = errorHands.createUserErrors(txt_createUser.getText().toString(), txt_createPass.getText().toString(), txt_repeatPass.getText().toString());
		if(err == "good") {
			JSONObject js = createJson.createUser(txt_createUser.getText().toString(), txt_createPass.getText().toString());
			System.out.println(js);
		}else {
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Odyssey Help!");
			alert.setHeaderText("Error creating a User");
			alert.setContentText(err);
			alert.show();
		}
			
	}
	
	
	
	
	
}
