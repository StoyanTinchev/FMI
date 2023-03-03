#include <iostream>

using namespace std;

int countLetters(char *input, int i, int count) {
	if (input[i] == '\0') {
		return count;
	}
	if (input[i] >= 'A' && input[i] <= 'Z') {
		count++;
	}
	if (input[i] >= 'a' && input[i] <= 'z') {
		count++;
	}
	return countLetters(input, i + 1, count);
}

char *getInput() {
	char *input = new char[1000];
	cin.getline(input, 1000);

	return input;
}

int main() {
	char *input = getInput();

	cout << countLetters(input, 0, 0) << endl;
	delete[] input;
	return 0;
}
