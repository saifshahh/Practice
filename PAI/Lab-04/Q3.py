class Student:
    def __init__ (self, name, age):
        self.name = name
        self.age = age
        
    def Print_biodata(self):
        print(f"Name: {self.name}")
        print(f"Age: {self.age}")
        
s1 = Student("Saif", "18")
s1.Print_biodata()
