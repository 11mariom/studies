/*
 * Mariusz Kozakowski
 */
#include <iostream>

/*------------------
 * Program declarations
 */
class Program
{
    // subclass declarations
    class Account;
    class Transaction;
    class Group;

    // subclass definitions
    class Account
    {
	char* name_;
	int balance_;
	friend class Transaction;
    protected:
	static int size_;
    public:
	Account(){};
	Account(char* name, int balance);
	Account(Account*& src);
	~Account();

	void print();

	static int size(){ return size_; }
    };

    class Transaction
    {
      	char* name_;
	int amount_;
	Group* group_;
	Account* account_;
    protected:
	static int size_;
    public:
	Transaction(){};
	Transaction(char* name, int amount, Group* group, Account* account);
	Transaction(Transaction*& src);
	~Transaction();

	void print();

	static int size(){ return size_; }
    };

    class Group
    {
	char* name_;
	friend class Transaction;
    protected:
	static int size_;
    public:
	Group(){};
	Group(char* name);
	Group(Group*& src);
	~Group();

	void print();

	static int size(){ return size_; }
    };

    // variables
    Account** account_;
    Transaction** transaction_;
    Group** group_;
public:
    Program();
    ~Program();

    void addAccount(char* name, int balance);
    void delAccount(int id);

    void addTransaction(char* name, int amount, int gid, int aid);
    void delTransaction(int id);

    void addGroup(char* name);
    void delGroup(int id);

    void print();
    void printAccount(int id);
    void printAccounts();
    void printTransaction(int id);
    void printTransactions();
    void printGroup(int id);
    void printGroups();
};

// initialize static counters
int Program::Account::size_ = 0;
int Program::Transaction::size_ = 0;
int Program::Group::size_ = 0;

//------------------
int main()
{
    Program data;

    data.addAccount((char*)"Personal Account", 1214);
    data.print();
    data.addAccount((char*)"Work Account", 10000);
    data.addGroup((char*)"Transportation");
    data.addGroup((char*)"Games");
    data.addGroup((char*)"Lunch");
    data.addGroup((char*)"Education");

    data.addTransaction((char*)"Test 2", 10, 2, 1);
    data.addTransaction((char*)"Fuel", 100, 0, 0);
    data.print();

    data.addTransaction((char*)"Test 1", 123, 1, 0);
    data.print();

    return 0;
}

/*------------------
 * Main program constructor and destructor
 */
Program::Program()
{
}

Program::~Program()
{
    int a = Account::size(),
	t = Transaction::size(),
	g = Group::size();

    for(int i = 0; i < a; ++i)
	delete account_[i];
    for(int i = 0; i < t; ++i)
	delete transaction_[i];
    for(int i = 0; i < g; ++i)
	delete group_[i];

    if(a > 0)
	delete[] account_;
    if(t > 0)
	delete[] transaction_;
    if(g > 0)
	delete[] group_;
}

/*------------------
 * Program::Acount
 */
Program::Account::Account(char* name, int balance)
{
    name_ = name;
    balance_ = balance;
    ++size_;
}

Program::Account::Account(Account*& src)
{
    name_ = src->name_;
    balance_ = src->balance_;
    ++size_;
}

Program::Account::~Account()
{
    --size_;
}

void Program::Account::print()
{
    std::cout << name_ << " => " << balance_ << std::endl;
}

void Program::addAccount(char* name, int balance)
{
    int size = Account::size();
    Account** tmp = new Account*[size + 1];

    // copy existing acocunts
    for(int i = 0; i < size; ++i){
	tmp[i] = new Account(account_[i]);
	delete account_[i];
    }

    tmp[size] = new Account(name, balance);
    account_ = tmp;
}

void Program::delAccount(int id)
{
    int size = Account::size();
    Account** tmp = new Account*[size - 1];

    for(int i = 0; i < id; ++i){
	tmp[i] = new Account(account_[i]);
	delete account_[i];
    }

    delete account_[id];
    for(int i = id + 1; i < size; ++i){
	tmp[i-1] = new Account(account_[i]);
	delete account_[i];
    }

    account_ = tmp;
}

