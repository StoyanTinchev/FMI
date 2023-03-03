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
	Client clients[5];

	for (int i = 0; i < 5; ++i) {
		clients[i] = {
			(double) i,
			{
				{(char) (65 + i)}, {(char) (97 + i)},
			},
		};
		std::cout << clients[i] << std::endl;
	}

	double sum = 0;
	for (auto &client : clients) {
		sum += client.money;
	}
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}
