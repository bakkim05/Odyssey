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
	/*Thread t1 = new Thread(new Runnable() {
        public void run() {
       	 geneticAlgorithm();
       	 t1.interrupt();
        }
   });  */

	
	
	
	
	public void runGenAlgorithm() throws InterruptedException {
		geneticAlgorithm();
	}
	
	public void stopGenAlgorithm() {

	}
	

	private  void geneticAlgorithm() throws InterruptedException {
		
		Population population = new Population(txt_wordToFind.getText(),  Integer.parseInt(txt_mutateRate.getText()),Integer.parseInt(txt_populationSize.getText()));
		
		int num = 0;
		while(num <= 10000) {
			population.TestPopulation();
			population.SaveTheAdapted();
			showPopulation(population.showPopulation(),population.showbestIndividual());
			population.MateThePopulation();
			
			num++;
		}
			
		
	}
	
	private void showPopulation(List<popmember> population, String Bestindividual) {
		ObservableList<String> items = FXCollections.observableArrayList();
		
		for(popmember ppmbr : population) {
			items.add(ppmbr.Word);
		}
		
		list_Population.getItems().clear();
		list_Population.setItems(items);
		lbl_closestWord.setText(Bestindividual);
		
		
		
		
	}
	
	
}
