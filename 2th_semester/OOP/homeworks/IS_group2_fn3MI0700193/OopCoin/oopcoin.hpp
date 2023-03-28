#pragma once

#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>

class OOPCoin {
public:
	OOPCoin();

	~OOPCoin();

	void createUser(unsigned creatorId, const char *name, double investment);

	void removeUser(const char *name);

	void sendCoins(unsigned senderId, unsigned receiverId, double coins);

	bool verifyTransactions();

	void wealthiestUsers();

	void biggestBlocks();

private:
	static unsigned computeHash(const unsigned char *memory, int length);

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
	unsigned nextUserId = 0;

	void addUser(const User &user);

	void addTransactionBlock(const TransactionBlock &block);

	double getBalance(unsigned userId);

	void addTransaction(const Transaction &transaction);

	void loadData();

	void saveData();
};
