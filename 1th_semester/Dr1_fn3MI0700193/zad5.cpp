#include <iostream>

using namespace std;

#define CELSIUS(x) (x - 32) * 5 / 9
#define KELVIN(x) CELSIUS(x) + 273.15

std::ostream &operator<<(std::ostream &os, const char *str) {
	cout.precision(2);
	return std::operator<<(os, str) << fixed;
}

int main() {
	double fahrenheitNum;
	cout << "Enter fahrenheit degree: ";
	cin >> fahrenheitNum;
	char choice;
	cout << "Do you want to convert to celsius, kelvin or both? (c/k/a): ";
	cin >> choice;

	switch (choice) {
	case 'c': cout << "Celsius: " << CELSIUS(fahrenheitNum) << endl;
		break;
	case 'k': cout << "Kelvin: " <<  KELVIN(fahrenheitNum) << endl;
		break;
	case 'a': cout << "Celsius: " << CELSIUS(fahrenheitNum) << endl;
		cout << "Kelvin: " <<  KELVIN(fahrenheitNum) << endl;
		break;
	default: cout << "Invalid choice!" << endl;
	}
}