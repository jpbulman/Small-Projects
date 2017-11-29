import static org.junit.Assert.assertEquals;

import java.util.LinkedList;

import org.junit.Test;

public class Examples {

	MtBT mtTester = new MtBT();

	DataBT test1 = new DataBT(1, new DataBT(3), new MtBT());

	DataBT test2 = new DataBT(1, new DataBT(3), new DataBT(9));

	DataBT test3 = new DataBT(3, new DataBT(5, new DataBT(10), new DataBT(7)), new DataBT(7));

	DataBT nonHeap = new DataBT(3, new DataBT(5, new DataBT(1), new DataBT(7)), new DataBT(7));

	MtHeap mtHeap = new MtHeap();

	DataHeap dataHeapTester = new DataHeap(1, new DataHeap(3), new DataHeap(2, new DataHeap(3), new MtHeap()));

	DataHeap dataHeap1 = new DataHeap(1, new DataHeap(3, new DataHeap(5), new MtHeap()), new DataHeap(5));

	DataHeap dataHeap2 = new DataHeap(1, new DataHeap(3, new DataHeap(5), new DataHeap(6)), new MtHeap());

	DataHeap dataHeap3 = new DataHeap(3, new DataHeap(5), new DataHeap(6));

	DataHeap notHeap1 = new DataHeap(90, new DataHeap(90, new DataHeap(5), new DataHeap(6)),
			new DataHeap(2, new DataHeap(4), new MtHeap()));

	DataHeap notHeap2 = new DataHeap(2, notHeap1, new MtHeap());

	HeapTester HT = new HeapTester();

	// Basic add elt tester 
	// (also handles duplicates)
	@Test
	public void addEltTester1() {
		assertEquals(true, HT.addEltTester(dataHeap1, 6, dataHeap2));
	}

	// Wrong element tester
	@Test
	public void addEltTester2() {
		assertEquals(false, HT.addEltTester(dataHeap1, 1, dataHeap2));
	}

	// When one parameter is a heap and the other is not
	@Test
	public void addEltTester3() {
		assertEquals(false, HT.addEltTester(dataHeap2, 1, notHeap1));
	}

	// Same as previous test, but with the non heap as the first parameter
	@Test
	public void addEltTester4() {
		assertEquals(false, HT.addEltTester(notHeap1, 1, dataHeap3));
	}

	// Testing when both parameters are not heaps
	@Test
	public void addEltTester5() {
		assertEquals(false, HT.addEltTester(notHeap2, 1, notHeap1));
	}

	// Tests adding an elt to an MtHeap
	@Test
	public void addEltTester6() {
		DataHeap dataHeapX = new DataHeap(6);
		assertEquals(true, HT.addEltTester(new MtHeap(), 6, dataHeapX));
	}

	// Basic removal test
	@Test
	public void remMinEltTester1() {
		assertEquals(true, HT.remMinEltTester(dataHeap2, dataHeap3));
	}

	// Basic failure test when both are heaps
	@Test
	public void remMinEltTester2() {
		assertEquals(false, HT.remMinEltTester(dataHeap3, dataHeap1));
	}

	// Failure test when one is a heap and the other is not
	@Test
	public void remMinEltTester3() {
		assertEquals(false, HT.remMinEltTester(notHeap1, dataHeap1));
	}

	// Tests when the other parameter is not a heap
	@Test
	public void remMinEltTester4() {
		assertEquals(false, HT.remMinEltTester(dataHeap3, notHeap2));
	}

	// Tests when both parameters are not heaps
	@Test
	public void remMinEltTester5() {
		assertEquals(false, HT.remMinEltTester(notHeap2, notHeap1));
	}

	// Tests a diverse and unsorted list
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

		assertEquals(testCheck, HT.listSort(testList));
	}

	// Gets data from a DataBT
	@Test
	public void getDataTest1() {
		assertEquals(test1.getData(), 1);
	}

	// Gets Data from an empty tree
	@Test
	public void getDataTest2() {
		assertEquals(mtTester.getData(), -1);
	}

	// Tests getting data from a subtree
	@Test
	public void getDataTest3() {
		assertEquals(test3.left.getData(), 5);
	}

	// Checks a DataBT
	@Test
	public void isHeapTest1() {
		assertEquals(true, test1.isHeap());
	}

	@Test
	public void isHeapTest2() {
		assertEquals(true, test2.isHeap());
	}

	@Test
	public void isHeapTest3() {
		assertEquals(true, test3.isHeap());
	}

	// Check a non-Heap
	@Test
	public void isHeapTest4() {
		assertEquals(false, nonHeap.isHeap());
	}

	// Checks an MtHeap
	@Test
	public void isHeapTest5() {
		assertEquals(true, mtHeap.isHeap());
	}

	// Checks a heap
	@Test
	public void isHeapTest6() {
		assertEquals(true, dataHeapTester.isHeap());
	}

	// Gets values for heaps
	@Test
	public void valueListTester1() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(3);
		testList.add(5);
		testList.add(10);
		testList.add(7);
		testList.add(7);
		assertEquals(testList, test3.valueList(new LinkedList<Integer>()));
	}

	// Gets value for empty heap
	@Test
	public void valueListTester2() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(-1);
		assertEquals(testList, mtTester.valueList(new LinkedList<Integer>()));
	}

	// Gets values for both combined
	@Test
	public void valueListTester3() {
		LinkedList<Integer> testList = new LinkedList<Integer>();
		testList.add(1);
		testList.add(3);
		testList.add(-1);
		assertEquals(testList, test1.valueList(new LinkedList<Integer>()));
	}

}
