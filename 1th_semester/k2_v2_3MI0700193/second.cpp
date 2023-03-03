#include <iostream>

using namespace std;

void printWordsBackwards(char *input) {
	int count = 0;
	int max = 0;
	int maxIndex = 0;
	int index = 0;
	int wordLetters = 0;
	int i = 0;
	while (input[i] != '\0') {
		if (input[i] == ' ') {
			count++;
			if (max < index) {
				max = index;
				maxIndex = (i - (wordLetters - index)) - index;
			}
			index = 0;
			wordLetters = 0;
		} else {
			wordLetters++;
			if ((input[i] >= 'A' && input[i] <= 'Z') ||
				(input[i] >= 'a' && input[i] <= 'z')) {
				index++;
			}
		}
		i++;
	}
	count++;
	if (max < index) {
		max = index;
		maxIndex = (i - (wordLetters - index)) - index;
	}
	cout << "Number of words: " << count << endl;
	if ((maxIndex + max - 1) == (maxIndex - 1)) {
		cout << "There are no words in the input.";
		return;
	}

	cout << "Longest word: ";
	for (int j = (maxIndex + max - 1); j > (maxIndex - 1) ; --j) {
		cout << input[j];
	}

}

int main() {
	char sentence[1000];
	cin.getline(sentence, 1000);
	printWordsBackwards(sentence);
	return 0;
}