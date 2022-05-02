# Class
class Person:
    
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def Introduction(self):
        print("Hello, my name is", self.name, ", and now I'm", self.age, "years old.")
        
# Inheritance
class Student(Person):
    
    def __init__(self, name, age, school):
        self.name = name
        self.age = age
        self.school = school
        
    def Print_School(self):
        print(self.name, "is studying at", self.school, "School")     
# ------------------------------------ Main ---------------------------------- #
if __name__ == '__main__':    
    
    person1 = Person("Tina", 25)
    person1.Introduction()
    
    student1 = Student("Henry", 15, "Apple")
    student1.Introduction()
    student1.Print_School()