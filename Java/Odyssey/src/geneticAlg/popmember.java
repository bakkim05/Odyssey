package geneticAlg;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class popmember {

	public String Word;
	public double TestResult;
	
	public void TestPopMember(String toCompare) {
		List<String> lettersUsed = new ArrayList<>();
		this.TestResult = 0;
		
		for(int i = 0; i < Word.length()-1; i++) {
			if(toCompare.contains(Word.substring(i, i)) && !lettersUsed.contains(Word.substring(i, i))) {
				TestResult ++;
				lettersUsed.add(Word.substring(i, i));
			}
		}
	
	}
	
	
	public void mutate(int mutationRate) {
		if(!(mutationRate > 10 && mutationRate < 1)) {
			
			if(mutationRate >= 1 + (int)(Math.random() * ((10 - 1) + 1))) {
				
				this.Word = this.Word.substring(1);
				Random r = new Random();
				this.Word = this.Word + (char)(r.nextInt('z' - 'a'+1) + 'a');
				
			}
			
		}
		
		
		
	}
	
	
	
	
}
