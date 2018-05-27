package application;


import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.xml.stream.XMLStreamException;

import javaclient.SocketClient;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.chart.BarChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.media.MediaPlayer.Status;
import javafx.util.Duration;
import mediaPlayer.Player;
import other.ErrorHandlersK;
import xml.writer;

public class MainPController {
	
	Player player = new Player();
	public Button btn_playPause;
	public TextField txt_songName;
	public TextField txt_songArtist;
	public Slider slr_song;
	public Label lbl_time;
	public BarChart<?,?> sbc_groovBox;
	ErrorHandlersK errHand = new ErrorHandlersK();
	List MetaSongsList = new ArrayList<>();

	

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
	
	
	//player.Encode()

	
	public void loadASong() {
		
		try {
			String message = callForMedia();		
			if(message != null) {
				player.setMediaFromEncodedFile(message);
			}
		} catch (XMLStreamException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		//load listeners	
		startAllListeners();
		
	}
	
	private String callForMedia() throws XMLStreamException {
		
		//Create XML
		writer Writer = new writer();
		Writer.setFile("config2.xml");
		Writer.createMusic("", "", "", "", "", "", "", 4);
		
		//Sends the XML
		SocketClient sock = new SocketClient("localhost");
		sock.requestHostname();
		
		System.out.println(sock.message);
		
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
				SocketClient sock = new SocketClient("localhost");
				sock.requestHostname();
				
				
				
	}
		
		
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
		
		
	}
	
	
	
}



