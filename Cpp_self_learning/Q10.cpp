#include<iostream>
using namespace std;

class Matrix{
    int a[2][2];

    public:
    Matrix(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                a[i][j]=0;
            }
        }
    }

    Matrix(int a[2][2]){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                this->a[i][j]=a[i][j];
            }
        }
    }

    Matrix operator +(Matrix m){
        Matrix temp;

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.a[i][j]=this->a[i][j]+m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator -(Matrix m){
        Matrix temp;

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.a[i][j]=this->a[i][j]-m.a[i][j];
            }
        }

        return temp;
    }

    Matrix operator *(Matrix m){
        Matrix temp;

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.a[i][j]=0;

                for(int k=0;k<2;k++){
                    temp.a[i][j]+=this->a[i][k]*m.a[k][j];
                }
            }
        }

        return temp;
    }

    void display(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int a[2][2]={{1,2},{3,4}};
    int b[2][2]={{5,6},{7,8}};

    Matrix m1(a);
    Matrix m2(b);

    cout<<"Matrix 1 : "<<endl;
    m1.display();

    cout<<"Matrix 2 : "<<endl;
    m2.display();

    Matrix m3=m1+m2;
    cout<<"Addition : "<<endl;
    m3.display();

    Matrix m4=m1-m2;
    cout<<"Subtraction : "<<endl;
    m4.display();

    Matrix m5=m1*m2;
    cout<<"Multiplication : "<<endl;
    m5.display();
}