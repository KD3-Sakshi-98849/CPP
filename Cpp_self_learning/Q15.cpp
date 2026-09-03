#include<iostream>
using namespace std;

namespace college{
    class Student{
        private:
        string name;
        int Id;
        int marks;
        public:
        Student():name(""),Id(0){
            //cout<<"default values are assigned . please assign values "<<endl;
        }
        Student(string name,int Id,int marks):name(name),Id(Id),marks(marks){

        }

        void getName(){
            cout<<"student name : "<<name<<endl;
        }
        void getId(){
            cout<<"student Id : "<<Id<<endl;
        }
        void setMarks(int marks){
            if(marks<0){
                throw ("marks cant be -ve");
            }
             this->marks=marks;
        }
        void setName(){
            cout<<"Enter student name : ";
            cin>>this->name;
        }
        void setId(){
            cout<<"Enter student Id : ";
            cin>>this->Id;
        }

        void display(){
            cout<<"student name : "<<name<<endl;
            cout<<"student Id : "<<Id<<endl;
        }
    };
    class Teacher{
        private:
        string name;
        int Id;
        public:
        Teacher():name(""),Id(0){
            //cout<<"default values are assigned . please assign values "<<endl;
        }
        Teacher(string name,int Id):name(name),Id(Id){

        }
        void getName(){
            cout<<"teacher name : "<<name<<endl;
        }
        void getId(){
            cout<<"teacher Id : "<<Id<<endl;
        }

        void setName(){
            cout<<"Enter teacher name : ";
            cin>>this->name;
        }
        void setId(){
            cout<<"Enter teacher Id : ";
            cin>>this->Id;
        }

        void display(){
            cout<<"teacher name : "<<name<<endl;
            cout<<"teacher Id : "<<Id<<endl;
        }
    };
}
int main(){
    try{
    college::Student s1;
    college::Student s2("Sourabh",1234,80);
    s1.setName();
    s1.setId();
    s1.display();
    s2.display();
    s1.setMarks(-1);

    college::Teacher t1;
    college::Teacher t2("Sourabh",1234);
    t1.setName();
    t1.setId();
    t2.display();
    t1.display();
    }
    catch(string s){
        cout<<s;
    }
}