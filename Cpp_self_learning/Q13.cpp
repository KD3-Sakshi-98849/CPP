#include<iostream>
using namespace std;
class Payment{
      public:
      virtual void makePayment(double amount){

      }
};
class CreditCard : public Payment{
      public:
      void makePayment(double amount){
           cout<<amount<<" transaction successful"<<endl;
      }
};
class UPI: public Payment{
      public:
      void makePayment(double amount){
           cout<<amount<<" transaction successful"<<endl;
      }
};
class Cash: public Payment{
      public:
      void makePayment(double amount){
           cout<<amount<<" transaction successful"<<endl;
      }
};

class Paymentfactory{
    public:
    static Payment* create(int i){
          if(i==1){
            return new CreditCard;
          }
          else if(i==2){
            return new UPI;
          }
          else{
            return new Cash;
          }
    }
};
int main(){
    Payment* ptr=Paymentfactory::create(1);
    ptr->makePayment(500);
}