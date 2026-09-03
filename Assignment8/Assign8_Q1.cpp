#include<iostream>
using namespace std;

class Distance
{
  private:
    int feet;
    int inches;
  public:
    Distance(void): feet(0), inches(0)
    {
    }
    Distance(int feet, int inches): feet(feet), inches(inches)
    {
    }
    void setFeet(int feet)
    {
        this->feet = feet;
    }
    int getFeet(void)
    {
        return this->feet;
    }
    void setInches(int inches)
    {
        this->inches = inches;
    }
    int getInches(void)
    {
        return this->inches;
    }
    Distance operator+(Distance d)
    {
        Distance temp;
        temp.feet = this->feet + d.feet;
        temp.inches = this->inches + d.inches;
        if(temp.inches >= 12)
        {
            temp.feet = temp.feet + temp.inches / 12;
            temp.inches = temp.inches % 12;
        }
        return temp;
    }
    Distance& operator++(void)
    {
        this->inches++;
        if(this->inches >= 12)
        {
            this->feet++;
            this->inches = this->inches - 12;
        }
        return *this;
    }
    friend Distance operator++(Distance &d, int);
    friend istream& operator>>(istream &in, Distance &d);
    friend ostream& operator<<(ostream &out, Distance &d);
};

Distance operator++(Distance &d, int)
{
    Distance temp = d;
    d.inches++;
    if(d.inches >= 12)
    {
        d.feet++;
        d.inches = d.inches - 12;
    }
    return temp;
}

istream& operator>>(istream &in, Distance &d)
{
    cout<<"Enter Feet : ";
    in>>d.feet;
    cout<<"Enter Inches : ";
    in>>d.inches;
    return in;
}

ostream& operator<<(ostream &out, Distance &d)
{
    out<<"Feet : "<<d.feet<<endl;
    out<<"Inches : "<<d.inches<<endl;
    return out;
}

int main()
{
    Distance d1, d2, d3;

    cout<<"\nEnter First Distance"<<endl;
    cin>>d1;

    cout<<"\nEnter Second Distance"<<endl;
    cin>>d2;

    d3 = d1 + d2;
    cout<<"\nAddition of Two Distances"<<endl;
    cout<<d3;

    ++d1;
    cout<<"\nAfter Prefix Increment of First Distance"<<endl;
    cout<<d1;

    d2++;
    cout<<"\nAfter Postfix Increment of Second Distance"<<endl;
    cout<<d2;

    return 0;
}