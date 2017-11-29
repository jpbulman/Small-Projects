
import java.util.LinkedList;

public class HeapTester {

	//Micheal Clements and JP Bulman
	
	int currentMin = 0;
	
	LinkedList<Integer> listSort(LinkedList<Integer> Unsorted){
		
		if(Unsorted.size()==0) {return new LinkedList<Integer>();}
		
		LinkedList<Integer> Returner = new LinkedList<Integer>();
		
		currentMin = Unsorted.getFirst();
		int numOccured = 0;
		
		for(int i : Unsorted) {
			if(i==currentMin) {numOccured++;}
			if(i<currentMin) {currentMin=i;numOccured=1;}
		}
		
		for(int i = 1;i<=numOccured;i++) {
			Returner.add(currentMin);
		}
		
		LinkedList<Integer> remainingElts = new LinkedList<Integer>();
		
		for(int i : Unsorted) {
			if(i!=currentMin) {remainingElts.add(i);}
		}
		
		Returner.addAll(listSort(remainingElts));
		
		return Returner;
		
	}
	
	boolean addEltTester(IHeap heapOriginal, int elt, IBinTree hAdded) {
		
		IHeap added = heapOriginal.addElt(elt);
		
		boolean bin = hAdded.isHeap();
		boolean add = added.isHeap();
		
		LinkedList<Integer> addedElts = added.valueList(new LinkedList<Integer>());
		LinkedList<Integer> hAddedElts = added.valueList(new LinkedList<Integer>());
		
		LinkedList<Integer> sorted1 = listSort(addedElts);
		LinkedList<Integer> sorted2 = listSort(hAddedElts);
		
		boolean equalListOfElts = (sorted1.equals(sorted2));
		
		return(bin&&add&&equalListOfElts);
		
	}
	
	boolean remMinEltTester(IHeap hOrig, IBinTree hRemoved) {
	
		IHeap hNew = hOrig.remMinElt();
		
		boolean orig = hOrig.isHeap();
		boolean removed = hRemoved.isHeap();
		
		LinkedList<Integer> hNewElts = hNew.valueList(new LinkedList<Integer>());
		LinkedList<Integer> hRemovedElts = hRemoved.valueList(new LinkedList<Integer>());
		
		LinkedList<Integer> sorted1 = listSort(hNewElts);
		LinkedList<Integer> sorted2 = listSort(hRemovedElts);
		
		boolean listEquality = sorted1.equals(sorted2);
		
		return (orig&&removed&&listEquality);
	}
	
}
