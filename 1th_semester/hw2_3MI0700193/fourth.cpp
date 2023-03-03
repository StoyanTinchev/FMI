#include <iostream>

using namespace std;

double myPow(double pow, int exponent) {
	double res = 1;
	for (int i = 0; i < exponent; ++i) {
		res *= pow;
	}
	return res;
}

int myRound(double number) {
	return number < 0 ? number - 0.5 : number + 0.5;
}

int myFloor(double number) {
	return int(number);
}

int myCeil(double number) {
	if (number / number == 1 || number == 0)
		return (int) number;
	return int(number) + 1;
}

int main() {
	cout << myPow(2, 4) << endl;
	cout << myRound(2.5) << endl;
	cout << myFloor(4.9) << endl;
	cout << myCeil(5.1) << endl;
}
