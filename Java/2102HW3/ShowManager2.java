import java.util.LinkedList;

class ShowManager2 {
	
	ShowManager2() {}

	public ShowSummary organizeShows(LinkedList<Show> shows) {
		ShowSummary showsum = new ShowSummary();
		for (Show s : shows) {
			if(s.broadcastTime >= 1700 && s.broadcastTime < 2300) {
			showsum.primetime.add(s);
	}
			else if ( s.broadcastTime >= 600 && s.broadcastTime < 1700) {
				showsum.daytime.add(s);
			}
	}
	return showsum;
}
}