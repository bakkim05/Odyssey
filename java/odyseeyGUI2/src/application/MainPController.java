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
import javafx.scene.control.ListView;
import javafx.scene.control.Slider;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.media.MediaPlayer.Status;
import javafx.stage.Stage;
import javafx.util.Duration;
import mediaPlayer.MetaSongs;
import mediaPlayer.Player;
import other.ErrorHandlersK;
import xml.writer;

public class MainPController {

	Player player = new Player();
	SocketClient sock;
	public TextField txt_gender;
	public TextField txt_artist;
	public TextField txt_album;
	public TextField txt_year;
	public TextArea txt_lyrics;
	public ChoiceBox<String> cb_Options;
	public ChoiceBox<String> cb_sort;
	public ChoiceBox<String> cb_songsInServer;
	public Button btn_playPause;
	public ListView<String> lv_myTracks;
	public TableView<MetaSongs> tbv_myTracks;
	public TableColumn<MetaSongs, String> clm_song;
	public TableColumn<MetaSongs, String> clm_artist;
	public TableColumn<MetaSongs, String> clm_album;
	public TextField txt_songName;
	public TextField txt_songArtist;
	public Slider slr_song;
	public Label lbl_time;
	public BarChart<?,?> sbc_groovBox;
	ErrorHandlersK errHand = new ErrorHandlersK();
	public static List<MetaSongs> MetaSongsList = new ArrayList<MetaSongs>();
	public ObservableList<MetaSongs> dataInTable;
	private MetaSongs metaSongToChange;
	
	@FXML

	private void initialize() {

		cb_Options.setItems(FXCollections.observableArrayList(
				"The Gene game!","Complete the sentence!", "Log out", "Delete my account"));

		cb_sort.setItems(FXCollections.observableArrayList(
				"Sort by song name", "Sort by song artist"));
		
		cb_songsInServer.setItems(FXCollections.observableArrayList(
				"Songs in Server"));
		
		//Starts all the listeners
		//startAllListeners();
		
		//to test lv_myTracks
		MetaSongs mt1 = new MetaSongs("la bamba", "21", "este otro", "el otro a", null, null, null);
		MetaSongs mt2 = new MetaSongs("la merde", "25", "el men", "el album", null, null, null);
		MetaSongs mt3 = new MetaSongs("quiero rep", "regue", "Ozuna", "odisea", null, null, null);

		
		MetaSongsList.add(mt1);
		MetaSongsList.add(mt2);
		MetaSongsList.add(mt3);

	
		//...CREATES THE MUSIC TABLE...
		
		 // Set up the table data
        clm_song.setCellValueFactory(
            new PropertyValueFactory<MetaSongs,String>("songName")
        );
        clm_artist.setCellValueFactory(
            new PropertyValueFactory<MetaSongs,String>("Artist")
        );
        clm_album.setCellValueFactory(
            new PropertyValueFactory<MetaSongs,String>("Album")
        );
		
		updateMyTracks();

	}





	//player.Encode()
	public void playPauseMedia() {

		// Playing and pausing music
		System.out.println("play");
		
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
				//
				//String encodesong = XMLInterface.getXML(message).getMusic();
				//String namesong = XMLInterface.getXML(message).getSongName();
				String mse = message;
				String result = mse.substring(4, message.length());// inicia en la posicion 4 hasta el largo del string
				System.out.println("result"+result);
				if(result != null) {
				 System.out.println("entre al if");
				 player.setMediaFromEncodedFile(result);
				}
			}
		} catch (XMLStreamException e) {
			// TODO Auto-generated catch block
			System.out.println("fallo catch");
			e.printStackTrace();
		}

		//load listeners
		 
	 
		//player.setMediaFromFileChooser();
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

	
	private void updateMyTracks(){
		
		if(MetaSongsList.isEmpty()) {
			//MetaSongsList is empty!
		}else {
			
			//Updates the lv_myTracks
			List<String> list = new ArrayList<String>();
	        
			for(MetaSongs mts : MetaSongsList) {	
				list.add(mts.getSongName());			
			}
	        ObservableList<String> obList = FXCollections.observableList(list);
			lv_myTracks.getItems().clear();
	        lv_myTracks.setItems(obList);
			
		
	        // Updates table_myTracks
		dataInTable = FXCollections.observableArrayList();
		for(MetaSongs mts : MetaSongsList) {			
			dataInTable.add(mts);					
		}
		tbv_myTracks.setItems(dataInTable);
		
			
		}
		
		
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

	
	
	public void btnChangeMeta() {
		String year = metaSongToChange.getYear();
		String genero = metaSongToChange.getGender();
		String album = metaSongToChange.getAlbum();
		String artista = metaSongToChange.getArtist();
		String cancion = metaSongToChange.getSongName();
		String letra = metaSongToChange.getLyrics();
		writer nuevoData = new writer();
		try {
			nuevoData.createMusic(cancion, genero, artista, album, year, letra, " ", 3);
			sock.requestHostname();
		} catch (XMLStreamException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
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
				}else if(newValue.equals(1)) {// complete the sentence
					try {
						goToGene2Page();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}else if(newValue.equals(2)) {// Log out
					try {
						goToStartPage();
					} catch (IOException e) {
						e.printStackTrace();
					}

				}else if(newValue.equals(3)) {//delete account
					// insert code here
				}
				
			}

		});

		//
		
		
		//cb_sort
		
		
		cb_sort.getSelectionModel().selectedIndexProperty().addListener(new ChangeListener<Number>() {

			@Override
			public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {

				//add code here!!

			}

		});
		
		
		//

		//cb_songsInServer
		
		
		cb_songsInServer.getSelectionModel().selectedIndexProperty().addListener(new ChangeListener<Number>() {

			@Override
			public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {

				System.out.println("cb_songsInServer is working");
				
			}

		});
		
		
		//
		
		// lv_myTracks
		
		
		lv_myTracks.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>() {
		    @Override
		    public void changed(ObservableValue<? extends String> observable, String oldValue, String newValue) {
		        
		    	for(MetaSongs mmt : MetaSongsList) {
		    	    if(mmt.getSongName().equals(newValue)) {
		    	    	
		    	    	metaSongToChange = mmt;
		    	    	
		    	    	txt_gender.setText(mmt.getGender());
		    	    	txt_artist.setText(mmt.getArtist());
		    	    	txt_album.setText(mmt.getAlbum());
		    	    	 txt_year.setText(mmt.getYear());
		    	    	 txt_lyrics.setText(mmt.getLyrics());
		    	    	
		    	    	 break;
		    	    	 
		    	    }
		    	}
		    	
		    	
		    }
		});
		
		
		//
		
		
		
		
	}

	private void goToGenePage() throws IOException {

		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/GenPage.fxml"));
		Scene genePage = new Scene(gui);

		//this line optains the stage information
		Stage window = (Stage)lbl_time.getScene().getWindow();
		window.setScene(genePage); // txt_createUser is needed here to obtain the window its in
		window.show();

	}

	
	private void goToGene2Page() throws IOException {

		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/Gen2Page.fxml"));
		Scene gen2Page = new Scene(gui);

		//this line optains the stage information
		Stage window = (Stage)lbl_time.getScene().getWindow();
		window.setScene(gen2Page); // txt_createUser is needed here to obtain the window its in
		window.show();

	}

	
	
	private void goToStartPage() throws IOException {

		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/StartPage.fxml"));
		Scene startPage = new Scene(gui);

		//this line optains the stage information
		Stage window = (Stage)lbl_time.getScene().getWindow();
		window.setScene(startPage); // txt_createUser is needed here to obtain the window its in
		window.show();

	}


}
