#include<iostream>
using namespace std;
class Leap{
    private:
    int month;
    int year;
    int date;

    public:
    void initDate()
   {
    date=0;
    month= 0;
    year=0;
   }
    // void acceptDateFromConsole();
    // void printDateOnConsole();


void acceptDateFromConsole()
{
    cout<<"month:";
    cin>>month;

    cout<<"year:";
    cin>>year;

    cout<<"date:";
    cin>>date;

}
void printDateOnConsole()
{
cout<<"month:"<<month<<endl;
cout<<"year"<<year<<endl;
cout<<"date"<<date<<endl;
}
bool isLeapYear()
{
if((year%4==0 && year % 100!=0)||
year%400==0)
 return true;
else
 return false;
}
};
int menulist (void){
    int choice;
cout<<"\n0.Exit"<<endl;
cout<<"1.init date"<<endl;
cout<<"2.Accept date"<<endl;
cout<<"3.print date"<<endl;
cout<<"4.check leap year"<<endl;
 cout << "Enter choice: ";
    cin >> choice;

    return choice;
}
int main(){
    int choice;
    Leap lp;
    while((choice=menulist())!=0){
        switch(choice){
             
              case 1:
                lp.initDate();
                cout << "Date initialized." << endl;
                break;

            case 2:
            lp.acceptDateFromConsole();
            break;

            case 3:
            lp.printDateOnConsole();
            break;

            case 4:
            if(lp.isLeapYear())
              cout<<"Leap year"<<endl;
            else
             cout<<"not leap year";
             break;

             default:
             cout<<"invalid chice"<<endl;
            }
        }
    }

// Leap lp;
// lp.initDate();
// lp.acceptDateFromConsole();
// lp.printDateOnConsole();
// lp.isLeapYear();
// return 0;
