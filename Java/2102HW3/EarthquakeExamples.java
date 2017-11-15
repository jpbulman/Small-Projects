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
//Test the code's performance when the only report to return stems from the last 2 doubles
  @Test
  public void instructorTestEQ() { 
    assertEquals(NovReports, 
                 E1.dailyMaxForMonth(threeDates, 11));
  }
  //Test the code's performance when it must return two reports
  @Test
  public void studentTestEq() {
	  NovReports.add(new MaxHzReport(20151102.0,8.0));
	  threeDates.add(20151102.0);
	  threeDates.add(8.0);
	  assertEquals(NovReports, E1.dailyMaxForMonth(threeDates, 11));
  }
  //Test the code's performance when there are multiple possible reports for one day
  @Test
  public void StudentTestb() {
	  threeDates.add(2.2);
	  assertEquals(NovReports, E1.dailyMaxForMonth(threeDates, 11));
  }
  //Test the code's performance when extraneous dates are provided at the end of the data
  @Test
  public void StudentTestc() {
	  threeDates.add(20151202.0);
	  assertEquals(NovReports, E1.dailyMaxForMonth(threeDates, 11));
	  }
  //Test the code's handling of an list that lacks relevant data
  @Test
  public void StudentTestd() {
  LinkedList<MaxHzReport> boring = new LinkedList<MaxHzReport>();
  LinkedList<Double> useless = new LinkedList<Double>();
  useless.add(20150101.0);
  useless.add(2.0);
  	assertEquals(boring, E1.dailyMaxForMonth(useless, 11));
  }
}

//The subtasks included
/* Calculate the average run time for each show
 * Place the average of the first show at the first position in the list
 * Calculate each smoothed data point
 * Place each smoothed data point at its correct place in the list
 * Place the average of the last show in the final list position
 * Return the list
 */








