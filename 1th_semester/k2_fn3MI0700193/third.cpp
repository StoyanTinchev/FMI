#include <iostream>
#include <cmath>

using namespace std;

void printBoolMasAttractions(const int *mas, int size) {
	for (int i = 0; i < size; ++i) {
		cout << mas[i];
	}
	cout << endl;
}

void powerSet(int money, int attractions, const int *attractionCosts) {
	int powSetSize = pow(2, attractions);
	for (int i = 0; i < powSetSize; ++i) {
		int *setIdx = new int[attractions];
		for (int j = 0; j < attractions; ++j) {
			if (i & (1 << j)) {
				setIdx[j] = 1;
			} else {
				setIdx[j] = 0;
			}
		}
		int moneyCost = 0;
		for (int I = 0; I < attractions; ++I) {
			if (setIdx[I])
				moneyCost += attractionCosts[I];
		}
		if (money >= moneyCost)
			printBoolMasAttractions(setIdx, attractions);
	}
}

int main() {
	int money, attractions;
	cin >> money >> attractions;

	if (attractions > 24 || attractions < 1) {
		cout << "Attractions must be less than 25. Enter again: ";
		cin >> attractions;
	}

	int *attractionCosts = new int[attractions];
	for (int i = 0; i < attractions; i++) {
		cin >> attractionCosts[i];
	}

	int *attractionMas = new int[attractions];
	for (int I = 0; I < attractions; ++I) {
		attractionMas[I] = 0;
	}
	powerSet(money, attractions, attractionCosts);

	return 0;
}