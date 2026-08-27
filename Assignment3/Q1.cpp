#include<iostream>
using namespace std;
class Cylinder{
    private:
    double radius;
    double height;
    double total_vloume;
    static double PI;

    public:
    Cylinder(void):radius(0),height(0){
    }

    Cylinder(double radius, double height)
     {
        this->radius=radius;
        this->height=height;
    }

    void setRadius(double radius) 
    {
      this->radius=radius;
      
    }
    void getRadius()
     {
        cout<<"Radius: "<<radius<<endl;
    }
   
    void setHeight(double height)
    {
     this->height=height;
    }
   void getHeight()
    {
      cout<<"Height; "<<height<<endl;
    } 
   
     void accept(){
      cout<<"enter radius ";
      cin>>radius;

      cout<<"enter height";
      cin>>height;
    }
    void display(){
       cout<<"radius="<<radius<<endl;
      //  cout<<<"radius 2="<<r2<<endl;
       cout<<"height"<<height<<endl;
    }
    
  double calculateVolume(void)
  {
   total_vloume= PI* radius * radius *height;
   cout<<"volume: "<<total_vloume<<endl;
   return total_vloume;
  }

};
double Cylinder::PI=3.14;
int main(){
Cylinder c;
c.getRadius();
c.getHeight();
c.setRadius(5);
c.setHeight(5);
c.display();
c.calculateVolume();
Cylinder c2(10,20);
c2.getRadius();
c2.getHeight();
c2.calculateVolume();

return 0;


}