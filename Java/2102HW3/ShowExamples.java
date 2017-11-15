import static org.junit.Assert.*;
import org.junit.Test;
import java.util.LinkedList;

public class ShowExamples 
{
	ShowManager1 sm1 = new ShowManager1();
	LinkedList<Show> shows = new LinkedList<Show>();
	ShowManager2 sm2 = new ShowManager2();
	LinkedList<Show> shows2 = new LinkedList<Show>();
	ShowSummary report1 = new ShowSummary();
	ShowSummary report2 = new ShowSummary();
	
	ShowSummary report3 = new ShowSummary();
	
	LinkedList<Show> singleEntry = new LinkedList<Show>();
	ShowSummary single = new ShowSummary();
	
	LinkedList<Show> singleDayTime = new LinkedList<Show>();
	ShowSummary singleDay = new ShowSummary();
	
	LinkedList<Show> singleNightTime = new LinkedList<Show>();
	ShowSummary singleNight = new ShowSummary();
	public ShowExamples()
	{
		LinkedList<Episode> eps1 = new LinkedList<Episode>();
		eps1.add(new Episode("Best of Both Worlds", 88));
		eps1.add(new Episode("The Ultimate Computer", 49));
		eps1.add(new Episode("Trials and Tribble-ations", 43));		
		Show s1 = new Show("Star Trek", 1800, eps1);
		shows.add(s1);
		report1.primetime.add(s1);
		
		LinkedList<Episode> eps2 = new LinkedList<Episode>();
		eps2.add(new Episode("Fear of a Bot Planet", 23));
		eps2.add(new Episode("The Why of Fry", 21));
		eps2.add(new Episode("Roswell that Ends Well", 23));
		eps2.add(new Episode("Meanwhile", 22));
		Show s2 = new Show("Futurama", 1900, eps2);
		shows.add(s2);
		report1.primetime.add(s2);
		
		LinkedList<Episode> eps3 = new LinkedList<Episode>();
		eps3.add(new Episode("Yakko's World", 4));
		eps3.add(new Episode("Hello Nice Warners", 8));
		eps3.add(new Episode("Where Rodents Dare", 9));
		Show s3 = new Show("Animaniacs", 1630, eps3);
		shows.add(s3);
		report1.daytime.add(s3);
		
		LinkedList<Episode> eps4 = new LinkedList<Episode>();
		eps4.add(new Episode("The Letter W", 59));
		eps4.add(new Episode("The Letter P", 57));
		eps4.add(new Episode("The Letter I", 58));
		Show s4 = new Show("Sesame Street", 900, eps4);
		shows.add(s4);
		report1.daytime.add(s4);
		
		LinkedList<Episode> eps5 = new LinkedList<Episode>();
		eps5.add(new Episode("The Doctor Falls",60));
		eps5.add(new Episode("Oxygen",30));
		eps5.add(new Episode("The Power of Three",50));
		eps5.add(new Episode("Dinosaurs on a Spaceship",45));
		Show s5 = new Show("Doctor Who",1200,eps5);
		shows2.add(s5);
		report3.daytime.add(s5);
		
		LinkedList<Episode> eps6 = new LinkedList<Episode>();
		eps6.add(new Episode("Mob Rules",45));
		eps6.add(new Episode("Confessions",30));
		eps6.add(new Episode("Genetics",10));
		eps6.add(new Episode("Whistleblowers",120));
		Show s6 = new Show("Blue Bloods",1900,eps6);
		shows2.add(s6);
		report3.primetime.add(s6);
		
		LinkedList<Episode> eps7 = new LinkedList<Episode>();
		eps7.add(new Episode("Ke Ku 'Ana",130));
		eps7.add(new Episode("Misery Loves Company",30));
		eps7.add(new Episode("Assets",43));
		eps7.add(new Episode("Hold the Breath",202));
		Show s7 = new Show("H50",1800,eps7);
		shows2.add(s7);
		report3.primetime.add(s7);
		
		LinkedList<Episode> eps8 = new LinkedList<Episode>();
		eps8.add(new Episode("The Quad",20));
		eps8.add(new Episode("Morgan",90));
		eps8.add(new Episode("The Pod",120));
		eps8.add(new Episode("Stod",4));
		Show s8 = new Show("WPI Show",100,eps8);
		shows2.add(s8);
		
		singleEntry.add(s6);
		single.primetime.add(s6);
		
		singleDayTime.add(s4);
		singleDay.daytime.add(s4);
		
		singleNightTime.add(s8);
	}
	
	//Multiple primetime and daytime shows
	@Test
	public void instructorTestOrganizeShows() 
	{
		ShowSummary report2 = sm1.organizeShows(shows);
		assertEquals(report1, report2);
	}
	
	//Multiple primetime and daytime shows with a nighttime broadcast
	@Test
	public void secondMethodTest() {
		ShowSummary report4 = sm1.organizeShows(shows2);
		assertEquals(report3,report4);
	}
	
	//Empty and empty list tester
	@Test
	public void thridMethodTest() {
		ShowManager1 sm2 = new ShowManager1();
		LinkedList<Show> emptyList = new LinkedList<Show>();
		ShowSummary tester = sm2.organizeShows(emptyList);
		ShowSummary emptySm = new ShowSummary();
		assertEquals(tester,emptySm);
	}

	//Single entry primetime list tester
	@Test
	public void FourthMethodTest() {
		ShowManager1 organizer = new ShowManager1();
		ShowSummary singleSM = organizer.organizeShows(singleEntry);
		assertEquals(single,singleSM);
	}
	
	//Single entry daytime list tester
	@Test
	public void FifthMethodTest() {
		ShowManager1 organizer = new ShowManager1();
		ShowSummary singleSM = organizer.organizeShows(singleDayTime);
		assertEquals(singleDay,singleSM);
	}
	
	//Single nighttime entry list test
	@Test
	public void SixthMethodTest() {
		ShowManager1 organizer = new ShowManager1();
		ShowSummary singleSM = organizer.organizeShows(singleNightTime);
		assertEquals(singleSM,singleNight);
	}

}



//Problem 1 Strategy 1
//Subtasks
//First, the 'organizeShows' method must be able to cycle through the list of shows in order to process them; this means a for loop can be used to 
//help solve the problem. The element-based for loop cycles until it hits the end of the list of shows, each time looking for a 'Show'. First,
//the loop checks if the show is on or after 6am and before 5pm. If this is true, it add it to the daytime list of shows in the summary. If that
//is not true, it checks to see if it is on or after 5pm and before 11pm. If that is true, it then adds the show to the primetime list in the 
//show summary. If all else fails, then it does nothing with the show because the network does not care about it. Finally, once the loop is done,
//the method reaches the bottom and returns the ShowSummary

//List of subtasks
//
//Loop through the list of shoes
//Check what time the show is
//Add it to either daytime or primetime list of shows in the report
//Return the report















