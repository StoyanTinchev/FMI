#ifndef HW1_3MI0700193_MATRICES_MANIPULATION_H
#define HW1_3MI0700193_MATRICES_MANIPULATION_H
#include <iostream>

using namespace std;

int **create_mas_filled_with_zeros(int rows, int cols) {
	int **array;
	array = new int *[rows];
	for (int i = 0; i < rows; i++)
		array[i] = new int[cols];

	for (int I = 0; I < rows; ++I) {
		for (int J = 0; J < cols; ++J) {
			array[I][J] = 0;
		}
	}
	return array;
}

void print_mas(int **mas, int rows, int cols) {
	for (int I = 0; I < rows; ++I) {
		for (int J = 0; J < cols; ++J) {
			cout << mas[I][J] << " ";
		}
		cout << endl;
	}

}

#endif
