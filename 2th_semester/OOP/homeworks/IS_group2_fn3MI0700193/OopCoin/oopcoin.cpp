#include "oopcoin.hpp"

OOPCoin::OOPCoin() {
	loadData();

	if (usersSize == 0) {
		createUser(0, "System User", 100);
	}
}

OOPCoin::~OOPCoin() {
	saveData();
	delete[] users;
	delete[] blocks;
}

void OOPCoin::createUser(unsigned int creatorId, const char *name, double investment) {
	if (creatorId != systemUserId) {
		std::cerr << "Only the system user can create other users." << std::endl;
		return;
	}

	User newUser{nextUserId, name};

	addUser(newUser);
	sendCoins(systemUserId, newUser.id, investment * 420);
	std::cout << "User " << newUser.name << " created with id " << newUser.id << std::endl;
}

void OOPCoin::removeUser(const char *name) {
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

void OOPCoin::sendCoins(unsigned int senderId, unsigned int receiverId, double coins) {
	if (senderId == receiverId && senderId != 0) {
		std::cerr << "Sender and receiver cannot be the same." << std::endl;
		return;
	} else if (coins <= 0) {
		std::cerr << "Coins must be positive." << std::endl;
		return;
	} else if (senderId != 0 && (getBalance(senderId) - coins) < coins) {
		std::cerr << "Sender does not have enough coins." << std::endl;
		return;
	} else if (senderId == 0 && (getBalance(senderId) - coins) < 0) {
		std::cerr << "oopCoins are not infinite. User created with only the left over coins: "
		          << getBalance(senderId) << "." << std::endl;

		Transaction transaction{senderId, receiverId, getBalance(senderId)};
		addTransaction(transaction);
		return;
	}

	Transaction transaction{senderId, receiverId, coins};

	addTransaction(transaction);
}

bool OOPCoin::verifyTransactions() {
	for (int i = 1; i < blocksSize; i++) {
		if (blocks[i].prevBlockId != blocks[i - 1].id ||
			blocks[i].prevBlockHash != blocks[i - 1].computeBlockHash() ||
			blocks[i].validTransactions < 1) {
			return false;
		}
	}

	return true;
}

void OOPCoin::wealthiestUsers() {
	const unsigned usersSizeWithoutSystemUser = usersSize - 1;
	if (usersSizeWithoutSystemUser == 0) {
		std::cerr << "There are no users to show." << std::endl;
		return;
	}

	struct UserBalance {
		User *user;
		double balance;
	} userBalances[usersSizeWithoutSystemUser];

	for (int i = 1; i < usersSize; i++) {
		userBalances[i - 1].user = &users[i];
		userBalances[i - 1].balance = getBalance(users[i].id);
	}

	for (int i = 0; i < usersSizeWithoutSystemUser - 1; i++) {
		for (int j = 0; j < usersSizeWithoutSystemUser - i - 1; j++) {
			if (userBalances[j].balance < userBalances[j + 1].balance) {
				UserBalance temp = userBalances[j];
				userBalances[j] = userBalances[j + 1];
				userBalances[j + 1] = temp;
			}
		}
	}

	char fileName[128];
	snprintf(fileName, sizeof(fileName), "wealthiest-users-%lld.txt", static_cast<long long>(time(nullptr)));

	FILE *file = fopen(fileName, "w");

	for (int i = 0; i < usersSizeWithoutSystemUser; i++) {
		std::cout << userBalances[i].user->name << " " << userBalances[i].balance << std::endl;
		fprintf(file, "%s, %lf\n", userBalances[i].user->name, userBalances[i].balance);
	}

	fclose(file);
}

void OOPCoin::biggestBlocks() {
	struct BlockAmount {
		unsigned id;
		double balance;
	} blockAmounts[blocksSize];

	for (int i = 0; i < blocksSize; i++) {
		blockAmounts[i].id = blocks[i].id;
		blockAmounts[i].balance = 0;

		for (int j = 0; j < blocks[i].validTransactions; j++) {
			blockAmounts[i].balance += blocks[i].transactions[j].coins;
		}
	}

	for (int i = 0; i < blocksSize - 1; i++) {
		for (int j = 0; j < blocksSize - i - 1; j++) {
			if (blockAmounts[j].balance < blockAmounts[j + 1].balance) {
				BlockAmount temp = blockAmounts[j];
				blockAmounts[j] = blockAmounts[j + 1];
				blockAmounts[j + 1] = temp;
			}
		}
	}

	char fileName[128];
	snprintf(fileName, sizeof(fileName), "biggest-blocks-%lld.txt", static_cast<long long>(time(nullptr)));

	FILE *file = fopen(fileName, "w");

	for (int i = 0; i < blocksSize; i++) {
		std::cout << blockAmounts[i].id << " " << blockAmounts[i].balance << std::endl;
		fprintf(file, "%u, %lf\n", blockAmounts[i].id, blockAmounts[i].balance);
	}

	fclose(file);
}

unsigned OOPCoin::computeHash(const unsigned char *memory, int length) {
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

void OOPCoin::addUser(const OOPCoin::User &user) {
	if (usersSize == usersCapacity) {
		usersCapacity *= 2;
		User *newUsers = new User[usersCapacity];
		std::copy(users, users + usersSize, newUsers);
		delete[] users;
		users = newUsers;
	}
	nextUserId++;
	users[usersSize++] = user;
}

void OOPCoin::addTransactionBlock(const OOPCoin::TransactionBlock &block) {
	if (blocksSize == blocksCapacity) {
		blocksCapacity *= 2;
		TransactionBlock *newBlocks = new TransactionBlock[blocksCapacity];
		std::copy(blocks, blocks + blocksSize, newBlocks);
		delete[] blocks;
		blocks = newBlocks;
	}
	blocks[blocksSize++] = block;
}

double OOPCoin::getBalance(unsigned int userId) {
	double balance = 0;

	for (int i = 0; i < blocksSize; i++) {
		for (int j = 0; j < blocks[i].validTransactions; j++) {

			if (blocks[i].transactions[j].receiver == userId) {
				balance += blocks[i].transactions[j].coins;

			} else if (blocks[i].transactions[j].sender == userId) {
				balance -= blocks[i].transactions[j].coins;
			}
		}
	}

	return balance;
}

void OOPCoin::addTransaction(const OOPCoin::Transaction &transaction) {
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

void OOPCoin::loadData() {
	FILE *usersFile = fopen("users.dat", "rb");
	if (usersFile) {
		fread(&usersSize, sizeof(int), 1, usersFile);
		fread(&usersCapacity, sizeof(int), 1, usersFile);
		users = new User[usersCapacity];
		fread(users, sizeof(User), usersSize, usersFile);
		fclose(usersFile);
		nextUserId = users[usersSize - 1].id + 1;
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

void OOPCoin::saveData() {
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



