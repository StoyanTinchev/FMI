#include <iostream>
#include <cstring>

using namespace std;

char *strcat(char *str1, const char *str2) {
	char *ptr = str1 + strlen(str1);

	while (*str2 != '\0') {
		*ptr++ = *str2++;
	}

	*ptr = '\0';
	return str1;
}

int getMasSize(char *mas) {
	int size = 0;
	while (*mas != '\0') {
		size++;
		mas++;
	}
	return size;
}

int main() {
	int N;
	cin >> N;
	char **passwords = new char *[N];
	for (int i = 0; i < N; ++i) {
		passwords[i] = new char[1]{'\0'};

		char *input = new char[9];
		int I = 0;
		do {
			cin >> input[I];
			I++;
		} while (cin.peek() != '\n');

		do {
			passwords[i] = strcat(passwords[i], input);
		} while (cin.peek() != '\n');
	}

	int mas[N];
	for (int i = 0; i < N; ++i) {
		int count = 0;
		for (int j = 0; j < getMasSize(passwords[i]); ++j) {
			if (passwords[i][j] >= 'A' && passwords[i][j] <= 'Z') {
				count++;
			}
		}
		mas[i] = count;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (mas[i] == mas[j]) {
				cout << passwords[i] << passwords[j] << endl;
			}
		}
	}
	return 0;
}
