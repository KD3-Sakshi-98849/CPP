#include<iostream>
using namespace std;
class student{
    private:
    int rollNo;
    int marks;
    static int highestMarks;
    public:
    student():rollNo(0),marks(0){
    }
    student(int rollNo,int marks):rollNo(rollNo),marks(marks){
        if(marks>highestMarks){
            student::highestMarks=marks;
        }
    }
    void getRecord(){
        cout<<"rollNo : "<<rollNo<<endl;
        cout<<"marks : "<<marks<<endl;
    }
    static void getHighest(){
        cout<<"highestMarks is : "<<highestMarks;
    }
};
int student::highestMarks=0;

int main(){
    int x;
    cout<<"enter no of students : ";
    cin>>x;
    cout<<endl;

    //dynamically allcate memory
    student *ptr=new student[x];

    for(int i=0; i<x; i++){
        int r,m;
        cout<<"enter roll no and marks resp : ";
        cin>>r>>m;
        cout<<endl;

        ptr[i]={r,m};
    }
    for(int i=0;i<x;i++){
        ptr[i].getRecord();
    }
    student::getHighest();

}