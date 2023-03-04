#include <iostream>

struct Person {
	char firstName[100];
	char lastName[100];

	friend std::ostream &operator<<(std::ostream &out, const Person &person) {
		out << "First name: " << person.firstName << std::endl;
		out << "Last name: " << person.lastName << std::endl;
		return out;
	}
};

struct Client {
	double money;
	Person person;

	friend std::ostream &operator<<(std::ostream &out, const Client &client) {
		out << client.person;
		out << "Money: " << client.money << std::endl;
		return out;
	}
};

int main() {
	Client clients[2];

//	 input of the clients information
	for (auto &client : clients) {
		std::cout << "Client " << &client - clients + 1 << std::endl;
		std::cout << "First name: ";
		std::cin >> client.person.firstName;
		std::cout << "Last name: ";
		std::cin >> client.person.lastName;
		std::cout << "Money: ";
		std::cin >> client.money;
		std::cout << std::endl;
	}

	double sum = 0;
	for (auto &client : clients) {
		sum += client.money;
	}
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}
