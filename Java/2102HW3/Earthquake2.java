import java.util.LinkedList;

class Earthquake2 {
  Earthquake2(){}

  // checks whether a datum is a date
  boolean isDate(double anum) { return (int)anum > 10000000; }
  // extracts the month from an 8-digit date
  int extractMonth(double dateNum) { return ((int)dateNum % 10000) / 100; }
 
  //Consumes outputs from an earthquake monitor and a month and returns a report
  // of the highest seismic activity from that month
  public LinkedList<MaxHzReport> dailyMaxForMonth(LinkedList<Double> data,
                                                  int month) {
   LinkedList<MaxHzReport> dailyMaxReport = new LinkedList<MaxHzReport>();
   for(int i = 0; i < data.size() -1; i ++) {
	   if(extractMonth(data.get(i)) == month) {
		   double max = 0;
		   for(int j = i +1; j < data.size() && isDate(data.get(j)) == false; j ++) {
			   if (data.get(j) > max) {
				   max = data.get(j);
			   }
		   }
		   dailyMaxReport.add(new MaxHzReport(data.get(i), max));
	   }
   }
return dailyMaxReport;
  
}  
  }

