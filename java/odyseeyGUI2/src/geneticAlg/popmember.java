package geneticAlg;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class popmember {

	public String Word;
	public int TestResult;
	
	public void TestPopMember(String toCompare) {
		//List<String> lettersUsed = new ArrayList<>();
		this.TestResult = 0;
		
		for(char chr : Word.toCharArray()) {
			if(toCompare.contains(Character.toString(chr))) {
				//if(false==lettersUsed.contains(Character.toString(chr))) {
					TestResult ++;
					//lettersUsed.add(Character.toString(chr));
				//}
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
