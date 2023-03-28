#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>

class OOPCoin {
public:
	OOPCoin() {
		loadData();

		if (usersSize == 0) {
			createUser(0, "System User", 0);
		}
	}

	~OOPCoin() {
		saveData();
		delete[] users;
		delete[] blocks;
	}

	void createUser(unsigned creatorId, const char *name, double investment) {
		if (creatorId != systemUserId) {
			std::cerr << "Only the system user can create other users." << std::endl;
			return;
		}

		User newUser{usersSize, name};

		addUser(newUser);
		sendCoins(systemUserId, newUser.id, investment * 420);
	}

	void removeUser(const char *name) {
		int userIdx = -1;
		for (int i = 0; i < usersSize; i++) {
			if (strcmp(users[i].name, name) == 0) {
				userIdx = i;
				break;
			}
		}

		if (userIdx != -1) {
			sendCoins(users[userIdx].id, 0, getBalance(users[userIdx].id));
			for (int i = userIdx; i < usersSize - 1; i++) {
				users[i] = users[i + 1];
			}
			usersSize--;
		}
	}

	void sendCoins(unsigned senderId, unsigned receiverId, double coins) {
		Transaction transaction{senderId, receiverId, coins};

		addTransaction(transaction);
	}

	bool verifyTransactions() {
		for (int i = 1; i < blocksSize; i++) {
			if (blocks[i].prevBlockId != blocks[i - 1].id ||
				blocks[i].prevBlockHash != blocks[i - 1].computeBlockHash() ||
				blocks[i].validTransactions < 1) {
				return false;
			}
		}

		return true;
	}

	void wealthiestUsers() {
		struct UserBalance {
			unsigned id;
			double balance;
		} userBalances[1000];

		for (int i = 0; i < usersSize; i++) {
			userBalances[i].id = users[i].id;
			userBalances[i].balance = getBalance(users[i].id);
		}

		std::sort(userBalances, userBalances + usersSize, [](const UserBalance &a, const UserBalance &b) {
		  return a.balance > b.balance;
		});

		char fileName[128];
		snprintf(fileName, sizeof(fileName), "wealthiest-users-%lld.txt", static_cast<long long>(time(nullptr)));

		FILE *file = fopen(fileName, "w");

		for (int i = 0; i < usersSize; i++) {
			std::cout << users[userBalances[i].id].name << " " << userBalances[i].balance << std::endl;
			fprintf(file, "%s, %lf\n", users[userBalances[i].id].name, userBalances[i].balance);
		}

		fclose(file);
	}

	void biggestBlocks() {
		struct BlockAmount {
			unsigned id;
			double amount;
		} blockAmounts[blocksSize];

		for (int i = 0; i < blocksSize; i++) {
			blockAmounts[i].id = blocks[i].id;
			blockAmounts[i].amount = 0;

			for (int j = 0; j < blocks[i].validTransactions; j++) {
				blockAmounts[i].amount += blocks[i].transactions[j].coins;
			}
		}

		std::sort(blockAmounts, blockAmounts + blocksSize, [](const BlockAmount &a, const BlockAmount &b) {
		  return a.amount > b.amount;
		});

		char fileName[128];
		snprintf(fileName, sizeof(fileName), "biggest-blocks-%lld.txt", static_cast<long long>(time(nullptr)));

		FILE *file = fopen(fileName, "w");

		for (int i = 0; i < blocksSize; i++) {
			std::cout << blockAmounts[i].id << " " << blockAmounts[i].amount << std::endl;
			fprintf(file, "%u, %lf\n", blockAmounts[i].id, blockAmounts[i].amount);
		}

		fclose(file);
	}

private:
	static unsigned computeHash(const unsigned char *memory, int length) {
		unsigned hash = 0xbeaf;

		for (int c = 0; c < length; c++) {
			hash += memory[c];
			hash += hash << 10;
			hash ^= hash >> 6;
		}

		hash += hash << 3;
		hash ^= hash >> 11;
		hash += hash << 15;
		return hash;
	}

	struct User {
		char name[128];
		unsigned id;

		User() = default;

		User(unsigned int id, const char *new_name) : id(id) {
			strncpy(name, new_name, sizeof(name) - 1);
			name[sizeof(name) - 1] = '\0';
		}
	} *users;

	struct Transaction {
		unsigned sender;
		unsigned receiver;
		double coins;
		long long time;

		Transaction() = default;

		Transaction(unsigned int Sender, unsigned int Receiver, double Coins) : sender(Sender), receiver(Receiver), coins(Coins) {
			time = static_cast<long long>(std::time(nullptr));
		}
	};

