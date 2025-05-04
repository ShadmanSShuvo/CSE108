#include<iostream>
#include<string>
using namespace std;

class BankAccount{
private:
    string name;
    string accountNumber;
    double balance;
public:
    string getAccountNumber() const {
        return accountNumber;
    }
    string getAccountName() const {
        return name;
    }
    BankAccount() : name(""), accountNumber(""), balance(0.0) {}
    BankAccount(string n, string accNum, double bal) : name(n), accountNumber(accNum), balance(bal) {}
    BankAccount(string n, string accNum) : name(n), accountNumber(accNum) {}
    
    void deposit(double ammount){
        if(ammount > 0)
            balance += ammount;
        else
            cout << "Invalid deposit amount" << endl;
    }

    void withdraw(double ammount){
        if(ammount > 0 && ammount <= balance)
            balance -= ammount;
        else
            cout << "Invalid withdrawal amount" << endl;
    }

    void display() const{
        cout << "\tAccount Number: " << accountNumber << endl;
        cout << "\tAccount Holder: " << name << endl;
        cout << "\tBalance: $" << balance << endl;
        cout << "\n";
    }

    

    ~BankAccount() {
        //cout << "Destructor called for account: " << name << endl;
    }
};

class Bank{
private:
    BankAccount accounts[100];
    int accountCount=0;

public:
    void addAccount(const BankAccount& account){
        accounts[accountCount] = account;
        accountCount++;
    }

    void displayAllAccounts(){
        cout << "Registered Accounts:" << endl;
        for(int i = 0; i < accountCount; i++){
            accounts[i].display();
            
        }
    }

    void deposit(const string& accNum, double amount){
        for(int i = 0; i < accountCount; i++){
            if(accounts[i].getAccountNumber() == accNum){
                accounts[i].deposit(amount);
                break;
            }
        }
    }

    void withdraw(const string& accNum, double amount){
        for(int i = 0; i < accountCount; i++){
            if(accounts[i].getAccountNumber() == accNum){
                accounts[i].withdraw(amount);
                break;
            }
        }
    }
    void addAccount(const string& accNum, const string& name){
        accounts[accountCount] = BankAccount(name, accNum);
        accountCount++;
    }

    void addAccount(const string& accNum, const string& name, double balance){
        accounts[accountCount] = BankAccount(name, accNum, balance);
        accountCount++;
    }

    void removeAccount(const string& accNum){
        for(int i = 0; i < accountCount; i++){
            if(accounts[i].getAccountNumber() == accNum){
                cout << "Account '" << accounts[i].getAccountName() << " (" << accounts[i].getAccountNumber() << ")' removed successfully.\n" << endl;
                for(int j = i; j < accountCount - 1; j++){
                    accounts[j] = accounts[j + 1];
                }
                accountCount--;
                break;
            }
        }
    }

    ~Bank() {
        // Destructor
        // cout << "Destructor called for Bank" << endl;
    }
};



int main() {
    Bank bank;
    // Add new bank accounts
    bank.addAccount("12345", "John Doe");
    bank.addAccount("67890", "Jane Smith");
    // Perform transactions
    bank.deposit("12345", 1000.0);
    bank.deposit("67890", 500.0);
    // Display account details
    bank.displayAllAccounts();
    // Perform transactions
    bank.withdraw("12345", 200.0);
    bank.withdraw("67890", 500.0);
    // Display account details after transaction
    bank.displayAllAccounts();
    // Remove an account
    bank.removeAccount("67890");
    // Display account details after removal
    bank.displayAllAccounts();
    // Add more accounts
    bank.addAccount("24680", "Sarah Adams");
    bank.addAccount("13579", "Michael Lee");
    // Perform transactions on the newly added accounts
    bank.deposit("24680", 1500.0);
    bank.deposit("13579", 200.0);
    bank.withdraw("13579", 100.0);
    bank.withdraw("24680", 300.0);
    // Display all accounts
    bank.displayAllAccounts();
    return 0;
}