import java.util.Arrays;

public class ReturnLeastAnagram {
	
	public static int getLeast(Integer anagram) {
		String list = Integer.toString(anagram);
		int[] convertedList = new int[list.length()]; 

		for(int i = 0; i < list.length(); i++) {
			convertedList[i] = list.charAt(i) - '0';
		}

		Arrays.sort(convertedList);

		String finalList = "";

		for(int i = 0; i < convertedList.length; i++) {
			finalList += Integer.toString(convertedList[i]);
		}		

		return Integer.parseInt(finalList);
	}

	public static void main(String[] args) {
		int test1 = 354; 
		int test2 = 535; 
		int test3 = 101; 

		System.out.println(getLeast(test1)); // --> 345
		System.out.println(getLeast(test2)); // --> 355
		System.out.println(getLeast(test3)); // --> 11
	}
}