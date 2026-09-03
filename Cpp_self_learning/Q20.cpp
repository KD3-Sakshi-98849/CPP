#include<iostream>
#include<memory>
using namespace std;

class Student{
    public:
    string name;

    Student(string name):name(name){
        cout<<"Student constructor called"<<endl;
    }

    ~Student(){
        cout<<"Student destructor called"<<endl;
    }

    void display(){
        cout<<"student name : "<<name<<endl;
    }
};

int main(){

    cout<<"Unique pointer : "<<endl;

    unique_ptr<Student> p1(new Student("Sourabh"));

    p1->display();

    unique_ptr<Student> p2=move(p1);

    if(p1==nullptr){
        cout<<"ownership transferred from p1 to p2"<<endl;
    }

    p2->display();


    cout<<"\nShared pointer : "<<endl;

    shared_ptr<Student> p3(new Student("Rahul"));

    shared_ptr<Student> p4=p3;

    cout<<"number of owners : "<<p3.use_count()<<endl;

    p3->display();
    p4->display();


    cout<<"\nWeak pointer : "<<endl;

    weak_ptr<Student> p5=p3;

    cout<<"number of owners after weak pointer : "<<p3.use_count()<<endl;

    if(auto temp=p5.lock()){
        temp->display();
    }
    else{
        cout<<"object does not exist"<<endl;
    }

}