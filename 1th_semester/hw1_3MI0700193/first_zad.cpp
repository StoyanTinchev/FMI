#include "matrices_manipulation.h"

int floorSqrt(int x) {
	if (x == 0 || x == 1)
		return x;

	int i = 1, result = 1;
	while (result <= x) {
		i++;
		result = i * i;
	}
	return i - 1;
}

void switch_direction(char *direction) {
	char options[6] = "rdlur";
	for (int I = 0; I < 4; ++I) {
		if (options[I] == *direction) {
			*direction = options[I + 1];
			return;
		}
	}
}

int main() {
	long int num;
	cin >> num;

	while (num <= 0 || num >= INT32_MAX) {
		cout << "The number must be greater than zero and smaller than 2147483647. Please enter new number: ";
		cin >> num;
	}

	int sqrt_num = floorSqrt((int) num);
	int matrix_dimension = (sqrt_num * sqrt_num < num) ?
	                       (sqrt_num + 1) : (sqrt_num);
	int **mas = create_mas_filled_with_zeros(matrix_dimension, matrix_dimension);

	int row = 0, col = 0;
//	-1 защото трябва да се брои първата итерация
	int must_switch_count = -1;

	int must_switch = 1, matrix_dimension_copy = matrix_dimension;
	char direction = 'r';
	for (int I = 1; I <= num; ++I) {
		mas[row][col] = I;
		switch (direction) {
		case 'r': col++;
			break;
		case 'd': row++;
			break;
		case 'l': col--;
			break;
		case 'u': row--;
			break;
		}
		must_switch++;
		if (must_switch == matrix_dimension_copy) {
			switch_direction(&direction);
			must_switch_count++;
			must_switch = 1;
			if (must_switch_count == 2) {
				matrix_dimension_copy--;
				must_switch_count = 0;
			}
		}
	}
	print_mas(mas, matrix_dimension, matrix_dimension);
}
