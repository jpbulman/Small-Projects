import java.util.LinkedList;

class DataBT implements IBinTree {
	int data;
	IBinTree left;
	IBinTree right;

	DataBT(int data, IBinTree left, IBinTree right) {
		this.data = data;
		this.left = left;
		this.right = right;
	}

	// an alternate constructor for when both subtrees are empty
	DataBT(int data) {
		this.data = data;
		this.left = new MtBT();
		this.right = new MtBT();
	}

	// determines whether this node or node in subtree has given element
	public boolean hasElt(int e) {
		return this.data == e || this.left.hasElt(e) || this.right.hasElt(e);
	}

	// adds 1 to the number of nodes in the left and right subtrees
	public int size() {
		return 1 + this.left.size() + this.right.size();
	}

	// adds 1 to the height of the taller subtree
	public int height() {
		return 1 + Math.max(this.left.height(), this.right.height());
	}
	
	public LinkedList<Integer> valueList(LinkedList<Integer> adder){
		
		if(this.left.size()==0&&this.right.size()==0) {
			adder.add(this.data);
			return adder;
		}
		else {
			adder.add(this.data);
			LinkedList<Integer> a = left.valueList(new LinkedList<Integer>());
			LinkedList<Integer> b = right.valueList(new LinkedList<Integer>());
			a.addAll(b);
			adder.addAll(a);
			return adder;
		}
		
	}

	public int getData() {
		return this.data;
	}

	public boolean isHeap() {
		
		if (this.left.size() == 0 && this.right.size() == 0) {
			return true;
		}

		if (this.left.isHeap() && this.right.isHeap() && ((this.data<this.left.getData()||this.left.getData()==-1)&&(this.data<this.right.getData()||this.right.getData()==-1))) {
			return true;
		} 
		else {
			return false;
		}

	}
}
