#include <iostream>
#include <valarray>

using namespace std;

bool isPrime(int n)
{
	if (n == 2 || n == 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i <= sqrt(n); i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

int main() {
	int startSeq, endSeq;
	cout << "Enter start sequence: ";
	cin >> startSeq;
	if (startSeq <= 1) {
		cout << "Prime numbers should start from 1, please enter new start num:";
		cin >> startSeq;
	}

	cout << "Enter end sequence: ";
	cin >> endSeq;
	cout << endl;

	if (endSeq < startSeq) {
		startSeq = startSeq + endSeq;
		endSeq = startSeq - endSeq;
		startSeq = startSeq - endSeq;
	}

	cout << "Prime numbers between " << startSeq << " and " << endSeq << " are: ";
	for (int i = startSeq; i <= endSeq; i++) {
		if (isPrime(i))
			cout << i << " ";
	}
}