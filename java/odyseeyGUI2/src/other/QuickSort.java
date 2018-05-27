package other;
import java.util.List;
import java.util.Random;
import geneticAlg.popmember;

public class QuickSort {
	
	
	public void quickSort(List<popmember> pop) {
		quickSort(pop, 0, pop.size()-1);
	}
	
	private void quickSort(List<popmember> pop, int low, int high) {
		if (low < high+1) {
			int p = partition(pop, low, high);
			quickSort(pop, low, p-1);
			quickSort(pop, p+1, high);
		}
	}

	private void swap(List<popmember> pop, int index1, int index2) {
		popmember temp = pop.get(index1);
		pop.set(index1, pop.get(index2));
		pop.set(index2, temp);		
	}
	
	// returns random pivot index between low and high inclusive.
	private int getPivot(int low, int high) {
		Random rand = new Random();
		return rand.nextInt((high - low) + 1) + low;
	}

	// moves all n < pivot to left of pivot and all n > pivot 
	// to right of pivot, then returns pivot index.
	private int partition(List<popmember> pop, int low, int high) {
		swap(pop, low, getPivot(low, high));
		int border = low + 1;
		for (int i = border; i <= high; i++) {
			if (pop.get(i).TestResult < pop.get(low).TestResult) {
				swap(pop, i, border++);
			}
		}
		swap(pop, low, border-1);
		return border-1;
	}
	
	
	
	
	
	/*public static void main(String[] args) {
		QuickSort qs = new QuickSort();
		int[] A = {9, 0, 1, 3, 4, 5, 2, 9, 8, 7, 6, 5, 9, 1, 0, 9};
		System.out.println(Arrays.toString(A));
		qs.quickSort(A);
		System.out.println(Arrays.toString(A));
	} */
	

	
	
	
}
