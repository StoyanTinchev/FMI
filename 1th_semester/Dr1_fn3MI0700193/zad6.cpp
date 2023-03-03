#include <iostream>

using namespace std;

int main() {
	int num, reversedN = 0, remainder;
	cin >> num;
	int originalN = num;
	while (num != 0) {
		remainder = num % 10;
		reversedN = reversedN * 10 + remainder;
		num /= 10;
	}
	if (originalN == reversedN)
		cout << "Number is palindrome" << endl;
	else
		cout << "Number is not palindrome" << endl;
	return 0;
}