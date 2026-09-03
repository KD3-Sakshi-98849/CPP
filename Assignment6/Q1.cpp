#include <iostream>
using namespace std;
class Product
{
protected:
    int price;
    int id;
    string title;
    // double calculateBill;

public:
    Product() : id(0), title(" "), price(0) {}
    Product(int id, string title, int price) : id(id), title(title), price(price) {}
    virtual int CalculatePrice() = 0;

    virtual void AcceptRecord()
    {
        cout << "Enter id" << endl;
        cin >> id;
        cout << "Enter Title" << endl;
        cin >> title;
        cout << "Enter price" << endl;
        cin >> price;
    }
    virtual void PrintRecord()
    {
        cout << "id" << id << endl;
        cout << "Title" << title << endl;
        cout << "price" << price << endl;
    }
    virtual ~Product() {}
    // void printRecord()
    // {
    //     cout << "Calculate price:" << CalculatePrice << endl;
    // }
};
class Book : public Product
{
private:
    string author;

public:
    Book() : author(" ") {}
    Book(int id,
         string title,
         int calculateBill,
         int price, string author) : Product(id, title, price), author(author) {}

    void AcceptRecord()
    {
        Product::AcceptRecord();
        cout << "Enter Author:" << endl;
        cin >> author;
    }
    void PrintRecord()
    {
        Product::PrintRecord();
        cout << "Author:" << author << endl;
    }
    int CalculatePrice()
    {
        return price = price - (price * 0.10);
    }
};
class Tape : public Product
{
private:
    string artist;

public:
    Tape() : artist(" ") {}
    Tape(string artist, int id,
         string title,
         int calculateBill,
         int price) : Product(id, title, price), artist(artist) {}
    void AcceptRecord()
    {
        Product::AcceptRecord();
        cout << "Enter Artist";
        cin >> artist;
    }
    void PrintRecord()
    {
        Product::PrintRecord();
        cout << "Artist:" << artist << endl;
    }
    int CalculatePrice()
    {
        return price = price - (price * 0.05);
    }
};
int menulist()
{
    int choice;
    cout << "0.Exit" << endl;
    cout << "1.Book" << endl;
    cout << "2.Tape" << endl;
    cout << "3.Print Record" << endl;
    cout << "4.Calculate Bill" << endl;

    cout << "enter choice:" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    int index = 0;
    int price = 0;
    Product *ptrProduct[3];

    while ((choice = menulist()) != 0)
    {

        switch (choice)
        {

        case 1:
            if (index < 3)
            {
                ptrProduct[index] = new Book();
                ptrProduct[index]->AcceptRecord();
                index++;
            }
            break;

        case 2:
            if (index < 3)
            {
                ptrProduct[index] = new Tape();
                ptrProduct[index]->AcceptRecord();
                index++;
            }
            break;

        case 3:
            for (int i = 0; i < index; i++)
            {
                ptrProduct[i]->PrintRecord();
                // break;
            }
            break;

        case 4:
            price = 0;
            for (int i = 0; i < index; i++)
            {
                price += ptrProduct[i]->CalculatePrice();
                // break;
            }
            cout << "Final Bill=" << price << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    for (int i = 0; i < index; i++)
    {
        delete ptrProduct[i];
        ptrProduct[i] = NULL;
    }
    return 0;
}