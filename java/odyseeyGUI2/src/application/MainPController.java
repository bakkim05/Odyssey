package application;


import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.stream.XMLStreamException;

import factory.XMLInterface;
import javaclient.SocketClient;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.BarChart;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.media.MediaPlayer.Status;
import javafx.stage.Stage;
import javafx.util.Duration;
import mediaPlayer.Player;
import other.ErrorHandlersK;
import xml.writer;

public class MainPController {

	Player player = new Player();
	SocketClient sock;
	public ChoiceBox<String> cb_Options;
	public Button btn_playPause;
	public TextField txt_songName;
	public TextField txt_songArtist;
	public Slider slr_song;
	public Label lbl_time;
	public BarChart<?,?> sbc_groovBox;
	ErrorHandlersK errHand = new ErrorHandlersK();
	List MetaSongsList = new ArrayList<>();
	@FXML

	private void initialize() {

		cb_Options.setItems(FXCollections.observableArrayList(
				"The Gene game!", "Log out", "Delete my account"));

		startAllListeners();

	}





	//player.Encode()
	public void playPauseMedia() {

		// Playing and pausing music
	
		if(player.medPly.getStatus() == Status.PLAYING) {

			player.pauseMedia();
			btn_playPause.setText("Play");

		}else if(player.medPly.getStatus() == Status.PAUSED) {

			player.runMedia();
			player.mediaVisualizer(sbc_groovBox);
			player.mediaTimeListener(slr_song, lbl_time);
			btn_playPause.setText("Pause");


		}else if(player.medPly.getStatus() == Status.READY) {

			player.runMedia();
			player.mediaVisualizer(sbc_groovBox);
			player.mediaTimeListener(slr_song, lbl_time);
			btn_playPause.setText("Pause");

		}





	}

	public void loadASong() {

		try {
			String message = callForMedia();
			if(message != null) {
				System.out.println("holi:"+message);
				//player.setMediaFromEncodedFile(message);
				XMLInterface.getXML(message);
			}
		} catch (XMLStreamException e) {
			// TODO Auto-generated catch block
			System.out.println("fallo catch");
			e.printStackTrace();
		}

		//load listeners
		//startAllListeners();

	}

	private String callForMedia() throws XMLStreamException {
		//Create XML
		writer Writer = new writer();
		Writer.setFile("config2.xml");
		Writer.createMusic("", "", "", "", "", "", "", 4);
		//Sends the XML
		//SocketClient sock = new SocketClient("localhost");
		sock.requestHostname();

		System.out.println("callFO:"+sock.message);

		return sock.message;
	}

	public void searchSong() throws Exception{

		if("good" == errHand.createMusicError(txt_songName.getText().toString(), txt_songArtist.getText().toString())) {
			// load Variables
			String songName = txt_songName.getText().toString();
			String songArtist = txt_songArtist.getText().toString();

			//Create XML
			writer Writer = new writer();
			Writer.setFile("config2.xml");
			Writer.createMusic(songName, "", songArtist, "", "", "", "", 0);

			//Sends the XML
			//SocketClient sock = new SocketClient("localhost");
			sock.requestHostname();



		}




	}


	public void connectToServer() {

		sock = new SocketClient("localhost");

	}

	private void startAllListeners() {

		// slider listener

		slr_song.valueProperty().addListener(new ChangeListener<Number>() {

			@Override
			public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {

				if(Math.abs((double)newValue-(double)oldValue) > (double)oldValue+1.5 || Math.abs((double)newValue-(double)oldValue) < (double)oldValue+1.5 ) {
					//Nothing happens, its normal song reproduction
				}else {
					player.medPly.seek(Duration.seconds((double)newValue));
				}

			}
		});


		//


		//cb_Options Listener

		cb_Options.getSelectionModel().selectedIndexProperty().addListener(new ChangeListener<Number>() {

			@Override
			public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {

				if(newValue.equals(0)) {// The gene Game!
					try {
						goToGenePage();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}else if(newValue.equals(1)) {// Log out
					try {
						goToStartPage();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}else if(newValue.equals(2)) {// Delete my account

				}

			}

		});

		//

	}

	private void goToGenePage() throws IOException {

		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/GenPage.fxml"));
		Scene genePage = new Scene(gui);

		//this line optains the stage information
		Stage window = (Stage)txt_songName.getScene().getWindow();
		window.setScene(genePage); // txt_createUser is needed here to obtain the window its in
		window.show();

	}

	private void goToStartPage() throws IOException {

		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/StartPage.fxml"));
		Scene startPage = new Scene(gui);

		//this line optains the stage information
		Stage window = (Stage)txt_songName.getScene().getWindow();
		window.setScene(startPage); // txt_createUser is needed here to obtain the window its in
		window.show();

	}


}
