# Class
class Person:
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def Introduction(self):
        print("Hello, my name is", self.name, ", and now I'm", self.age, "years old.")
        
    def Print_Age(self):
        print(self.name, "is", self.age, "years old.")
        
# Inheritance
class Student(Person):
    
    def __init__(self, name, age, school):
        Person.__init__(self, name, age)
        # self.name = name
        # self.age = age
        self.school = school
        
    def Print_School(self):
        print(self.name, "is studying at", self.school, "School")     
        
    def Print_Age(self):
        super().Print_Age()
        print(self.name, "is a", self.age, "year-old stuednt.")
        
# Multiple Inheritance
class Class_Leader(Student, Person):
    
    def __init__(self, name, age, school):
        Person.__init__(self, name, age)
        Student.__init__(self, name, age, school) 
        
    def Print_School(self):
        # Method Overriding
        print(self.name, "is a class leader at", self.school, "School")   
        
# ------------------------------------ Main ---------------------------------- #
if __name__ == '__main__':    
    
    person1 = Person("Tina", 25)
    person1.Introduction()
    person1.Print_Age()
    
    print("")
    student1 = Student("Henry", 15, "Apple")
    student1.Introduction()
    student1.Print_School()
    student1.Print_Age()
    
    print("")
    print(issubclass(Student, Person))
    print(issubclass(Person, Student))
    
    print("")
    leader1 = Class_Leader("Luna", 14, "Banana")
    leader1.Introduction()
    leader1.Print_Age() # find out the function at class Student first !
    leader1.Print_School()
    
    print("")
    print(issubclass(Class_Leader, Person))
    print(issubclass(Class_Leader, Student))
    