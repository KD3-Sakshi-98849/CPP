#include<iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    double price;

public:
    Product(void): id(0), title(" "), price(0.0)
    {
    }

    Product(int id, string title, double price): id(id), title(title), price(price)
    {
    }

    virtual void acceptRecord(void)
    {
        cout<<"ID : ";
        cin>>id;
        cout<<"Title : ";
        cin>>title;
        cout<<"Price : ";
        cin>>price;
    }

    virtual double calculateFinalPrice(void) = 0;

    virtual void printRecord(void)
    {
        cout<<"ID : "<<id<<endl;
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }

    virtual ~Product(void)
    {
    }
};

class Book : public Product
{
private:
    string author;

public:
    Book(void): author(" ")
    {
    }

    Book(int id, string title, string author, double price):
        Product(id, title, price), author(author)
    {
    }

    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"Author : ";
        cin>>author;
    }

    double calculateFinalPrice(void)
    {
        return price * 0.90;
    }

    void printRecord(void)
    {
        Product::printRecord();
        cout<<"Author : "<<author<<endl;
    }
};

class Tape : public Product
{
private:
    string artist;

public:
    Tape(void): artist(" ")
    {  }

    Tape(int id, string title, string artist, double price):
        Product(id, title, price), artist(artist)
    {  }

    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"Artist : ";
        cin>>artist;
    }

    double calculateFinalPrice(void)
    {
        return price * 0.95;
    }

    void printRecord(void)
    {
        Product::printRecord();
        cout<<"Artist : "<<artist<<endl;
    }
};

int menuList(void)
{
    int choice;
    cout<<"\n0. EXIT"<<endl;
    cout<<"1. Book"<<endl;
    cout<<"2. Tape"<<endl;
    cout<<"Enter a Choice : ";
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    int index = 0;
    Product *arr[3];
    while(index < 3 && (choice = ::menuList()) != 0)
    {
        switch(choice)
        {
        case 1:
            arr[index] = new Book();
            arr[index]->acceptRecord();
            index++;
            break;

        case 2:
            arr[index] = new Tape();
            arr[index]->acceptRecord();
            index++;
            break;

        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    double total = 0.0;
    for(int i = 0; i < index; i++)
    {
        cout<<"\nProduct "<<i + 1<<endl;
        arr[i]->printRecord();
        double finalPrice = arr[i]->calculateFinalPrice();
        cout<<"Final Price : "<<finalPrice<<endl;
        total = total + finalPrice;
    }
    cout<<"\nTotal Bill = "<<total<<endl;
    for(int i = 0; i < index; i++)
    {
        delete arr[i];
    }
    return 0;
}