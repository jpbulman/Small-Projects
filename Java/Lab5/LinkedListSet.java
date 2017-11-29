import java.util.LinkedList;

public class LinkedListSet implements ISet{

	LinkedList<String> list;
	
	LinkedListSet(LinkedList<String> list){
		this.list=list;
	}
	
	public boolean hasElt(String s) {
		return this.list.contains(s);
	}
	
	public ISet addElt(String elt) {
		this.list.add(elt);
		return this;
	}
	
	public int size() {
		return this.list.size();
	}
	
}
