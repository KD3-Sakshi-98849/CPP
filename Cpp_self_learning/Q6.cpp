#include<iostream>
using namespace std;
class BankAccount{
    private:
    string accountHolderName;
    int accountNumber;
    int balance;

    public:
    int test=1;
    BankAccount(void):accountHolderName(""),accountNumber(0),balance(0){

    }
    BankAccount(string accountHolderName,int accountNumber,int balance):accountHolderName(accountHolderName),accountNumber(accountNumber),balance(balance){
        
    }
    void deposit(int amount){
        this->balance=this->balance+amount;
    }
    void withdraw(int amount){
        this->balance=this->balance-amount;
    }
    void Display(){
        cout<<"account balance is : "<<this->balance<<endl;
    }
};

int main(){
    BankAccount a1("sourabh",12345,1000);
    a1.Display();
    a1.deposit(500);
    a1.Display();
    //we can acces public variable in main
    cout<<a1.test;
    //we cannot acces private members from main
    //cout<<a1.balance;
    a1.withdraw(200);
    a1.Display();
}