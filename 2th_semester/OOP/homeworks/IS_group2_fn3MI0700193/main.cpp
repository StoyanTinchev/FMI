#include "OopCoin/oopcoin.hpp"

int main() {
	OOPCoin oopCoin;

	char command[128];
	while (true) {
		std::cout << "> ";
		std::cout.flush();
		std::cin >> command;

		if (strcmp(command, "create-user") == 0) {
			char name[128];
			double investment;
			std::cin >> name >> investment;
			oopCoin.createUser(0, name, investment); // Use system user ID (0) as the creator

		} else if (strcmp(command, "remove-user") == 0) {
			char name[128];
			std::cin >> name;
			oopCoin.removeUser(name);

		} else if (strcmp(command, "send-coins") == 0) {
			unsigned senderId, receiverId;
			double coins;
			std::cin >> senderId >> receiverId >> coins;
			oopCoin.sendCoins(senderId, receiverId, coins);

		} else if (strcmp(command, "verify-transactions") == 0) {
			bool valid = oopCoin.verifyTransactions();
			std::cout << "Transactions are " << (valid ? "valid" : "invalid") << std::endl;

		} else if (strcmp(command, "wealthiest-users") == 0) {
			int countEntries;
			std::cin >> countEntries;
			oopCoin.wealthiestUsers(countEntries);

		} else if (strcmp(command, "biggest-blocks") == 0) {
			int countEntries;
			std::cin >> countEntries;
			oopCoin.biggestBlocks(countEntries);

		} else if (strcmp(command, "exit") == 0) {
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}

	return 0;
}
