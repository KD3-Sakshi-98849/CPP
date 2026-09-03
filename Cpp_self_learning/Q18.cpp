#include<iostream>
using namespace std;

template<class T>
class Array{
    T *ptr;
    int size;

    public:
    Array(int size):size(size){
        ptr=new T[size];
    }

    Array(const Array &a){
        this->size=a.size;
        this->ptr=new T[size];

        for(int i=0;i<size;i++){
            this->ptr[i]=a.ptr[i];
        }
    }

    T& operator [](int index){
        return ptr[index];
    }

    Array& operator =(const Array &a){
        if(this!=&a){

            delete [] ptr;

            size=a.size;
            ptr=new T[size];

            for(int i=0;i<size;i++){
                ptr[i]=a.ptr[i];
            }
        }

        return *this;
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<ptr[i]<<" ";
        }

        cout<<endl;
    }

    ~Array(){
        delete [] ptr;
        ptr=nullptr;
    }
};

int main(){

    Array<int> a1(5);

    for(int i=0;i<5;i++){
        a1[i]=(i+1)*10;
    }

    cout<<"Array 1 : ";
    a1.display();

    Array<int> a2=a1;

    cout<<"Array 2 : ";
    a2.display();

    a2[2]=100;

    cout<<"Modified Array 2 : ";
    a2.display();
}