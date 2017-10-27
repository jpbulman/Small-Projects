
public class Athlete {

	public ShootingResult shootres;
	public SkiingResult skires;
	
	public Athlete(ShootingResult shootres,SkiingResult skires) {
		this.shootres=shootres;
		this.skires=skires;
	}
	
	Athlete betterSkiier(Athlete otherAth) {
		if(this.skires.PointsEarned() < otherAth.skires.PointsEarned()) {return this;}
		else {return otherAth;}
	}
	
	boolean hasBeaten(Athlete otherAth) {
		return (this.shootres.PointsEarned() > otherAth.shootres.PointsEarned())||
				(this.skires.PointsEarned() < otherAth.skires.PointsEarned());
	}
	
}
