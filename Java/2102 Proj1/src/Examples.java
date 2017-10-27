import static org.junit.Assert.*;
import org.junit.Test;

public class Examples {

    public Examples(){}
    
    
    // This shows what a test case looks like
    @Test 
    public void simpleCheck() {
	assertEquals(4, 4);
    }
    
    ShootingRound joe1 = new ShootingRound(4);
    ShootingRound joe2 = new ShootingRound(5);
    ShootingRound joe3 = new ShootingRound(1);
    ShootingRound joe4 = new ShootingRound(2);
    
    ShootingResult JoesShoot = new ShootingResult(joe1,joe2,joe3,joe4);
    
    SkiingResult JoesSkii = new SkiingResult(4.5,15,JoesShoot);
    		
    Athlete Joe = new Athlete(JoesShoot,JoesSkii);
    
    @Test
    public void pointsEarnShootTest() {
    	assertEquals(12.0, Joe.shootres.PointsEarned(),0.01);
    }
    
    @Test
    public void pointsEarnSkiTest() {
    	assertEquals(164.5, Joe.skires.PointsEarned(),0.01);
    }
    
  
}