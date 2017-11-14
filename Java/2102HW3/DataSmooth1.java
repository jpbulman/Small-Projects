import java.util.LinkedList;

class DataSmooth1 {
  DataSmooth1(){}
  
  public LinkedList<Double> dataSmooth(LinkedList<Show> shows) 
  {
	  LinkedList<Double> avgRunTimes = new LinkedList<Double>();
	
	  for(Show s:shows) {
		  int currNumOfEps = 0;
		  double totalTime = 0;
		  
		  for(Episode e:s.episodes) {
			  totalTime = totalTime + e.runTime;
			  currNumOfEps++;
		  }
		  
		  double avgShow = totalTime/currNumOfEps;
		   
		  avgRunTimes.add(avgShow);
	  }
	  
	  LinkedList<Double> returner = new LinkedList<Double>();
	  
	  int currPos = 0;
	  
	  for(Double d:avgRunTimes) {
		  //-1 is because of 0-based indexing, size might be 4, but position is 3
		  if(currPos==0||currPos==avgRunTimes.size()-1) {returner.add(d);currPos++;}
		  else {returner.add(((avgRunTimes.get(currPos-1))+(avgRunTimes.get(currPos))+(avgRunTimes.get(currPos+1)))/3);currPos++;}
	  }

	  return returner;
  }
  
}