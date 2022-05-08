
#include <iostream>

using namespace std;

class AbstractEmployee{
    // void AskForPromotion(); // virtul function, can be or can not be overwritten
    virtual void AskForPromotion() = 0; // pure virtul function, must be overwritten
};

class Employee:AbstractEmployee{
private:    // private is default
    string Name;
    int Age;
    string Job;
public:

    void IntroduceYourself(){
        cout << Name << " is " << Age << " years old, and he/she is a " << Job << "." << endl;
    }
    
    string GetName(){
        return Name;
    }
    
    int GetAge(){
        return Age;
    }
    
    string GetJob(){
        return Job;
    }
    
    Employee (string name, int age, string job){
        Name = name;
        Age = age;
        Job = job;
    }
    
    void AskForPromotion(){ // pure virtul function, must be overwritten
        if (Age >= 30)
            cout << Name << " got promoted !" << endl;
        else
            cout << Name << ", sorry, no promotion for you." << endl;
    };
    
};  // Don't forget semicolon !!!

int main()
{
    Employee employee1 = Employee("Emily", 24, "Writer");
    
    employee1.IntroduceYourself();
    // valid only when Name, Age, Job is in public
    // cout << employee1.Name << " is " << employee1.Age << " years old, and he/she is a " << employee1.Job << "." << endl;    
    // Because Name, Age, Job is in private, cannot access directly
    cout << employee1.GetName() << " is " << employee1.GetAge() << " years old, and he/she is a " << employee1.GetJob() << "." << endl;    
    
    
    Employee employee2 = Employee("Henry", 32, "Teacher");
    employee2.IntroduceYourself();
    
    // pur virtual function
    employee1.AskForPromotion();
    employee2.AskForPromotion();
    
    return 0;
}

