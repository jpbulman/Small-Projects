import static org.junit.Assert.assertEquals;

import java.util.LinkedList;

import org.junit.Test;

public class HeapTester {

	//Micheal Clements and JP Bulman
	
	//DataBT test1 = new DataBT(3,new DataBT(5,new DataBT(6,new DataBT(12,new MtBT(),new MtBT()),new DataBT(18,new MtBT(),new MtBT()),new DataBT(8,new DataBT())))),new DataBT());
	
	MtBT mtTester = new MtBT();
	
	DataBT test1 = new DataBT(1,new DataBT(3),new MtBT());
	
	DataBT test2 = new DataBT(1,new DataBT(3),new DataBT(9));
	
	DataBT test3 = new DataBT( 3 , new DataBT(5,new DataBT(10),new DataBT(7)) , new DataBT(7) );
	
	DataBT nonHeap = new DataBT( 3 , new DataBT(5,new DataBT(1),new DataBT(7)) , new DataBT(7) );
	
	MtHeap mtHeap = new MtHeap();
	
	DataHeap dataHeapTester = new DataHeap(1, new DataHeap(3) , new DataHeap(2 , new DataHeap(3) , new MtHeap()));
	
	DataHeap dataHeap1 = new DataHeap(1 , new DataHeap(3,new DataHeap(5),new MtHeap()) , new MtHeap() );
	
	DataHeap dataHeap2 = new DataHeap(1 , new DataHeap(3,new DataHeap(5),new DataHeap(6)) , new MtHeap() );
	
	DataHeap dataHeap3 = new DataHeap(3 , new DataHeap(5) , new DataHeap(6));
	
	DataHeap notHeap1 = new DataHeap(90 , new DataHeap(90,new DataHeap(5),new DataHeap(6)) , new DataHeap(2,new DataHeap(4),new MtHeap()) );
	
	
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
	
	@Test
	public void addEltTester1() {
		assertEquals(true,addEltTester(dataHeap1,6,dataHeap2));
	}
	
	@Test
	public void addEltTester2() {
		assertEquals(false,addEltTester(dataHeap1,1,dataHeap2));
	}
	
	@Test
	public void addEltTester3() {
		assertEquals(false,addEltTester(notHeap1,1,dataHeap2));
	}
	
	@Test
	public void addEltTester4() {
		assertEquals(false,addEltTester(notHeap1,1,dataHeap3));
	}
	
	@Test
	public void remMinEltTester1() {
		assertEquals(true,remMinEltTester(dataHeap2,dataHeap3));
	}
	
	@Test
	public void remMinEltTester2() {
		assertEquals(false,remMinEltTester(dataHeap3,dataHeap1));
	}
	
	@Test
	public void remMinEltTester3() {
		assertEquals(false,remMinEltTester(notHeap1,dataHeap1));
	}
	
	@Test
	public void remMinEltTester4() {
		assertEquals(false,remMinEltTester(dataHeap3,dataHeap2));
	}
	
	@Test
	public void sortTest1() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(1);
		testList.add(500);
		testList.add(78);
		testList.add(-1);
		testList.add(0);
		testList.add(500);
		
		LinkedList<Integer> testCheck = new LinkedList<Integer>();
		testCheck.add(-1);
		testCheck.add(0);
		testCheck.add(1);
		testCheck.add(78);
		testCheck.add(500);
		testCheck.add(500);
		
		assertEquals(testCheck,listSort(testList));
	}
	
	@Test
	public void getDataTest1() {
		assertEquals(test1.getData(),1);
	}
	
	@Test
	public void getDataTest2() {
		assertEquals(mtTester.getData(),-1);
	}
	
	@Test
	public void getDataTest3() {
		assertEquals(test3.left.getData(),5);
	}
	
	@Test
	public void isHeapTest1() {
		assertEquals(true,test1.isHeap());
	}
	
	@Test
	public void isHeapTest2() {
		assertEquals(true,test2.isHeap());
	}
	
	@Test
	public void isHeapTest3() {
		assertEquals(true,test3.isHeap());
	}
	
	@Test
	public void isHeapTest4() {
		assertEquals(false,nonHeap.isHeap());
	}
	
	@Test
	public void isHeapTest5() {
		assertEquals(true,mtHeap.isHeap());
	}
	
	@Test
	public void isHeapTest6() {
		assertEquals(true,dataHeapTester.isHeap());
	}
	
	@Test
	public void valueListTester1() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(3);
		testList.add(5);
		testList.add(10);
		testList.add(7);
		testList.add(7);
		assertEquals(testList,test3.valueList(new LinkedList<Integer>()));
	}
	
	@Test
	public void valueListTester2() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(-1);
		assertEquals(testList,mtTester.valueList(new LinkedList<Integer>()));
	}
	
	@Test
	public void valueListTester3() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(1);
		testList.add(3);
		testList.add(-1);
		assertEquals(testList,test1.valueList(new LinkedList<Integer>()));
	}
	
}
