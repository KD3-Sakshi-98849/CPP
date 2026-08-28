#include<iostream>
using namespace std;
class Time
{
    private:
    int hrs;
    int mins;
    int secs;

    public:
    Time(void):hrs(0),mins(0),secs(0)
    { }
    Time(int hrs,int mins,int secs):hrs(hrs),mins(mins),secs(secs)
    { }

    void setHrs(int hrs){
        this->hrs=hrs;
    }
    void setMins(int mins){
        this->mins=mins;
    }
    void setSecs(int secs){
        this->secs=secs;
    }
    void getHrs(void){
        cout<<"hrs : "<<hrs<<endl;
    }
    void  getMins(void){
         cout<<"MIN : "<<mins<<endl;
    }
    void getsecs(void){
       cout<<"Secs : "<<secs<<endl;
    }   

    void accept(){
        cout<<"enter hrs,mins,secs:";
        cin>>hrs>>mins>>secs;
    }
    void display(void){
        cout<<hrs<<":"<<mins<<":"<<secs<<endl;
    }
 
};
   int menulist(){
    int choice;
    cout<<"1.Add Time"<<endl;
    cout<<"2.Display All Time"<<endl;
    cout<<"3.Display only hrs of all time objects"<<endl;

    cout<<"Enter choice"<<endl;
    cin>>choice;
     
    return choice;

    
}
int main(){
    int choice;
    int n;
    cout<<"how many enter you object : ";
    cin>>n;

    Time *arr=new Time[n];
    

//    Time t;
   while ((choice=menulist())!=0){
    switch(choice)
    { 
        case 1:
        for(int i=0;i<n;i++){
           arr[i].accept();
        }
        
        break;

        case 2:
        for(int i=0;i<n;i++){
           arr[i].display();
        }cout<<endl;
        break;

        case 3:
        for(int i=0;i<n;i++){
           arr[i].getHrs();
        }cout<<endl;
        break;
       
        default:
        cout<<"invalid choice";
        break;
    }
    
   }

   delete[] arr;
   arr =NULL;
   return 0;
    
}