package mediaPlayer;

import java.io.File;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.stage.FileChooser;
import javafx.util.Duration;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.StackedBarChart;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;



public class Player {

	public MediaPlayer medPly = null;
	Media media = null;
	
	public void setMedia() {
		
		FileChooser fc = new FileChooser();
		//fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("*.mp3"));
		File file = fc.showOpenDialog(null);
		String path = file.getAbsolutePath();
		path = path.replace("\\", "/");
		this.media = new Media(new File(path).toURI().toString());
		
		setMedPly();
	}
	
	private void setMedPly() {
		
		medPly = new MediaPlayer(media);
		//this.medPly.stop();
		
	}
	
	public void runMedia() {
		
		this.medPly.play();
		
	}
	
	public void pauseMedia() {
		
		this.medPly.pause();
		
	}
	
	
public void mediaTimeListener(Slider slr_song, Label lbl_time) {
		
		medPly.currentTimeProperty().addListener(new ChangeListener<Duration>() {

            @Override
            public void changed(ObservableValue<? extends Duration> observable, Duration oldValue, Duration newValue) {
                
            	slr_song.setMax(medPly.getMedia().getDuration().toSeconds());
            	slr_song.setMin(0);
            	slr_song.setValue(newValue.toSeconds());
            	lbl_time.setText(Double.toString(newValue.toMinutes()));
            	
            }
            });
	}
	
	

public void mediaVisualizer(BarChart<?,?> sbc_groovbox) {

	 medPly.setAudioSpectrumListener(new SpektrumListener(this.medPly, sbc_groovbox));  

	
}

	
	
}
