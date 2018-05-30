package application;

import java.io.IOException;

import javax.xml.stream.XMLStreamException;

import org.json.simple.JSONObject;

import javafx.event.ActionEvent;
import jSON.CreateJson;
import javaclient.SocketClient;
import javaclient.cclient;
import javafx.event.Event;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.stage.Stage;
import javafx.scene.control.TextField;
import other.ErrorHandlersK;
import xml.writer;

public class StartPController {

	ErrorHandlersK errorHands = new ErrorHandlersK();
	public TextField txt_createUser;
	public TextField txt_createPass;
	public TextField txt_repeatPass;
	public TextField txt_password;
	public TextField txt_username;
	
	
	public void LogInButtonClicked() throws XMLStreamException, IOException {
		
		
		String err = errorHands.loadUserError(txt_username.getText().toString(), txt_password.getText().toString());
		if(err == "good") {
			
			// load Variables
						String userName = txt_username.getText().toString();
						String passw = txt_password.getText().toString();

				//Create XML
						writer Writer = new writer();
						Writer.setFile("config1.xml");
						Writer.createUser(userName, "","", "", passw, "", 11);
						
				//Sends the XML
						SocketClient sock = new SocketClient("localhost");
						sock.SendUser();
						
				//changes stages
						headToMainPage();
			
		}else {
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Odyssey Help!");
			alert.setHeaderText("Error logging in");
			alert.setContentText(err);
			alert.show();
		}
		
		
	}
	
	
	
	public void SignInButtonClicked() throws XMLStreamException {
			
		
		String err = null;
		 err = errorHands.createUserErrors(txt_createUser.getText().toString(), txt_createPass.getText().toString(), txt_repeatPass.getText().toString());
		if(err == "good") {
			
			// load Variables
			String userName = txt_createUser.getText().toString();
			String passw = txt_createPass.getText().toString();

	//Create XML
			writer Writer = new writer();
			Writer.setFile("config1.xml");
			Writer.createUser(userName, "Bertha","21", "sdfd", passw, "sdsd", 10);
			
	//Sends the XML
			//SocketClient sock = new SocketClient("localhost");
			//sock.SendUser();
			cclient lol = new cclient("localhost", 8085);
			lol.sendMessage("<?xml version=\"1.0\" encoding=\"UTF-8\"?><InfoUser>	<Username username=\"jung\">	<Name>Bertha</Name>	<Age>21</Age>	<FavSongs>sdfd</FavSongs>	<password>789</password>	<Friends>sdsd</Friends></Username>	<apCode>10</apCode></InfoUser>");
		}else {
			Alert alert = new Alert(AlertType.ERROR);
			alert.setTitle("Odyssey Help!");
			alert.setHeaderText("Error creating a User");
			alert.setContentText(err);
			alert.show();
		}
			
	}
	
	
	
	private void headToMainPage() throws IOException {
		
		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/MainPage.fxml"));
		Scene mainPage = new Scene(gui);
		
		//this line optains the stage information
		Stage window = (Stage)txt_createUser.getScene().getWindow();
		window.setScene(mainPage); // txt_createUser is needed here to obtain the window its in
		window.show();
		
	}
	
	
	
}
