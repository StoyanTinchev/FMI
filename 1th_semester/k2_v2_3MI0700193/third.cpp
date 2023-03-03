#include <iostream>

bool sumNumbersEqualTarget
	(int numbers[], int target, int index, int sum, int count) {
	if (count == 4) {
		return sum == target;
	}
	if (index == 10) {
		return false;
	}
	return sumNumbersEqualTarget(numbers, target, index + 1, sum + numbers[index], count + 1) ||
		sumNumbersEqualTarget(numbers, target, index + 1, sum, count);
}

int main() {

	int i = 0;
	int *numbers = new int[i + 1];
	int number;
	do {
		std::cin >> number;
		numbers[i] = number;
		i++;
		int *temp = new int[i + 1];
		for (int j = 0; j < i; ++j) {
			temp[j] = numbers[j];
		}
		delete[] numbers;
		numbers = temp;
	} while (std::cin.peek() != '\n');

	int target;
	std::cin >> target;

	std::cout << std::boolalpha << sumNumbersEqualTarget(numbers, target, 0, 0, 0);
	return 0;
}