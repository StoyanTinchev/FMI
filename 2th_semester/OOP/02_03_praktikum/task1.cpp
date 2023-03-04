#include <iostream>

struct Product {
	char description[32];  // описание на изделие
	int partNum;           // номер на изделие
	double cost;           // цена на изделие

//	predefine cout (<<) operator
	friend std::ostream &operator<<(std::ostream &os, const Product &p);
};

// overload cout (<<) operator
std::ostream &operator<<(std::ostream &os, const Product &p) {
	os << "Description: " << p.description << std::endl;
	os << "Part number: " << p.partNum << std::endl;
	os << "Cost: " << p.cost << std::endl;
	return os;
}

int main() {
	Product p1 = {"screw-driver", 456, 5.50};
	Product p2 = {"hammer", 324, 8.20};

	std::cout << p1 << std::endl << p2 << std::endl;

	Product mas[10];
	for (auto & item : mas) {
		item = {};
	}

	Product mas2[5] = {
		{"screw-driver", 456, 5.50},
		{"hammer", 324, 8.20},
		{"socket", 458, 5.75},
		{"pilier", 929, 10.50},
		{"hand-saw", 536, 7.45}
	};

	for (auto & item : mas2) {
		std::cout << item << std::endl;
	}

	return 0;
}