import java.util.LinkedList;

public class Main {

    public static boolean isPrime(int i,int currDivisor){

        if (i==2){return true;}
        if(i%currDivisor==0){return false;}
        if(currDivisor==2){return true;}
        else return isPrime(i,currDivisor-1);

    }

    public static int Largest(LinkedList<Integer> i){

        int currentLargest = 0;

        for(int j:i){
            if(j>currentLargest){currentLargest=j;}
        }

        return currentLargest;
    }

    public static LinkedList<Integer> primeFactors(int i,int currentCheck,LinkedList<Integer> factors){

        if(i==2){factors.add(2);return factors;}

        if(currentCheck==i){return factors;}

        if(i%currentCheck==0&&isPrime(currentCheck,currentCheck-1)) {

            factors.add(currentCheck);

            if (isPrime((i / currentCheck), (i / currentCheck) - 1)) {
                factors.add((i / currentCheck));
                return factors;
            } else {
                factors.addAll(primeFactors(i / currentCheck, 2, new LinkedList<Integer>()));
                return factors;
            }
        }

        else {primeFactors(i,currentCheck+1,factors);return factors;}

    }


    public static void main(String[] args){
        int Solution = Largest(primeFactors(600851475143,2,new LinkedList<Integer>()));
    }

} 