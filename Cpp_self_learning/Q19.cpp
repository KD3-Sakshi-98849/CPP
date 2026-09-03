#include<iostream>
#include<list>
#include<algorithm>
#include<random>
using namespace std;

int main(){

    list<int> l1;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,100);

    for(int i=0;i<10;i++){
        l1.push_back(dis(gen));
    }

    cout<<"Original list : ";

    for(list<int>::iterator it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;

    cout<<"Reverse list : ";

    for(list<int>::reverse_iterator it=l1.rbegin();it!=l1.rend();it++){
        cout<<*it<<" ";
    }

    cout<<endl;

    for(list<int>::iterator it=l1.begin();it!=l1.end();it++){
        *it=*it+5;
    }

    cout<<"After incrementing by 5 : ";

    for(list<int>::const_iterator it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;

    l1.sort();

    cout<<"After sorting : ";

    for(list<int>::iterator it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }

    cout<<endl;
}