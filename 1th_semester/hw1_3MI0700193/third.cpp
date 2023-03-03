#include "matrices_manipulation.h"

#define POSITION_COLS 2
#define POSITION_ROWS 3

void fill_positions(int **positions, int row_idx, int valA, int valB) {
	positions[row_idx][0] = valA;
	positions[row_idx][1] = valB;
}

void print_path(int *curr_row, int *curr_col, int finish_row, int finish_col) {
	if (*curr_col > finish_col) {
		while (*curr_col > finish_col) {
			cout << *curr_row << ", " << *curr_col << endl;
			(*curr_col)--;
		}
	} else {
		while (*curr_col < finish_col) {
			cout << *curr_row << ", " << *curr_col << endl;
			(*curr_col)++;
		}
	}
	if (*curr_row > finish_row) {
		while (*curr_row > finish_row) {
			cout << *curr_row << ", " << *curr_col << endl;
			(*curr_row)--;
		}
	} else {
		while (*curr_row < finish_row) {
			cout << *curr_row << ", " << *curr_col << endl;
			(*curr_row)++;
		}
	}
}

int main() {
	int row, col;
	cin >> row >> col;

	while ((row+col) < 3){
		cout << "There must be at least 3 places (for the key, the phone and the jacket)!";
		cout << "Please enter new matrix dimensions: ";
		cin >> row >> col;
	}

	if (row > 10 || col > 10)
		cout << "Happy input!" << endl;

	int input_validation = 0;
	int mas[row][col];
	for (int I = 0; I < row; ++I) {
		for (int J = 0; J < col; ++J) {
			cin >> mas[I][J];
			if (mas[I][J] != 0)
				input_validation++;
		}
	}

	while (input_validation != 3) {
		cout << "The matrix should have places for the key, the phone and the "
		        "jacket whose must be indicated with numbers (1, 2, and 3 respectively)!" << endl;
		cout << "Please enter the matrix again: " << endl;
		input_validation = 0;
		for (int I = 0; I < row; ++I) {
			for (int J = 0; J < col; ++J) {
				cin >> mas[I][J];
				if (mas[I][J] != 0)
					input_validation++;
			}
		}
	}

	int me_row, me_col;
	cin >> me_row >> me_col;
	while (me_row > row || me_col > col) {
		cout << "Please enter valid matrix place indexes: ";
		cin >> me_row >> me_col;
	}

	int **positions = create_mas_filled_with_zeros(POSITION_ROWS, POSITION_COLS);

	int positions_counter = 0;
	for (int I = 0; I < row; ++I) {
		for (int J = 0; J < col; ++J) {
			if (mas[I][J] != 0) {
				fill_positions(positions, positions_counter, I, J);
				positions_counter++;
			}
		}
	}

	for (int I = 0; I < POSITION_ROWS; ++I) {
		print_path(&me_row, &me_col, positions[I][0], positions[I][1]);
	}
	cout << me_row << ", " << me_col << endl;
}