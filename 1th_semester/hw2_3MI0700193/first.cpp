#include <iostream>

using namespace std;

int main() {
	int input;
	cin >> input;

	for (int I = 0; I <= input; ++I) {
		for (int J = 0; J <= input - I; ++J) {
			cout << ' ';
		}
		int middleElements = (2 * I + 1);
		for (int K = 0; K < middleElements; ++K) {
			cout << (K == ((middleElements - 1) / 2) ? '|' : '*');
		}
		cout << endl;
	}
}
