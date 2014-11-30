/*
 * Mariusz Kozakowski
 */
#include <iostream>

//------------------
class Account;
class Transaction;
class Group;

//------------------
void createAccount(Account*&);
void deleteAccount(Account*);

void createTransaction(Transaction*&);
void createTransaction(Transaction**&, int);
void printTransaction(Transaction**, int);
void deleteTransaction(Transaction*);
void deleteTransaction(Transaction**, int);

void createGroup(Group*&);
void createGroup(Group*&, int);
void printGroup(Group*, int);
void deleteGroup(Group*);
void deleteGroup(Group*, int);

//------------------
class Account
{
    char* name_;
    int balance_;
public:
    Account(){};
    Account(char* name, int balance = 0);
    ~Account(){};
    void set(char* name, int balance = 0);
    void change(int amount);
    void print();
};

class Transaction
{
    char* name_;
    int amount_;
    Group* group_;
    Account* account_;
public:
    Transaction(){};
    Transaction(char* name, int amount, Group* group, Account* account);
    ~Transaction(){};
    void set(char* name, int amount, Group* group, Account* account);
    void print();
};

class Group
{
    char* name_;
public:
    Group(){};
    Group(char* name);
    ~Group(){};
    void set(char* name);
    void print();
    char* name();
};

//------------------
int main()
{
    Account* account = new Account((char*)"Personal Account", 1214);
    Transaction* transaction;
    Group* group;

    std::cout << "|= Single pointer"
	      << std::endl;
    std::cout << "|== Account"
	      << std::endl;

    account->print();

    std::cout << std::endl;
    std::cout << "|== Group"
	      << std::endl;

    createGroup(group);
    group->set((char*)"Transportation");
    group->print();

    std::cout << std::endl;
    std::cout << "|== Transaction"
	      << std::endl;

    createTransaction(transaction);
    transaction->set((char*)"Fuel", 100, group, account);
    transaction->print();

    std::cout << std::endl;
    std::cout << "|= Arrays"
	      << std::endl;

    Transaction** transactions;
    Group* groups;

    int size = 5;
    int sizeGroup = 3;
    
    createTransaction(transactions, size);
    createGroup(groups, sizeGroup);

    (&groups[0])->set((char*)"Games");
    (&groups[1])->set((char*)"Lunch");
    (&groups[2])->set((char*)"Educations");
    
    for(int i = 0; i < size; ++i)
	transactions[i]->set((char*)"Automat", 1 * (i+1),
			     &groups[i/2], account);

    std::cout << "|== Groups (pointer to array)"
	      << std::endl;

    printGroup(groups, sizeGroup);

    std::cout << std::endl;
    std::cout << "|== Transactions (array of pointers)"
	      << std::endl;

    printTransaction(transactions, size);
    account->print();

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

Account::Account(char* name, int balance)
{
    this->set(name, balance);
}

void Account::set(char* name, int balance)
{
    name_ = name;
    balance_ = balance;
}

void Account::print()
{
    std::cout << name_ << " = "
	      << balance_
	      << std::endl;
}

void Account::change(int amount)
{
    balance_ -= amount;
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

Transaction::Transaction(char* name, int amount,
			 Group* group, Account* account)
{
    this->set(name, amount, group, account);
}

void Transaction::set(char* name, int amount,
		      Group* group, Account* account)
{
    name_ = name;
    amount_ = amount;
    group_ = group;
    account_ = account;

    account->change(amount);
}

void Transaction::print()
{
    std::cout << name_ << " ["
	      << group_->name() << "] = "
	      << amount_
	      << std::endl;
}

void printTransaction(Transaction** transactions, int size)
{
    for(int i = 0; i < size; ++i)
	transactions[i]->print();
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

Group::Group(char* name)
{
    this->set(name);
}

void Group::set(char* name)
{
    name_ = name;
}

void Group::print()
{
    std::cout << name_
	      << std::endl;
}

char* Group::name()
{
    return name_;
}

void printGroup(Group* groups, int size)
{
    for(int i = 0; i < size; ++i)
	(&groups[i])->print();
}

void deleteGroup(Group* group)
{
    delete group;
}

void deleteGroup(Group* groups, int size)
{
    delete[] groups;
}
