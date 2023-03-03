#include <iostream>

struct Address {
	char city[100];
	int zip;
	char street[200];
	int num;
	char add;
};

struct Date {
	unsigned day : 5;
	unsigned mnth : 4;
	unsigned year : 23;
};

struct Student {
	Address addr;
	char *name;
	Date date;
	float score;
	char subj;
};

int main() {
	std::cout << sizeof(Student) << std::endl;
	std::cout << sizeof(Date) << std::endl;
	return 0;
}
