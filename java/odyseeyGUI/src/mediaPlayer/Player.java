package mediaPlayer;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Base64;

import org.apache.commons.io.FileUtils;

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
	
	public void setMediaFromFileChooser() {
		
		FileChooser fc = new FileChooser();
		//fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("*.mp3"));
		File file = fc.showOpenDialog(null);
		String path = file.getAbsolutePath();
		path = path.replace("\\", "/");		
		medPly = new MediaPlayer(new Media(new File(path).toURI().toString()));
	}
	
	
	
	
	public void setMediaFromEncodedFile(String EncodedFile) {
		byte[] decodedMedia = null;
		File MediaReady = null;
		
		// Decodes the media 
		try {
			decodedMedia = Decode(EncodedFile);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		// Creates a .mp3 File for the Decoded media
		try {
			MediaReady = File.createTempFile("music", ".mp3");
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		// Fills the new .mp3 File with its information (Decoded Media)
		FileOutputStream outP;
		try {
			outP = new FileOutputStream(MediaReady);
			outP.write(decodedMedia);
			outP.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
		medPly = new MediaPlayer(new Media( new File(MediaReady.getAbsolutePath().replace("\\", "/") ).toURI().toString() ));
		
		
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



public String Encode() throws IOException {
	
	FileChooser fc = new FileChooser();
	File file = fc.showOpenDialog(null);
	
	byte[] bytes = FileUtils.readFileToByteArray(file);

	String encoded = Base64.getEncoder().encodeToString(bytes);                                       

return encoded;
	
}



public byte[] Decode(String toDecode) throws IOException {
	
	byte[] decoded = Base64.getDecoder().decode(toDecode);

	return decoded;
	
}
	


	
}
