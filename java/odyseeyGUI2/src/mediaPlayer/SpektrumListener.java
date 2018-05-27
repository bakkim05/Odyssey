package mediaPlayer;

import javafx.scene.media.AudioSpectrumListener;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.StackedBarChart;
import javafx.scene.chart.XYChart;
import javafx.scene.chart.XYChart.Series;
import javafx.scene.media.AudioSpectrumListener;
import javafx.scene.media.MediaPlayer;
import javafx.util.converter.NumberStringConverter;


public class SpektrumListener implements AudioSpectrumListener {

	MediaPlayer medPly = null;
	BarChart<?,?> sbc_groovbox;
	double[] correctedMagnitude;
	

	public SpektrumListener(MediaPlayer medPly, BarChart<?,?> sbc_groovbox) {
		super();
		this.medPly = medPly;
		this.sbc_groovbox = sbc_groovbox;
	}

	@Override
	public void spectrumDataUpdate(double timestamp, double duration, float[] magnitudes, float[] phases) {
		// TODO Auto-generated method stub
		
		//for (int i = 0; i < magnitudes.length; i++) {
		//correctedMagnitude[i] = magnitudes[i] - medPly.getAudioSpectrumThreshold();  
		//}
	XYChart.Series set1 = new XYChart.Series<>();
	
	set1.getData().add(new XYChart.Data("a",Math.abs(magnitudes[0]) ));
	set1.getData().add(new XYChart.Data("b",Math.abs(magnitudes[1]) ));
	set1.getData().add(new XYChart.Data("c",Math.abs(magnitudes[2]) ));
	set1.getData().add(new XYChart.Data("d",Math.abs(magnitudes[3]) ));

	sbc_groovbox.getData().clear();
	sbc_groovbox.getData().addAll(set1);

		
		//System.out.println(Math.abs(magnitudes[0])+" -- "+ Math.abs(magnitudes[1]));
		

		
	}

}
