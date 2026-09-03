#include<iostream>
using namespace std;

class Employee
{
protected:
    int id;
    double salary;
public:
    Employee(void): id(0), salary(0.0)
    {  }
    Employee(int id, double salary): id(id), salary(salary)
    {  }
    void setId(int id)
    {
        this->id = id;
    }
    int getId(void)
    {
        return this->id;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary(void)
    {
        return this->salary;
    }
    virtual void acceptRecord(void)
    {
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Salary : ";
        cin>>salary;
    }
    virtual void displayRecord(void)
    {
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
    virtual ~Employee(void)
    {  }
};
class Manager : virtual public Employee
{
private:
    double bonus;
public:
    Manager(void): bonus(0.0)
    {  }
    Manager(int id, double salary, double bonus): Employee(id, salary), bonus(bonus)
    {  }
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }
    double getBonus(void)
    {
        return this->bonus;
    }
    virtual void acceptRecord(void)
    {
        Employee::acceptRecord();
        acceptManager();
    }
    virtual void displayRecord(void)
    {
        Employee::displayRecord();
        displayManager();
    }
protected:
    void acceptManager(void)
    {
        cout<<"Enter Bonus : ";
        cin>>bonus;
    }
    void displayManager(void)
    {
        cout<<"Bonus : "<<bonus<<endl;
    }
};
class Salesman : virtual public Employee
{
private:
    double commission;
public:
    Salesman(void): commission(0.0)
    {  }
    Salesman(int id, double salary, double commission): Employee(id, salary), commission(commission)
    {  }
    void setCommission(double commission)
    {
        this->commission = commission;
    }
    double getCommission(void)
    {
        return this->commission;
    }
    virtual void acceptRecord(void)
    {
        Employee::acceptRecord();
        acceptSalesman();
    }
    virtual void displayRecord(void)
    {
        Employee::displayRecord();
        displaySalesman();
    }
protected:
    void acceptSalesman(void)
    {
        cout<<"Enter Commission : ";
        cin>>commission;
    }
    void displaySalesman(void)
    {
        cout<<"Commission : "<<commission<<endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager(void): Employee(), Manager(), Salesman()
    {  }
    SalesManager(int id, double salary, double bonus, double commission): Employee(id, salary), Manager(), Salesman()
    {
        setBonus(bonus);
        setCommission(commission);
    }
    virtual void acceptRecord(void)
    {
        Employee::acceptRecord();
        acceptManager();
        acceptSalesman();
    }
    virtual void displayRecord(void)
    {
        Employee::displayRecord();
        displayManager();
        displaySalesman();
    }
};
int menuList(void)
{
    int choice;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Manager"<<endl;
    cout<<"2. Salesman"<<endl;
    cout<<"3. SalesManager"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;
    return choice;
}
int main()
{
    int choice;
    Employee *arr[10];
    int index = 0;
    while(index < 10 && (choice = ::menuList()) != 0)
    {
        switch(choice)
        {
        case 1:
            arr[index] = new Manager();
            arr[index]->acceptRecord();
            index++;
            break;

        case 2:
            arr[index] = new Salesman();
            arr[index]->acceptRecord();
            index++;
            break;

        case 3:
            arr[index] = new SalesManager();
            arr[index]->acceptRecord();
            index++;
            break;

        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    for(int i = 0; i < index; i++)
    {
        cout<<"\nEmployee "<<i + 1<<endl;
        arr[i]->displayRecord();
    }
    for(int i = 0; i < index; i++)
    {
        delete arr[i];
    }
    return 0;
}