/*------------------
 * Program::Transaction
 */
Program::Transaction::Transaction(char* name, int amount, Group* group,
				  Account* account)
{
    name_ = name;
    amount_ = amount;
    group_ = group;
    account_ = account;

    account_->balance_ -= amount;
    ++size_;
}

Program::Transaction::Transaction(Transaction*& src)
{
    name_ = src->name_;
    amount_ = src->amount_;
    group_ = src->group_;
    account_ = src->account_;
    ++size_;
}

Program::Transaction::~Transaction()
{
    --size_;
}

void Program::Transaction::print()
{
    std::cout << account_->name_ << ": " << name_ << " [" << group_->name_
	      << "] = " << amount_ << std::endl;
}

void Program::addTransaction(char* name, int amount, int gid, int aid)
{
    int size = Transaction::size();
    Transaction** tmp = new Transaction*[size + 1];

    // copy existing transactions
    for(int i = 0; i < size; ++i){
	tmp[i] = new Transaction(transaction_[i]);
	delete transaction_[i];
    }

    tmp[size] = new Transaction(name, amount, group_[gid], account_[aid]);
    transaction_ = tmp;
}

void Program::delTransaction(int id)
{
    int size = Transaction::size();
    Transaction** tmp = new Transaction*[size - 1];

    for(int i = 0; i < id; ++i){
	tmp[i] = new Transaction(transaction_[i]);
	delete transaction_[i];
    }

    delete transaction_[id];
    for(int i = id + 1; i < size; ++i){
	tmp[i-1] = new Transaction(transaction_[i]);
	delete transaction_[i];
    }

    transaction_ = tmp;
}

/*------------------
 * Program::Group
 */
Program::Group::Group(char* name)
{
    name_ = name;
    ++size_;
}

Program::Group::Group(Group*& src)
{
    name_ = src->name_;
    ++size_;
}

Program::Group::~Group()
{
    --size_;
}

void Program::Group::print()
{
    std::cout << name_ << std::endl;
}

void Program::addGroup(char* name)
{
    int size = Group::size();
    Group** tmp = new Group*[size + 1];

    // copy existing groups
    for(int i = 0; i < size; ++i){
	tmp[i] = new Group(group_[i]);
	delete group_[i];
    }

    tmp[size] = new Group(name);
    group_ = tmp;
}

void Program::delGroup(int id)
{
    int size = Group::size();
    Group** tmp = new Group*[size - 1];

    for(int i = 0; i < id; ++i){
	tmp[i] = new Group(group_[i]);
	delete group_[i];
    }

    delete group_[id];
    for(int i = id + 1; i < size; ++i){
	tmp[i-1] = new Group(group_[i]);
	delete group_[i];
    }

    group_ = tmp;
}

/*------------------
 * print functions
 */
void Program::print()
{
    std::cout << "Accounts: " << Account::size() << std::endl;
    printAccounts();
    std::cout << std::endl;

    std::cout << "Transactions: " << Transaction::size() << std::endl;
    printTransactions();
    std::cout << std::endl;

    std::cout << "Groups: " << Group::size() << std::endl;
    printGroups();
    std::cout << std::endl;
}

void Program::printAccount(int id)
{
    account_[id]->print();
}

void Program::printAccounts()
{
    int size = Account::size();

    for(int i = 0; i < size; ++i)
	account_[i]->print();
}

void Program::printTransaction(int id)
{
    transaction_[id]->print();
}

void Program::printTransactions()
{
    int size = Transaction::size();

    for(int i = 0; i < size; ++i)
	transaction_[i]->print();
}

void Program::printGroup(int id)
{
    group_[id]->print();
}

void Program::printGroups()
{
    int size = Group::size();

    for(int i = 0; i < size; ++i)
	group_[i]->print();
}
