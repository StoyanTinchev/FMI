#include "matrices_manipulation.h"

int main() {
	long int matrix_dimension;
	cin >> matrix_dimension;

	while (matrix_dimension <= 0 || matrix_dimension >= INT32_MAX) {
		cout << "The number must be greater than zero and smaller than 2147483647. Please enter new number: ";
		cin >> matrix_dimension;
	}
	int **mas = create_mas_filled_with_zeros((int) matrix_dimension, (int) matrix_dimension);

	for (int I = 0; I < matrix_dimension; ++I) {
		for (int J = 0; J < matrix_dimension; ++J) {
			if (I == J)
				mas[I][J] = I;
			else if (I < J)
				mas[I][J] = J - I;
			else
				mas[I][J] = I * J;
		}
	}

	print_mas(mas, (int) matrix_dimension, (int) matrix_dimension);
}