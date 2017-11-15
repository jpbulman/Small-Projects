import static org.junit.Assert.*;
import org.junit.Test;
import java.util.LinkedList;

public class EarthquakeExamples {
  Earthquake1 E1 = new Earthquake1();
  LinkedList<Double> noData = new LinkedList<Double>();
  LinkedList<Double> threeDates = new LinkedList<Double>();  
  LinkedList<MaxHzReport> NovReports = new LinkedList<MaxHzReport>();
  
  public EarthquakeExamples() {
    threeDates.add(20151013.0);
    threeDates.add(10.0);
    threeDates.add(5.0);
    threeDates.add(20151020.0);
    threeDates.add(40.0);
    threeDates.add(50.0);
    threeDates.add(45.0);
    threeDates.add(20151101.0);
    threeDates.add(6.0);
    NovReports.add(new MaxHzReport(20151101.0,6.0));
  }

  @Test
  public void instructorTestEQ() { 
	  System.out.println(NovReports);
	  System.out.println(E1.dailyMaxForMonth(threeDates, 11));
    assertEquals(NovReports, 
                 E1.dailyMaxForMonth(threeDates, 11));
  }
  
  //Problem 3 Strategy 1 
  //
  //List of subtasks
  //
  //-Filter the data so that it's just the data for the month desired
  //-Loop through the list of month data
  //	-Keep track of what day the current piece of data is for
  //	-Keep track of what the highest report is so far
  //	-Check to see when the data ends for a day
  //	-Make a list of 'MaxHzReport's with the date and its corresponding highest Hz
  
}






