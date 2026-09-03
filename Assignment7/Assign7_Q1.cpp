#include<iostream>
#include<typeinfo>
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
    cout<<"\n";
    cout<<"0. EXIT"<<endl;
    cout<<"1. Add Manager"<<endl;
    cout<<"2. Add Salesman"<<endl;
    cout<<"3. Add SalesManager"<<endl;
    cout<<"4. Display Count of Employees"<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesmen"<<endl;
    cout<<"7. Display All SalesManagers"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;
    return choice;
}
int main()
{
    int choice;
    int index = 0;
    int manager = 0;
    int salesman = 0;
    int salesmanager = 0;
    Employee *arr[20];
    while((choice = ::menuList()) != 0)
    {
        switch(choice)
        {
        case 1:
        {
            arr[index] = new Manager();
            arr[index]->acceptRecord();
            index++;
            manager++;
            break;
        }
        case 2:
        {
            arr[index] = new Salesman();
            arr[index]->acceptRecord();
            index++;
            salesman++;
            break;
        }
        case 3:
        {
            arr[index] = new SalesManager();
            arr[index]->acceptRecord();
            index++;
            salesmanager++;
            break;
        }
        case 4:
        {
            cout<<" Employee Count "<<endl;
            cout<<"Manager : "<<manager<<endl;
            cout<<"Salesman : "<<salesman<<endl;
            cout<<"SalesManager : "<<salesmanager<<endl;
            break;
        }
        case 5:
        {
            if(manager == 0)
            {
                cout<<"No Manager Exist"<<endl;
            }
            else
            {
                cout<<" All Managers "<<endl;
                for(int i = 0; i < index; i++)
                {
                    if(typeid(*arr[i]) == typeid(Manager))
                    {
                        arr[i]->displayRecord();
                        cout<<endl;
                    }
                }
            }
            break;
        }
        case 6:
        {
            if(salesman == 0)
            {
                cout<<"No Salesman Exist"<<endl;
            }
            else
            {
                cout<<" All Salesmen "<<endl;

                for(int i = 0; i < index; i++)
                {
                    if(typeid(*arr[i]) == typeid(Salesman))
                    {
                        arr[i]->displayRecord();
                        cout<<endl;
                    }
                }
            }
            break;
        }
        case 7:
        {
            if(salesmanager == 0)
            {
                cout<<"No SalesManager Exist"<<endl;
            }
            else
            {
                cout<<" All SalesManagers "<<endl;

                for(int i = 0; i < index; i++)
                {
                    if(typeid(*arr[i]) == typeid(SalesManager))
                    {
                        arr[i]->displayRecord();
                        cout<<endl;
                    }
                }
            }
            break;
        }
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    for(int i = 0; i < index; i++)
    {
        delete arr[i];
    }
    return 0;
}