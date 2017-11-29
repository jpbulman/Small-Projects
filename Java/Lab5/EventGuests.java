
public class EventGuests {
	
	ISet guests;
	
	EventGuests(ISet guests){
		this.guests=guests;
	}
	
	void addGuest(String newGuestName) {
		this.guests.addElt(newGuestName);
	}

	boolean isComing(String guestName) {
		return this.guests.hasElt(guestName);
	}
	
	int numGuests() {
		return this.guests.size();
	}
	
}

