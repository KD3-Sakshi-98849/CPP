#include<iostream>
using namespace std;

//swap using call by value
void swapByValue(int a, int b){
    int temp=a;
    a=b;
    b=temp;
}

//swap using call by refrence
void swapByRefrence(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int x=10;
    int y=20;

    cout << "Before swapByValue: ";
    cout << x << " " << y << endl;

    swapByValue(x,y);

    cout << "After swapByValue: ";
    cout << x << " " << y << endl;

    cout << "\nBefore swapByReference: ";
    cout << x << " " << y << endl;

    swapByRefrence(x,y);

    cout << "After swapByReference: ";
    cout << x << " " << y << endl;

}