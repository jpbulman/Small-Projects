import java.util.LinkedList;

public class Examples {

	EventGuests BST = new EventGuests(new DataBST("Bob",new DataBST("Lisa",new DataBST("Joe",new EmptyBST(),new EmptyBST()),new EmptyBST()), new EmptyBST() ));
	
	EventGuests List = new EventGuests(new LinkedListSet(new LinkedList<String>()));

	EventGuests AVL = new EventGuests(new DataBST("Bob",new DataBST("Lisa",new EmptyBST(), new EmptyBST()),new DataBST("Joe",new EmptyBST(),new EmptyBST())));
	
}
