#include <iostream>
using namespace std;
class box
{
private:
    int length;
    int bridth;
    int height;

public:
    box()
    {
        this->length = 2;
        this->bridth = 2;
        this->height = 2;
    }

    box(int a)
    {
        this->length = a;
        this->bridth = a;
        this->height = a;
    }

    box(int a, int b, int c)
    {
        this->length = a;//refers to current obj//there is no local var thats why use this
        this->bridth = b;
        this->height = c;
    }

    void acceptRecord() //member fun
    {
        cout << "Enter length: ";
        cin >> length;

        cout << "Enter Breadth: ";
        cin >> bridth;

        cout << "Enter Height: ";
        cin >> height;
    }

    void printRecord()
    {
        cout << "length: " << length << endl;
        cout << "Breadth: " << bridth << endl;
        cout << "height: " << height << endl;
    }

    void calculateValue()
    {
        cout << "volume: " << length * bridth * height << endl;
    }
};

int menulist()
{
    int choice;

    cout << "\n1. Calculate value with default value" << endl;
    cout << "2. Calculate value with same value" << endl;
    cout << "3. Calculate value with different value" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    return choice;
}

int main()
{
    int choice;

    while ((choice = menulist()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            box b1;
            b1.printRecord();
            b1.calculateValue();
            break;
        }

        case 2:
        {
            int a;

            // cout << "Enter value: ";
            // cin >> a;

            box b2(a);
            b2.acceptRecord();
            b2.printRecord();
            b2.calculateValue();
            break;
        }

        case 3:
        {
            int a, b, c;

            // cout << "Enter length: ";
            // cin >> a;

            // cout << "Enter breadth: ";
            // cin >> b;

            // cout << "Enter height: ";
            // cin >> c;

            box b3(a, b, c);
            b3.acceptRecord();
            b3.printRecord();
            b3.calculateValue();
            break;
        }

        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}