#include<iostream>
using namespace std;
class strings{
    public:
    static int strlen(string str){
        int count=0;
        while(static_cast<int>(str[count])!=0){
             count++;
        }
        return count;
    }
    //static void strcpy(string)
    static void
};

int main(){
    string str="anuj";

    cout<<"lenght : "<<strings::strlen(str);

    
}