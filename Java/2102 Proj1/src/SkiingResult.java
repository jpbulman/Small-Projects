
public class SkiingResult implements IEvent {
	
	double time;
	int position;
	ShootingResult shootingres;
	
	public SkiingResult(double time,int position,ShootingResult shootingres) {
		this.time=time;
		this.position=position;
		this.shootingres=shootingres;
	}
	
	double addShootingPenalties(ShootingResult shoot) {
		this.time=this.time+(20*(20-(shoot.round1.points+shoot.round2.points+shoot.round3.points+
				shoot.round4.points)));
		
		return this.time;
	}
	
	public double PointsEarned() {
		
		if(this.position==1) {return (this.addShootingPenalties(this.shootingres)-10);}
		else if(this.position==2) {return (this.addShootingPenalties(this.shootingres)-7);}
		else if(this.position==3) {return (this.addShootingPenalties(this.shootingres)-3);}
		else {return this.addShootingPenalties(this.shootingres);}
		
	}

	
}
