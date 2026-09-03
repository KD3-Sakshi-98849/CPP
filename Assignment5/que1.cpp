#include<iostream>
using namespace std;
class Date{
  private:
  int day,month,year;
  public:
  Date(void):day(0),month(0),year(0){ }//default
  Date(int day,int month ,int year):day(day),month(month),year(year){ }
  void acceptRecord(void){
    cout<<"enter Day :";
    cin>>day;
    cout<<"enter month :";
    cin>>month;
    cout<<"enter year :";
    cin>> year;
  }
  void displayRecord(void){
    cout<<day<<"/"<<month<<"/"<<year<<endl;

  }


};

class Person{
  private :
  string name;
  string address;
  Date birthdate; 
  public :
  Person (void):name(" "),address(" "){ }
  Person(string name ,string address ):name(name),address(address){ }
  Person(string name ,string address ,Date birthdate):name(name),address(address),birthdate(birthdate) { }
   Person(string name ,string address ,int day ,int month ,int year):name(name),address(address),birthdate(day,month,year) { }
   void acceptRecord(void){
    cout<<"Enter name :";
    cin>>name;
    cout<<"Enter address :";
    cin>>address;
    cout<<"enter birthdate :";
    this->birthdate.acceptRecord( );
   }
   void displayRecord( ){
    cout<<"Name :"<<name<<endl;
    cout<<"address : "<<address<<endl;
    cout<<" Birthdate :";
    this->birthdate.displayRecord( );

   }
  };
class Student{
  private: 
  int id;
  double marks ;
  string course;
  Date joining_date ;
  Date end_date;
  public:
  Student(void) : id(0),marks(0.0),course("") { }
  Student(int id ,double marks,string course ):id(id) ,marks(marks),course(course){ }
  Student(int id ,double marks,string course,Date joining_date,Date end_date ):id(id) ,marks(marks),course(course),joining_date (joining_date), end_date( end_date){ }
  void acceptRecord(void){
    cout<<"Enter id:";
    cin>>id;
    cout<<"Enter marks :";
    cin>>marks;
    cout<<"enter course :";
    cin>>course;
    cout<<"enter  joining_date:";
    this->joining_date.acceptRecord( );
    cout<<"enter  end_date:";
    this->end_date.acceptRecord( );

   }
   void displayRecord( ){
    cout<<"id :  "<<id<<endl;
    cout<<"marks : "<<marks<<endl;
    cout<<"course :"<<course<<endl;
    cout<<" joining_date :";
    this->joining_date.displayRecord( );
    cout<<"end_date :";
    this->end_date.displayRecord( );

   }
  


 };
int main( ){
  Person p;
  p.acceptRecord( );
  p.displayRecord( );
  Student s;
  s.acceptRecord( );
  s.displayRecord( );
  return 0;
}