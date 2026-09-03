#include<iostream>
using namespace std;

inline int factorial(int n){
    int fac=1;
    for(int i=1 ; i<=n; i++){
        fac*=i;
    }
    return fac;
}

inline int pow(int base , int expo){
    int ans=1;
    for(int i=1; i<=expo; i++){
        ans=base*ans;
    }
    return ans;
}
int main(){
    //factorial using inline function
    int x=5;
    cout<<"Factorial of "<<x<<" is : ";
    cout<<factorial(x);
    cout<<endl;

    //calculate power using inline function
    int base=3;
    int exponent=5;
    cout<<base<<" raised to the power "<<exponent<<" is : ";
    cout<<pow(base,exponent);

}