#pragma once

#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>

#define OOPCOINS_PER_BGN 420.0
#define OOPCOINS_TO_BGN(oopCoins) ((oopCoins) / OOPCOINS_PER_BGN)
#define BGN_TO_OOPCOINS(bgn) ((bgn) * OOPCOINS_PER_BGN)

extern const char usersFileName[10];

extern const char blocksFileName[11];

extern const int oopCoins;

class OOPCoin {
public:
	OOPCoin();

	~OOPCoin();

	void createUser(unsigned, const char *, double);

	void removeUser(const char *);

	void sendCoins(unsigned, unsigned, double);

	bool verifyTransactions();

	void wealthiestUsers(unsigned);

	void biggestBlocks(unsigned);

private:
	static unsigned computeHash(const unsigned char *, int);

	struct User {
		char name[128];
		unsigned id;

	private:
		User() = default;

		User(unsigned int id, const char *new_name) : id(id) {
			strncpy(name, new_name, sizeof(name) - 1);
			name[sizeof(name) - 1] = '\0';
		}

	public:
		friend class OOPCoin;
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

	void addUser(const User &);

	void addTransactionBlock(const TransactionBlock &);

	double getBalance(unsigned);

	void addTransaction(const Transaction &);

	void loadData();

	void saveData();
};
