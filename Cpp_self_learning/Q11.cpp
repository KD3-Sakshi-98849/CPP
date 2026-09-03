#include<iostream>
using namespace std;

class node{
    int data;
    node *next;

    friend class linkedlist;

    public:
    node(int data):data(data),next(nullptr){

    }
};

class linkedlist{
    node *head;

    public:
    linkedlist():head(nullptr){

    }

    void add_first(int data){
        node *newnode=new node(data);

        newnode->next=head;
        head=newnode;
    }

    void add_last(int data){
        node *newnode=new node(data);

        if(head==nullptr){
            head=newnode;
            return;
        }

        node *ptr=head;

        while(ptr->next!=nullptr){
            ptr=ptr->next;
        }

        ptr->next=newnode;
    }

    void display(){
        node *ptr=head;

        while(ptr!=nullptr){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }

        cout<<endl;
    }

    ~linkedlist(){
        node *ptr=head;

        while(ptr!=nullptr){
            node *temp=ptr;
            ptr=ptr->next;
            delete temp;
        }

        head=nullptr;
    }
};

int main(){

    linkedlist l1;

    l1.add_first(20);
    l1.add_first(10);

    l1.add_last(30);
    l1.add_last(40);

    cout<<"Linked list : ";
    l1.display();
}