	struct TransactionBlock {
		unsigned id;
		unsigned prevBlockId;
		unsigned prevBlockHash;
		int validTransactions;
		Transaction transactions[16];

		TransactionBlock() = default;

		TransactionBlock(unsigned int Id, unsigned int PrevBlockId, unsigned int PrevBlockHash, int ValidTransactions)
			: id(Id), prevBlockId(PrevBlockId), prevBlockHash(PrevBlockHash), validTransactions(ValidTransactions) {}

		unsigned computeBlockHash() {
			return computeHash(reinterpret_cast<unsigned char *>(this), sizeof(TransactionBlock));
		}
	} *blocks;

	unsigned usersSize;
	unsigned usersCapacity;
	unsigned blocksSize;
	unsigned blocksCapacity;
	const unsigned systemUserId = 0;

	void addUser(const User &user) {
		if (usersSize == usersCapacity) {
			usersCapacity *= 2;
			User *newUsers = new User[usersCapacity];
			std::copy(users, users + usersSize, newUsers);
			delete[] users;
			users = newUsers;
		}
		users[usersSize++] = user;
	}

	void addTransactionBlock(const TransactionBlock &block) {
		if (blocksSize == blocksCapacity) {
			blocksCapacity *= 2;
			TransactionBlock *newBlocks = new TransactionBlock[blocksCapacity];
			std::copy(blocks, blocks + blocksSize, newBlocks);
			delete[] blocks;
			blocks = newBlocks;
		}
		blocks[blocksSize++] = block;
	}

	double getBalance(unsigned userId) {
		double balance = 0;
		for (int i = 0; i < blocksSize; i++) {
			for (int j = 0; j < blocks[i].validTransactions; j++) {
				if (blocks[i].transactions[j].sender == userId) {
					balance -= blocks[i].transactions[j].coins;
				} else if (blocks[i].transactions[j].receiver == userId) {
					balance += blocks[i].transactions[j].coins;
				}
			}
		}

		return balance;
	}

	void addTransaction(const Transaction &transaction) {
		if (blocksSize == 0 || blocks[blocksSize - 1].validTransactions == 16) {
			TransactionBlock newBlock{
				blocksSize,
				blocksSize > 0 ? blocks[blocksSize - 1].id : 0,
				blocksSize > 0 ? blocks[blocksSize - 1].computeBlockHash() : 0,
				0
			};

			addTransactionBlock(newBlock);
		}
		TransactionBlock &currBlock = blocks[blocksSize - 1];
		currBlock.transactions[currBlock.validTransactions++] = transaction;
	}

	void loadData() {
		FILE *usersFile = fopen("users.dat", "rb");
		if (usersFile) {
			fread(&usersSize, sizeof(int), 1, usersFile);
			fread(&usersCapacity, sizeof(int), 1, usersFile);
			users = new User[usersCapacity];
			fread(users, sizeof(User), usersSize, usersFile);
			fclose(usersFile);
		} else {
			usersSize = 0;
			usersCapacity = 10;
			users = new User[usersCapacity];
		}

		FILE *blocksFile = fopen("blocks.dat", "rb");
		if (blocksFile) {
			fread(&blocksSize, sizeof(int), 1, blocksFile);
			fread(&blocksCapacity, sizeof(int), 1, blocksFile);
			blocks = new TransactionBlock[blocksCapacity];
			fread(blocks, sizeof(TransactionBlock), blocksSize, blocksFile);
			fclose(blocksFile);
		} else {
			blocksSize = 0;
			blocksCapacity = 10;
			blocks = new TransactionBlock[blocksCapacity];
		}
	}

	void saveData() {
		FILE *usersFile = fopen("users.dat", "wb");
		fwrite(&usersSize, sizeof(int), 1, usersFile);
		fwrite(&usersCapacity, sizeof(int), 1, usersFile);
		fwrite(users, sizeof(User), usersSize, usersFile);
		fclose(usersFile);

		FILE *blocksFile = fopen("blocks.dat", "wb");
		fwrite(&blocksSize, sizeof(int), 1, blocksFile);
		fwrite(&blocksCapacity, sizeof(int), 1, blocksFile);
		fwrite(blocks, sizeof(TransactionBlock), blocksSize, blocksFile);
		fclose(blocksFile);
	}
};

int main() {
	OOPCoin oopCoin;

	char command[128];
	while (true) {
		std::cout << "> ";
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
			oopCoin.wealthiestUsers();

		} else if (strcmp(command, "biggest-blocks") == 0) {
			oopCoin.biggestBlocks();

		} else if (strcmp(command, "exit") == 0) {
			break;
		} else {
			std::cout << "Invalid command." << std::endl;
		}
	}

	return 0;
}
