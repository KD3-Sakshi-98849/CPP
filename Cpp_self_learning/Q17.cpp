#include<iostream>
#include<fstream>
using namespace std;

class Student{
    string name;
    int rollNo;
    int marks;

    public:
    Student():name(""),rollNo(0),marks(0){

    }

    Student(string name,int rollNo,int marks):name(name),rollNo(rollNo),marks(marks){

    }

    void display(){
        cout<<"name : "<<name<<endl;
        cout<<"rollNo : "<<rollNo<<endl;
        cout<<"marks : "<<marks<<endl;
    }

    void save(){
        ofstream fout("student.txt");

        fout<<name<<endl;
        fout<<rollNo<<endl;
        fout<<marks<<endl;

        fout.close();
    }

    void load(){
        ifstream fin("student.txt");

        fin>>name;
        fin>>rollNo;
        fin>>marks;

        fin.close();
    }
};

int main(){

    Student s1("Sourabh",1234,80);

    cout<<"Student object before saving : "<<endl;
    s1.display();

    s1.save();

    Student s2;

    s2.load();

    cout<<"\nStudent object after loading : "<<endl;
    s2.display();
}