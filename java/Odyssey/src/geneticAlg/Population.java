package geneticAlg;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

import other.QuickSort;

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
		
		for(popmember ppmbr : population) {			
			ppmbr.TestPopMember(this.searchedWord);			
		}
		
	}

	

	
	
	public void SaveTheAdapted() {
		List<popmember> theAdapted = new ArrayList<>();
		
		// sorts the population list using popmember.TestResult 
		QuickSort qs = new QuickSort();
		qs.quickSort(population);
		Collections.reverse(population);
		
		for(int i = 1; i<=(20); i++) {
			theAdapted.add(population.get(i-1));	
		}
		this.theBestIndividual = theAdapted.get(0).Word;
		this.population = theAdapted;	
	}
	
	
	

	
	
	public void MateThePopulation() {
		
		List<String> genePool=new ArrayList<>();
		List<popmember> newPopulation = new ArrayList<>();
					
			for(popmember ppmbr : population) {
				for(char chr : ppmbr.Word.toCharArray()) {
					if(false==genePool.contains(Character.toString(chr))) {
						genePool.add(Character.toString(chr));
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
		String l1 = null, l2 = null;

		for(int i=1; i<=this.searchedWordLength; i++) {
			l1 = genePool.get(0 + (int)(Math.random() * ((genePool.size() - 1) + 1)));
			
			if(l1=="a"||l1=="e"||l1 =="i"||l1=="o"||l1=="u") {
				son = son + l1;
				l2 = l1;
			}else if(l1!="a"||l1!="e"||l1!="i"||l1!="o"||l1!="u"&&l2=="a"||l2=="e"||l2=="i"||l2=="o"||l2=="u") {
				son = son + l1;
				l2 = l1;
			}else {
				i--;
			}
			
			 
		
		}
		son = son.substring(1);
		return son;
	}
	
	
	
	public List<popmember> showPopulation(){
		
		return population;
		
	}
	
	
	public String showbestIndividual() {
		return this.theBestIndividual;
	}
	
	 
	
}
