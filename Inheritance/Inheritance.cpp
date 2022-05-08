
#include <iostream>

using namespace std;

class AbstractEmployee{
    // void AskForPromotion(); // virtual function, can be or can not be overwritten
    virtual void AskForPromotion() = 0; // pure virtual function, must be overwritten
};

class Employee:AbstractEmployee{
private:    // private is default
    // string Name;
    int Age;
    string Job;
protected:
    string Name;
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
    
    void AskForPromotion(){ // pure virtual function, must be overwritten
        if (Age >= 30)
            cout << Name << " got promoted !" << endl;
        else
            cout << Name << ", sorry, no promotion for you." << endl;
    };
    
    // polymorphism, virtual function
    // it will check is there any Work() in the child class
    // if yes, access that function
    virtual void Work(){    
        cout << Name << " is checking email..." << endl;
    }
    
};  // Don't forget semicolon !!!

class Developer:public Employee{
public:
    string ProgrammingLanguage;
    
    Developer (string name, int age, string job, string programminglanguage)
        : Employee(name, age, job)
    {
        ProgrammingLanguage = programminglanguage;
    }
    
    void FixBug(){
        // cout << GetName() << " fix bug using " << ProgrammingLanguage << endl;   // when Name is in private
        cout << Name << " fix bug using " << ProgrammingLanguage << endl;   // only when Name move to """protected"""
    }
    
    void Work(){    
        cout << Name << " is writing " << ProgrammingLanguage << "..." << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Emily", 24, "Writer");
    Employee employee2 = Employee("Henry", 32, "Teacher");
    
    Developer developer1 = Developer("Amy", 30, "Firmware Engineer", "C++");
    developer1.FixBug();
    developer1.IntroduceYourself(); // need to be Developer:"""public""" Employee so that can access the function
    developer1.AskForPromotion();
    
    developer1.Work();  // no matter the function is virtual or not, it will be executed as we expected
    
    // The most common use of polymorphism is when a parent class reference is unsigned
    // to refer to a child class object
    Employee *e = &developer1;
    e -> Work();
    
    return 0;
}

