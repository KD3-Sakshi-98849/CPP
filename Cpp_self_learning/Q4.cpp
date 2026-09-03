#include<iostream>
using namespace std;
class Laptop{
      private:
      int brandId;
      int price;
      public:
      Laptop():brandId(1),price(50000){
        cout<<"constructor is called"<<endl;
      }
      ~Laptop(){
        cout<<"destructor is called"<<endl;
      }

      void display(){
        cout<<"brandId : "<<this->brandId<<endl;
        cout<<"price : "<<this->price<<endl;
      }
};

int main(){
    Laptop l1;
    l1.display();
}