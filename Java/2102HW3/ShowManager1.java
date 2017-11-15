import java.util.LinkedList;

class ShowManager1 {
	
	ShowManager1() {}

	public ShowSummary organizeShows(LinkedList<Show> shows)
	{
		LinkedList<Show> notNight = new LinkedList<Show>();
		
		for(Show view:shows) {
			if(view.broadcastTime >= 2300 || view.broadcastTime < 600) {}
			else {notNight.add(view);}
		}
		
		ShowSummary returnReport = new ShowSummary();
			
		for(Show view:notNight) {
			if(view.broadcastTime >= 0600 && view.broadcastTime < 1700) {returnReport.daytime.add(view);}
			else if(view.broadcastTime >= 1700 && view.broadcastTime < 2300) {returnReport.primetime.add(view);}
			else {}
		}
		
		return returnReport;
	}
	
}
