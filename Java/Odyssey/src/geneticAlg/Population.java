package geneticAlg;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Population {
		
String theBestIndividual = "n";
List<popmember> population = new ArrayList<>();
int populationSize;
int mutationRate;
String searchedWord;
int searchedWordLength;
int naturalCycles;


public Population(String searchedWord, int mutationRate, int populationSize) {
	super();

	this.searchedWord = searchedWord;
	this.searchedWordLength = searchedWord.length();
	this.mutationRate = mutationRate;
	this.populationSize = populationSize;
	
	generatePopulation();
	
	
}


	private void generatePopulation() {
		Random r = new Random();
		for(int i = 1; i<=populationSize;i++) {
			popmember creature = new popmember();
			String word = "r";
			for(int w = 1; w<= this.searchedWordLength; w++) {
				
				word = word + (char)(r.nextInt('z' - 'a'+1) + 'a');
				
			}
			creature.Word = word.substring(1);
			this.population.add(creature);		
		}
		
}


	public void TestPopulation() {
		
		for(int i = 0; i < population.size()-1; i++) {
			
			population.get(i).TestPopMember(this.searchedWord);
			
		}
		
	}
	
	
	public void SaveTheAdapted() {
		List<popmember> theAdapted = new ArrayList<>();
		
		for(double i = this.searchedWordLength; i != 0; i--) {
			if(theAdapted.size() == 20) {
				break;
			}else {
				
				for(int w = 0; w < population.size()-1; w++) {
					if(population.get(w).TestResult == i) {
						theAdapted.add(population.get(w));
						population.remove(w);
					}
				}
					
			}
				
		}
		
		this.theBestIndividual = theAdapted.get(0).Word;
		this.population = theAdapted;	
	}
	
	
	
	
	public void MateThePopulation() {
		
		List<String> genePool=new ArrayList<>();
		List<popmember> newPopulation = new ArrayList<>();
		
		for(int i = 0; i < population.size()-1; i++) {
			
			for(int w = 0;w<population.get(i).Word.length()-1; w++) {
				if(!genePool.contains(population.get(i).Word.substring(w, w))) {
					genePool.add(population.get(i).Word.substring(w, w));
				}
			}
			
		}
		
		for(int i = 1; i <= this.populationSize;i++) {
			
			popmember son = new popmember();
			son.Word = createSon(genePool);
			son.mutate(this.mutationRate);
			newPopulation.add(son);
			
		}
		
		
		this.population = newPopulation;
		this.naturalCycles++;
		
		
	}
	
	
	
	
	
	private String createSon(List<String> genePool) {
		String son = "r";
		
		for(int i=1; i<=this.searchedWordLength; i++) {
			
			son = son + genePool.get(0 + (int)(Math.random() * ((genePool.size() - 1) + 1)));
			son = son.substring(1, son.length());
			
		}
		
		
		
		return son;
	}
	
	
	public List<popmember> showPopulation(){
		
		return population;
		
	}
	
	public String showbestIndividual() {
		return this.theBestIndividual;
	}
	
	 
	
}
