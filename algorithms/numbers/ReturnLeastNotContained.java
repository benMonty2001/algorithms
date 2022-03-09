//returns the minimum value > 0 that is not contained in the array.
import java.util.Arrays;
import java.lang.Math;


public class ReturnLeastNotContained {

	public int solution(int[] A) {
        if(A.length == 0) {
            return 0;
        }
        if(A.length == 1) {
            if(A[0] < 1 || A[0] > 1) {
                return 1;
            } else {
                return A[0] + 1;
            }
        }
        int[] possibles = new int[A.length];

        for(int i = 0; i < A.length; i++) {
            if(A[i] > 0 && A[i] <= A.length) {
                possibles[A[i] - 1] = A[i];
            }
        }

        for(int i = 0; i < possibles.length; i++) {
            if(possibles[i] == 0) {
                return i + 1;
            } else {
                continue;
            }
        }
        return possibles[possibles.length - 1] + 1;
    }
}