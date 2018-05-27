package application;

import java.io.IOException;
import java.util.List;

import geneticAlg.Population;
import geneticAlg.popmember;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

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
        	try {
				geneticAlgorithm();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}	
       	 t1.interrupt();
        }
   });  

	
	
	
	
	public void runGenAlgorithm() throws InterruptedException {
		t1.start();
		
		//geneticAlgorithm();
	}
	
	public void stopGenAlgorithm() {
		
	}
	

	private  void geneticAlgorithm() throws InterruptedException {
		
		Population population = new Population(txt_wordToFind.getText(),  Integer.parseInt(txt_mutateRate.getText()),Integer.parseInt(txt_populationSize.getText()));
		
		int num = 0;
		while(num <= 10000) {
			population.TestPopulation();
			population.SaveTheAdapted();
			
			Platform.runLater(new Runnable(){
				@Override
				public void run() {
					showPopulation(population.showPopulation(),population.showbestIndividual());			
				}
			});
			
			
			//showPopulation(population.showPopulation(),population.showbestIndividual());
			for(popmember ppmbr : population.showPopulation()) {
				if(ppmbr.Word.equals(txt_wordToFind.getText().toString())) {
					num = 20000;
					break;
				}
			}
			population.MateThePopulation();
			
			//num++;
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
		for(popmember ppmbr : population) {
			if(ppmbr.Word.equals(txt_wordToFind.getText().toString())) {
				lbl_closestWord.setText(ppmbr.Word.toString());
				break;
			}
		}
		
		
		
		
	}
	
	public void goMainPage() {
		try {
			goToMainPage();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private void goToMainPage() throws IOException {
		
		Parent gui = FXMLLoader.load(getClass().getResource("/odyGUI/MainPage.fxml"));
		Scene mainPage = new Scene(gui);
		
		//this line optains the stage information
		Stage window = (Stage)txt_mutateRate.getScene().getWindow();
		window.setScene(mainPage); // txt_createUser is needed here to obtain the window its in
		window.show();
		
	}
	
}
