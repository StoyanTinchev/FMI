#include <iostream>

using namespace std;

void santaCalculator(int houses, int *chimnees, double stomachSize) {
	int foodEaten = 0, visitedHouses = 0;
	for (int I = 0; I < houses; ++I) {
		if (double(*(chimnees) / 2) >= stomachSize) {
			foodEaten += 20;
			visitedHouses++;
			stomachSize += 0.5;
		}
		chimnees++;
	}
	cout << visitedHouses << " " << foodEaten << endl;
}

int main() {
	int houses;
	cin >> houses;
	int *chimnees = new int[houses];
	for (int I = 0; I < houses; ++I) {
		cin >> chimnees[I];
	}
	double stomachSize;
	cin >> stomachSize;

	santaCalculator(houses, chimnees, stomachSize);
	return 0;
}
