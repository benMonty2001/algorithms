public class NumWords {

	public static int maxWords(String alphabetSoup, String[] words) {
		char[] letters = alphabetSoup.toCharArray();
		int max = Integer.MIN_VALUE;

		for(int i = 0; i < words.length; i++) {
			char[] word = words[i].toCharArray();
			char[] constructWord = new char[word.length];
			int numLettersFound = 0;
			int numTimesCurrentWordFound = 0;

			for(int j = 0; j < letters.length; j++) {
				for(int k = 0; k < word.length; k++) {
					if(letters[j] == word[k] && constructWord[k] != letters[j]) {
						constructWord[k] = letters[j];
						numLettersFound++;
						break;
					}
				}
				if(numLettersFound == word.length) {
					numLettersFound = 0;
					numTimesCurrentWordFound++;
					constructWord = new char[word.length];
				}
			}

			if(numTimesCurrentWordFound > max) {
				max = numTimesCurrentWordFound;
			}
		}
		return max;
	}

	public static void main(String[] args) {
		String test1 = "billobbllbibillbob"; // ---> 3
		String test2 = "b"; // ---> 0
		String test3 = "bbbbbbllllllllllllllllllllllllllllli"; // ---> 1

		String[] words = { "bob", "bill" };

		System.out.println("test1 = " + maxWords(test1, words));
		System.out.println("test2 = " + maxWords(test2, words));
		System.out.println("test3 = " + maxWords(test3, words));
	}
}