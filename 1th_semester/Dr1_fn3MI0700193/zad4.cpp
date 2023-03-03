#include <iostream>

using namespace std;

int main() {
	int num;
	char charA, charB;
	cout << "Enter symbols count: ";
	cin >> num;
	cout << "Enter first symbol: ";
	cin >> charA;
	cout << "Enter second symbol: ";
	cin >> charB;

	for (int I = 1; I < num; ++I) {
		for (int K = 0; K < I; ++K) {
			cout << charA;
		}
		for (int J = 0; J < num - I; ++J) {
			cout << charB;
		}
		cout << endl;
	}
}