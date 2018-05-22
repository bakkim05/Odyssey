package application;


import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.StackedBarChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.media.MediaPlayer.Status;
import javafx.util.Duration;
import mediaPlayer.Player;

public class MainPController {
	
	Player player = new Player();
	public Button btn_playPause;
	public Slider slr_song;
	public Label lbl_time;
	public BarChart<?,?> sbc_groovBox;

	

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
		
		player.setMedia();
		
		//load listeners
		
		startAllListeners();
		
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



