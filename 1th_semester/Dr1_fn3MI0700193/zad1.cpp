#include <iostream>

using namespace std;

// program that count the digits of a number
int main() {
	int n, count = 0;
	cin >> n;
	while (n > 0) {
		n /= 10;
		count++;
	}
	cout << count << endl;
	return 0;
}
