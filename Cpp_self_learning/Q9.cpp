#include<iostream>
using namespace std;
class Person{
      string name;
      int age;

      public:
      Person():name("sourabh"),age(23){

      }
      void display(){

      }
      virtual void work(){

      }
};
class Student: public Person{
      int marks;

      public:
      void study(){
           cout<<"studying "<<endl;
      }
      void work(){
        study();
      }
};
class Teacher: public Person{
      int salary;

      public:
      void study(){
           cout<<"teaching "<<endl;
      }
      void work(){
        study();
      }
};

int main(){
    Person * ptr=new Student;
    Person *ptr2=new Teacher;
    ptr->work();
    ptr2->work();
    delete ptr;
    delete ptr2;
    ptr=nullptr;
    ptr2=nullptr;
}
