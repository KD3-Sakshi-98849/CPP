#include <iostream>
using namespace std;
class Car
{
private:
    unsigned paying;
    unsigned int nonpaying;
    double money;

public:
    Car(void)
    {
        this->paying=0;
        this->nonpaying=0;
        this->money=0;
    }
    void paying_car()
    {
        paying++;
        this->money += 0.50;
    }

    void non_paying_car()
    {
        nonpaying++;

    }
    void printOnConsole()
    {
        // int t1 = money + nonpaying;
        // cout << "paying car" << paying;
        // cout << "non paying car" << nonpaying;
        cout << "total :" << paying + nonpaying<<endl;

        cout << "toatl money:" << money<<endl;
    }
};

// int totatlAmout_paying_car(){
// int total=total+0.50;
// }

int menulist(void)
{
    int choice;
    cout << "0.Exit" << endl;

    cout << "\n1.if the car is paid" << endl;
    cout << "2.if the car is not paid" << endl;
    cout << "3 display" << endl;

    cout << "Enter choice";
    cin >> choice;

    return choice;
}
int main()
{
    Car c;
    int choice;
    while ((choice = menulist()) != 0)
    {
        switch (choice)
        {
        case 0:
            cout << "exist"<<endl;
            break;
        case 1:
            c.paying_car();
            break;

        case 2:
            c.non_paying_car();
            break;

        case 3:

            c.printOnConsole();
            break;
            
        default:
            cout << "invalid choice";
        }
    }
}