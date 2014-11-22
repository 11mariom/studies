/*
 * Mariusz Kozakowski
 */
#include <iostream>

//------------------
struct Account;
struct Transaction;
struct Group;

void createAccount(Account*&);
void setAccount(Account*, char*, int);
void printAccount(Account*);
void deleteAccount(Account*);

void createTransaction(Transaction*&);
void createTransaction(Transaction**&, int);
void addTransaction(Transaction**&, int&);
void delTransaction(Transaction**&, int&, int);
void setTransaction(Transaction*, char*, int, Group*, Account*);
void printTransaction(Transaction*);
void printTransaction(Transaction**, int);
void deleteTransaction(Transaction*);
void deleteTransaction(Transaction**, int);

void createGroup(Group*&);
void createGroup(Group*&, int);
void setGroup(Group*, char*);
void printGroup(Group*);
void printGroup(Group*, int);
void deleteGroup(Group*);
void deleteGroup(Group*, int);

//------------------
struct Account
{
    char* name;
    int balance;
};

struct Transaction
{
    char* name;
    int amount;
    Group* group;
    Account* account;
};

struct Group
{
    char* name;
};

//------------------
int main()
{
    Account* account;
    Transaction* transaction;
    Group* group;

    std::cout << "|= Single pointer"
	      << std::endl;
    std::cout << "|== Account"
	      << std::endl;

    createAccount(account);
    setAccount(account, (char*)"Personal Account", 1214);
    printAccount(account);

    std::cout << std::endl;
    std::cout << "|== Group"
	      << std::endl;

    createGroup(group);
    setGroup(group, (char*)"Transportation");
    printGroup(group);

    std::cout << std::endl;
    std::cout << "|== Transaction"
	      << std::endl;

    createTransaction(transaction);
    setTransaction(transaction, (char*)"Fuel", 100, group, account);
    printTransaction(transaction);

    std::cout << std::endl;
    std::cout << "|= Arrays"
	      << std::endl;
    
    Transaction** transactions;
    Group* groups;

    int size = 5;
    int sizeGroup = 3;
    
    createTransaction(transactions, size);
    createGroup(groups, sizeGroup);

    setGroup(&groups[0], (char*)"Games");
    setGroup(&groups[1], (char*)"Lunch");
    setGroup(&groups[2], (char*)"Educations");

    for(int i = 0; i < size; ++i)
	setTransaction(transactions[i], (char*)"Automat", 1 * (i+1),
		       &groups[i/2], account);

    std::cout << "|== Groups (pointer to array)"
	      << std::endl;

    printGroup(groups, sizeGroup);

    std::cout << std::endl;
    std::cout << "|== Transactions (array of pointers)"
	      << std::endl;

    printTransaction(transactions, size);
    printAccount(account);

    std::cout << std::endl;
    std::cout << "|== Add new transaction"
	      << std::endl;
    
    addTransaction(transactions, size);
    setTransaction(transactions[size-1], (char*)"Added", 100, &groups[0], account);
    printTransaction(transactions, size);
    printAccount(account);

    std::cout << std::endl;
    std::cout << "|== Delete transaction"
	      << std::endl;

    delTransaction(transactions, size, 2);
    printTransaction(transactions, size);
    printAccount(account);
    

    deleteAccount(account);
    deleteTransaction(transaction);
    deleteTransaction(transactions, size);
    deleteGroup(group);
    deleteGroup(groups, sizeGroup);
    
    return 0;
}

//------------------
void createAccount(Account*& account)
{
    account = new Account;
}

void setAccount(Account* account, char* name, int balance)
{
    account->name = name;
    account->balance = balance;
}

void printAccount(Account* account)
{
    std::cout << account->name << " = "
	      << account->balance
	      << std::endl;
}

void deleteAccount(Account* account)
{
    delete account;
}

//------------------
void createTransaction(Transaction*& transaction)
{
    transaction = new Transaction;
}

void createTransaction(Transaction**& transactions, int size)
{
    transactions = new Transaction*[size];

    for(int i = 0; i < size; ++i)
	transactions[i] = new Transaction;
}

void addTransaction(Transaction**& transactions, int& size)
{
    Transaction** tmp;
    createTransaction(tmp, size + 1);

    for(int i = 0; i < size; ++i){
	setTransaction(tmp[i], transactions[i]->name, transactions[i]->amount,
		       transactions[i]->group, transactions[i]->account);
	transactions[i]->account->balance += transactions[i]->amount;
	delete transactions[i];
    }

    transactions = tmp;
    ++size;
}

void delTransaction(Transaction**& transactions, int& size, int index)
{
    if(index < size){
	Transaction** tmp;
	createTransaction(tmp, size - 1);

	for(int i = 0; i < index; ++i){
	    setTransaction(tmp[i], transactions[i]->name, transactions[i]->amount,
			   transactions[i]->group, transactions[i]->account);
	    transactions[i]->account->balance += transactions[i]->amount;
	    delete transactions[i];
	}

	transactions[index]->account->balance += transactions[index]->amount;
	delete transactions[index];
	
	for(int i = index + 1; i < size; ++i){
	    setTransaction(tmp[i-1], transactions[i]->name, transactions[i]->amount,
			   transactions[i]->group, transactions[i]->account);
	    transactions[i]->account->balance += transactions[i]->amount;
	    delete transactions[i];
	}
    
	transactions = tmp;
	--size;
    } else {
	std::cout << "Wrong index!"
		  << std::endl;
    }
}

void setTransaction(Transaction* transaction, char* name, int amount,
		    Group* group, Account* account)
{
    transaction->name = name;
    transaction->amount = amount;
    transaction->group = group;
    transaction->account = account;

    account->balance = account->balance - amount;
}

void printTransaction(Transaction* transaction)
{
    std::cout << transaction->name << " ["
	      << transaction->group->name << "] = "
	      << transaction->amount
	      << std::endl;
}

void printTransaction(Transaction** transactions, int size)
{
    for(int i = 0; i < size; ++i)
	printTransaction(transactions[i]);
}

void deleteTransaction(Transaction* transaction)
{
    delete transaction;
}

void deleteTransaction(Transaction** transactions, int size)
{
    for(int i = 0; i < size; ++i)
	delete transactions[i];
    delete transactions;
}

//------------------
void createGroup(Group*& group)
{
    group = new Group;
}

void createGroup(Group*& groups, int size)
{
    groups = new Group[size];
}

void setGroup(Group* group, char* name)
{
    group->name = name;
}

void printGroup(Group* group)
{
    std::cout << group->name
	      << std::endl;
}

void printGroup(Group* groups, int size)
{
    for(int i = 0; i < size; ++i)
	printGroup(&groups[i]);
}

void deleteGroup(Group* group)
{
    delete group;
}

void deleteGroup(Group* groups, int size)
{
    delete[] groups;
}
