public class NumDivisible2 {
    public static int numDivisible(int A, int B, int K) {
        int numDiv = 0;
        
        if(K == 0) {
            return -1;
        }

        if(A == B && A % K == 0) {
            return 1;
        }

        if(A % K == 0) {
            numDiv += 1;
        }

        numDiv += (B/K) - (A/K);

        return numDiv;
    }

    public static void printDiv(int lowerBound, int upperBound, int factor) {
        if(factor == 0) {

             System.out.println("[" + 
                                 lowerBound + ", " +
                                 upperBound + ", " +
                                 factor            + 
                           "] = " + "<---- INVALID INPUT. DIVISION BY ZERO");    
            return;
        }

        System.out.println("[" + 
                                 lowerBound + ", " +
                                 upperBound + ", " +
                                 factor            + 
                           "] = " + numDivisible(lowerBound, upperBound, factor));    
    }

    public static void main(String args[]) {
        printDiv(0, 11, 2);
        printDiv(0, 2000000, 2000000);
        printDiv(0, 0, 0);
        printDiv(3, 11, 2);
        printDiv(2, 16, 3);
    }
}