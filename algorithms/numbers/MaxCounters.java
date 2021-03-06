import java.util.Arrays;

public class MaxCounters {
	
	public static int[] resultingOperation(int numCounters, int[] list) {
		int[] counters = new int[numCounters];
		int maxCounter = 0;
        int previousMaxApplied = 0;
        boolean maxApplied = true;
		for(int i = 0; i < list.length; i++) {
            if(list[i] == numCounters + 1) {
				previousMaxApplied = maxCounter;
				maxApplied = true;
			} else {
                if(maxApplied) {
                	if(counters[list[i] - 1] >= previousMaxApplied) {
                		counters[list[i] - 1] += 1;
                	} else {
                		counters[list[i] - 1] = 1 + previousMaxApplied;
                	}
                } else {
                	counters[list[i] - 1] += 1;
                }
                if(counters[list[i] - 1] > maxCounter) {
					maxCounter = counters[list[i] - 1];
				}
			}
		}
		for(int i = 0; i < numCounters; i++) {
			if(counters[i] < previousMaxApplied) {
				counters[i] = previousMaxApplied;
			}
		}
		return counters;
	}

	public static void main(String[] args) {
		int[] list = { 3, 4, 4, 6, 1, 4, 4 };
		int numCounters = 5;
		System.out.println(Arrays.toString(resultingOperation(numCounters, list)));
	}
}