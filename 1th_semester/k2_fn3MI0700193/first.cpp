#include <iostream>

bool cmpMassives(const int *arr1, const int *arr2, int size) {
	int checkEqual = 0;
	int checkEqualReversed = 0;
	for (int i = 0; i < size; i++) {
		if (arr1[i] == arr2[i]) {
			checkEqual++;
		}
		if (arr1[i] == arr2[size - i - 1]) {
			checkEqualReversed++;
		}
	}
	if (checkEqual == size || checkEqualReversed == size) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;
	int **matrix = new int *[N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M];
		for (int j = 0; j < M; j++) {
			std::cin >> matrix[i][j];
		}
	}

	int **transposedMatrix = new int *[M];
	for (int i = 0; i < M; i++) {
		transposedMatrix[i] = new int[N];
		for (int j = 0; j < N; j++) {
			transposedMatrix[i][j] = matrix[j][i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (cmpMassives(transposedMatrix[i], transposedMatrix[j], M)) {
				std::cout << i << " " << j << std::endl;
			}
		}
	}

	return 0;
}
