import java.util.LinkedList;

public class Main {

    public static boolean isPrime(int i,int currDivisor){

        if(i%currDivisor==0){return false;}
        if(currDivisor==2){return true;}
        else return isPrime(i,currDivisor-1);

    }

    public static int multiplyAll(LinkedList<Integer> list){

        int currentProduct = 1;

        for (int i:list){
            currentProduct*=i;
        }

        return currentProduct;
    }

    public static LinkedList<Integer> primeFactors(int i,int currentCheck,LinkedList<Integer> factors){

        if(currentCheck==i){return factors;}

        if(i%currentCheck==0&&isPrime(currentCheck,currentCheck-1)) {

            factors.add(currentCheck);

            if (isPrime((i / currentCheck), (i / currentCheck) - 1)) {
                factors.add((i / currentCheck));
                return factors;
            } else {
                factors.addAll(primeFactors(i / currentCheck, 2, factors));
                return factors;
            }
        }

        else {primeFactors(i,currentCheck+1,factors);return factors;}

    }


    public static void main(String[] args){
        System.out.println(primeFactors(6,2,new LinkedList<Integer>()));
    }

} 