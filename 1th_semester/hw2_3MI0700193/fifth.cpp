#include <iostream>
#include <cstring>

using namespace std;

char *myStrcpy(char *destination, const char *source) {
	if (destination == NULL) {
		return NULL;
	}

	char *ptr = destination;

	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';

	return ptr;
}

int myStrcmp(const char *str1, const char *str2) {
	while (*str1) {
		if (*str1 != *str2) {
			break;
		}

		str1++;
		str2++;
	}

	return *(const unsigned char *) str1 - *(const unsigned char *) str2;
}

char *myStrchr(char *str, char character) {
	while (*str != character && *str != '\0') {
		str++;
	}
	if (*str == character) {
		return str;
	} else {
		return NULL;
	}
}

char *myStrcat(char *str1, const char *str2) {
	char *ptr = str1 + strlen(str1);

	while (*str2 != '\0') {
		*ptr++ = *str2++;
	}

	*ptr = '\0';
	return str1;
}

int main() {
	char source[] = "something";
	char destination[25];

	cout << myStrcpy(destination, source) << endl;

	char str1[5] = "som1";
	char str2[8] = "som0123";

	cout << myStrcmp(str1, str2) << endl;

	char str[5] = "som";
	char character = 'o';

	cout << *myStrchr(str, character) << endl;


	cout << myStrcat(str1, str2) << endl;
	return 0;
}
