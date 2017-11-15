import static org.junit.Assert.*;
import org.junit.Test;
import java.util.LinkedList;

public class DataSmoothExamples 
{  
  LinkedList<Show> shows = new LinkedList<Show>();
  LinkedList<Double> showResults = new LinkedList<Double>();
  DataSmooth1 D1 = new DataSmooth1();
  
  public DataSmoothExamples() 
  {
		LinkedList<Episode> eps1 = new LinkedList<Episode>();
		eps1.add(new Episode("Best of Both Worlds", 88));
		eps1.add(new Episode("The Ultimate Computer", 49));
		eps1.add(new Episode("Trials and Tribble-ations", 43));		
		shows.add(new Show("Star Trek", 1800, eps1));
		
		LinkedList<Episode> eps2 = new LinkedList<Episode>();
		eps2.add(new Episode("Fear of a Bot Planet", 23));
		eps2.add(new Episode("The Why of Fry", 21));
		eps2.add(new Episode("Roswell that Ends Well", 23));
		eps2.add(new Episode("Meanwhile", 22));
		shows.add(new Show("Futurama", 1900, eps2));
		
		LinkedList<Episode> eps3 = new LinkedList<Episode>();
		eps3.add(new Episode("Yakko's World", 4));
		eps3.add(new Episode("Hello Nice Warners", 8));
		eps3.add(new Episode("Where Rodents Dare", 9));
		shows.add(new Show("Animaniacs", 1630, eps3));
		
		LinkedList<Episode> eps4 = new LinkedList<Episode>();
		eps4.add(new Episode("The Letter W", 59));
		eps4.add(new Episode("The Letter P", 57));
		eps4.add(new Episode("The Letter I", 58));
		shows.add(new Show("Sesame Street", 900, eps4));

	    showResults.add(60.0);
	    showResults.add(29.75);
	    showResults.add(29.08333);
	    showResults.add(58.0);
  }
  
//Test the funciton's handling of a normal list that has end point ... [Some finite number of middle points] ... end point.
  //This test also demonstrates that the function accurately calculates average run times and averages of avg. run times...
  @Test
  public void instructorTestDS() 
  {
	  LinkedList<Double> runtimes = D1.dataSmooth(shows);
	  
	  for(int i = 0; i < runtimes.size(); i++)
	  {
		  assertEquals(runtimes.get(i), showResults.get(i), .01);
	  }
  }
  //Tests the function's handling of a list with exactly 1 item. This shows that the function does not fail on edge case
  @Test
  public void mytest() {
	  LinkedList<Show> shorty = new LinkedList<Show>();
	  LinkedList<Episode> eps5 = new LinkedList<Episode>();
	  eps5.add(new Episode ("Inside North Korea", 60));
	  shorty.add(new Show("Animaniacs", 1630, eps5));
	  LinkedList<Double> shortyresult = new LinkedList<Double>();
	  shortyresult.add(60.0);
	  assertEquals(D1.dataSmooth(shorty), shortyresult);

  }
  //Tests the function's handling of a list with exactly 2 items. This shows the function works on the other edge case.
  @Test
  public void mytest2() {
	  LinkedList<Show> length2 = new LinkedList<Show>();
	  LinkedList<Episode> eps6 = new LinkedList<Episode>();
	  LinkedList<Episode> eps7 = new LinkedList<Episode>();
	  LinkedList<Double> resulting = new LinkedList<Double>();
	  eps6.add(new Episode("Serenity", 30));
	  length2.add(new Show("Firefly", 1400, eps6));
	  eps7.add(new Episode("Treehouse of Terror", 45));
	  length2.add(new Show("The Simpsons", 1800, eps7));
	  resulting.add(30.0);
	  resulting.add(45.0);
	  assertEquals(D1.dataSmooth(length2), resulting);
  }
}
  
  //Problem 2 Strategy 1
  //
  //List of Subtasks
  //
  //-Get show's avg run time
  //-Make a list of avg run times by looping through a list of episodes
  //-Smooth the avg run times by looping through the list of times?
  
