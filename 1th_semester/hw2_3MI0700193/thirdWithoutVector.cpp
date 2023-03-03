#include <iostream>

using namespace std;

int getMasSize(char *mas) {
	int size = 0;
	while (*mas != '\0') {
		size++;
		mas++;
	}
	return size;
}

void add(char **mas, char newElement) {
	int size = getMasSize(*mas);

//	(size + 2) because of the '\0' and the new element
	char *new_banks = new char[size + 2];

	for (int i = 0; i < size; ++i)
		new_banks[i] = *mas[i];
	new_banks[size] = newElement;
	delete[]*mas;
	*mas = new char[size + 2];
	*mas = new_banks;
}

int main() {
	char *mas = new char[2] {'a'};
	cout << getMasSize(mas) << endl;
	for (int I = 0; I < getMasSize(mas); ++I) {
		cout << mas[I] << " ";
	}


	cout << endl;
	add(&mas, 'b');
	cout << getMasSize(mas) << endl;
	for (int i = 0; i < getMasSize(mas); ++i)
		cout << mas[i] << " ";
}