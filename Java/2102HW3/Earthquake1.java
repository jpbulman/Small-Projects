import java.util.LinkedList;

class Earthquake1 {
  Earthquake1(){}

  // checks whether a datum is a date
  boolean isDate(double anum) { return (int)anum > 10000000; }
  // extracts the month from an 8-digit date
  int extractMonth(double dateNum) { return ((int)dateNum % 10000) / 100; }
 
  public LinkedList<MaxHzReport> dailyMaxForMonth(LinkedList<Double> data, int month) {
	  LinkedList<MaxHzReport> returnList = new LinkedList<MaxHzReport>();
	  
	  LinkedList<Double> monthData = new LinkedList<Double>();
	  
	  boolean keepAdding = false;
	  
	  for(double d:data) {
		  if(isDate(d)) {if(extractMonth(d)==month) {monthData.add(d);keepAdding=true;} else {keepAdding=false;}}
		  else if(keepAdding) {monthData.add(d);}
	  }
	  
	  //System.out.println(monthData);
	  
	  double currHighest = 0;
	  double currDate = 0;
	  int Pos = 0;
	  
	  for(double d:monthData) {
		  if((currHighest < d)&&(!isDate(d))) {currHighest = d;}
		  
		  if(isDate(d)||(Pos==monthData.size()-1)) {
			if(Pos==0) {currDate=d;}
			else {MaxHzReport entry = new MaxHzReport(currDate,currHighest);returnList.add(entry);currDate = d;}
		  }
		  Pos++;
	  }
	  
	  		  
   return returnList;
  }
  
}  

