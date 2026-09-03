#include <iostream>
#include <typeinfo>
using namespace std;
class InvalidException
{
private:
    string messages;

public:
    InvalidException() : messages("") {}
    InvalidException(string messages) : messages(messages) {}
    string getmsg()
    {
        return messages;
    }
};
class Bank_Accounts
{
protected:
    string Account_Number;
    string Ac_Holder_Name;
    string Mobile_Number;
    int initial_Balance = 0;
    string Account_type;
    string Add_Account;

public:
    Bank_Accounts() : Account_Number(""), Ac_Holder_Name(""), Mobile_Number(""), initial_Balance(0), Account_type(""), Add_Account(0) {}
    Bank_Accounts(string Account_Number,
                  string Ac_Holder_Name,
                  string Mobile_Number,
                  int initial_Balance, string Add_Account) : Account_Number(Account_Number), Ac_Holder_Name(Ac_Holder_Name), Mobile_Number(Mobile_Number), initial_Balance(initial_Balance), Account_type(Account_type) {}

    void get_AddAccout()
    {
        cout << "AddAccount" << Add_Account;
    }
    virtual void AcceptRecord()
    {
        cout << "Enter Account Number" << endl;
        cin >> Account_Number;

        cout << "Enter Account Holder Name" << endl;
        cin >> Ac_Holder_Name;

        cout << "Enter Mobile Number" << endl;
        cin >> Mobile_Number;

        cout << "Enter initial Balance" << endl;
        cin >> initial_Balance;

        // cout << "Enter Account type" << endl;
        // cin >> Account_type;
    }
    virtual void DisplayRecord()
    {
        cout << "Enter Account Number" << Account_Number << endl;
        cout << "Enter Account Holder Name" << Ac_Holder_Name << endl;
        cout << "Enter Mobile Number" << Mobile_Number << endl;
        cout << "Enter initial Balance" << initial_Balance << endl;
        // cout << "Enter Account Type:" << Account_type << endl;
    }
    virtual void display_AccountType()
    {
        cout << "Enter Account type" << endl;
        cin >> Account_type;
    }
};
class Saving_Account : public Bank_Accounts
{
private:
    int interest_Rate = 0;
    // int withdrawBalance = 0;
    int Deposit_Amount = 0;

public:
    Saving_Account() : interest_Rate(0) {}
    Saving_Account(int interest_Rate, string Account_Number,
                   string Ac_Holder_Name,
                   string Mobile_Number,
                   int initial_Balance, string Add_Account) : interest_Rate(interest_Rate) {}
    // void withdrawBalance(int withdrawBalance)
    // {
    //     this->withdrawBalance = withdrawBalance;
    // }
    // void DepositAmount(int Deposit_Amount)
    // {
    //     this->Deposit_Amount=Deposit_Amount;
    // }
    void AcceptRecord()
    {
        Bank_Accounts::AcceptRecord();
        cout << "interest Rate" << endl;
        cin >> interest_Rate;
        cout << "enter Deposit Amount" << endl;
        cin >> Deposit_Amount;
        if (Deposit_Amount < 0)
        {
            throw InvalidException("Invalid!Negative Deposit Amount");
        }
    }
    void DisplayRecord()
    {
        Bank_Accounts::DisplayRecord();
        cout << " Deposit_Amount" << Deposit_Amount << endl;
        cout << "interest Rate" << interest_Rate << endl;
    }
};
class Current_Account : public Bank_Accounts
{
protected:
    // int Balance;
    int Withdraw_Amount;
    int Updated_Balance = 0;

public:
    Current_Account() : Withdraw_Amount(0), Updated_Balance(0) {}
    Current_Account(int Withdraw_Amount) : Withdraw_Amount(Withdraw_Amount), Updated_Balance(Updated_Balance) {}
    void AcceptRecord()
    {
        cout << "enter Withdraw Amount" << endl;
        cin >> Withdraw_Amount;
        if (Withdraw_Amount < 0)
        {
            throw InvalidException("Handle Insufficient Balance");
        }
    }
    void DisplayRecord()
    {
        cout << "Withdraw Amount" << Withdraw_Amount << endl;
    }
    void withdrawAmount(int Withdraw_Amount)
    {
        Updated_Balance -= this->Withdraw_Amount;
        cout << "Updated Balance:" << Updated_Balance;
    }
};
// int menulist()
// {

// }
int main()
{
    int choice;
    int count = 0;
    Bank_Accounts *arr[5];
    try
    {
        do
        {
            int choice;
            cout << "1.Add new Account" << endl;
            cout << "2.Display All Account" << endl;
            cout << "3.deposit Amount" << endl;
            cout << "4.withdraw Amount :" << endl;
            cout << "5.Display Account Type:" << endl;
            cout << "Enter choice" << endl;
            cin >> choice;

            // return choice;
            for (int i = 0; i < 5; i++)
            {
                if (count >= 5)
                {
                    cout << "Array is full" << endl;
                    if (choice == 1)
                    {
                        arr[count] = new Bank_Accounts();
                        arr[count]->get_AddAccout();
                        // arr[count] = new Bank_Accounts();
                        // Bank_Accounts *b = dynamic_cast<Bank_Accounts *>(arr[count]);
                        // b->AcceptRecord();
                        // b->DisplayRecord();
                    }
                    else if (choice == 2)
                    {
                        // if(typeid(arr[i])=Saving_Account){}
                        arr[count] = new Current_Account();
                        Current_Account *c = dynamic_cast<Current_Account *>(arr[count]);
                        c->DisplayRecord();
                    }
                    else if (choice == 3)
                    {
                        arr[count] = new Saving_Account();
                        Saving_Account *s = dynamic_cast<Saving_Account *>(arr[count]);
                        s->AcceptRecord();
                        s->DisplayRecord();
                    }
                    else if (choice == 4)
                    {
                        arr[count] = new Current_Account();
                        Current_Account *c = dynamic_cast<Current_Account *>(arr[count]);
                        c->withdrawAmount(500);
                    }
                    else if (choice == 5)
                    {
                        arr[count] = new Bank_Accounts();
                        arr[count]->display_AccountType();
                    }
                    else
                    {
                        cout << "Invalid choice:" << endl;
                    }
                }
                delete arr[i];
                arr[i] = NULL;
            }
        }
        // while (count > 5)
        // {
        //     for (int i = 0; i < counti++)
        //     {
        //         delete[i] Bank_Accounts;
        //         Bank_Accounts[i] = 0;
        //     }
        // }
    }

    catch (InvalidException &e)
    {
        cout << "Enter messag:" << &e << endl;
    }
    return 0;
}
