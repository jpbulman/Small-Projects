import java.util.LinkedList;

public class Main {

    static boolean endDigits(int i){

        String iS = String.valueOf(i);
        String end = iS.substring(1,iS.length());

        int endD = Integer.parseInt(end);

        if(endD==0){return false;}

        System.out.println(i+" "+endD);
        System.out.println(i/endD);
        System.out.println(3/4);
        //return ((i/endD)==(floor(i/endD)));
        return true;
    }

    public static void main(String[] args){

        LinkedList<Integer> returner = new LinkedList<Integer>();

        System.out.println(endDigits(998));

    }

} 
    