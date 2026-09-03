#include<iostream>
using namespace std;
class Product{
      private:
      string title;
      int price;

      public:
      virtual void accept(){
        cout<<"enter title : ";
        cin>>this->title;
        cout<<"enter price : ";
        cin>>this->price;
      }
      virtual void display(){
        cout<<"title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
      }
};
class Book: public Product{
      int pages;
      public:
      void accept(){
        Product::accept();
        cout<<"Enter Pages : ";
        cin>>this->pages;
      }
      void display(){
        Product::display();
        cout<<"pages : "<<pages<<endl;
        //cin>>this->pages;
      }
};
class Tape: public Product{
      int playtime;
      public:
      void accept(){
        Product::accept();
        cout<<"Enter Playtime : ";
        cin>>this->playtime;
      }
      void display(){
        Product::accept();
        cout<<"Playtime : "<<playtime<<endl;
        //cin>>this->pages;
      }
};

int main(){
      Product* arr[5];
      int choice;
      for(int i=0; i<5; i++){
        cout<<"1.Book \n2.Tape\n Enter choice\n";
        cin>>choice;
        switch(choice){
            case 1:{
                arr[i]=new Book;
                arr[i]->accept();
                break;
            }
            case 2:{
                arr[i]=new Tape;
                arr[i]->accept();
                break;
            }
        }
      }
      for(int i=0;i<5;i++){
        arr[i]->display();
        cout<<endl;
        delete arr[i];
        arr[i]=nullptr;
      }
}