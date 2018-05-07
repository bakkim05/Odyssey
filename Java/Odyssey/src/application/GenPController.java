package application;

import java.util.List;

import geneticAlg.Population;
import geneticAlg.popmember;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;

public class GenPController {

	@FXML
	public TextField txt_wordToFind;
	public TextField txt_mutateRate;
	public TextField txt_populationSize;
	public Label lbl_closestWord;
	public ListView<String> list_Population;
	
	//GenAlgorithm thread
	Thread t1 = new Thread(new Runnable() {
        public void run() {
       	 geneticAlgorithm();
        }
   });  

	
	
	
	
	public void runGenAlgorithm() {
		t1.start();
	}
	
	public void stopGenAlgorithm() {
		t1.interrupt();
	}
	

	private  void geneticAlgorithm() {
		
		Population population = new Population(txt_wordToFind.getText(),  Integer.parseInt(txt_mutateRate.getText()),Integer.parseInt(txt_populationSize.getText()));
		
		int num = 0;
		while(num <= 50000) {
			
			population.TestPopulation();
			population.SaveTheAdapted();
			showPopulation(population.showPopulation(),population.showbestIndividual());
			population.MateThePopulation();
			
			num++;
		}
			
		
	}
	
	private void showPopulation(List<popmember> population, String Bestindividual) {
		
		List<String> pop = null;
		for(int i =0; i<population.size()-1;i++) {
			pop.add(population.get(i).Word);
		}
		
		ObservableList<String> items = (ObservableList<String>) pop;
		list_Population.getItems().clear();
		list_Population.setItems(items);
		lbl_closestWord.setText(Bestindividual);
		
		
		
		
	}
	
	
}
