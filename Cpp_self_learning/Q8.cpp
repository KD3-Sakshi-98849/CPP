#include<iostream>
using namespace std;
class Programmer{
      public:
      Programmer(){
        cout<<"const of P is called\n";
      }
      void work(){
        cout<<"work of P is called\n";
      }
};
class Teacher{
      public:
      Teacher(){
        cout<<"const of T is called\n";
      }
      void work(){
        cout<<"work of T is called\n";
      }
};
class ProgrammingTeacher:public Programmer, public Teacher{
      public:
      ProgrammingTeacher(){
        cout<<"const of PT is called\n";
      }
    //   void work(){
    //     cout<<"work of PT is called";
    //   }
};
int main(){
      ProgrammingTeacher PT1;
      //PT1.work(); //ambigious
      PT1.Teacher::work(); //this is working
}