from abc import ABC, abstractmethod

class Employee(ABC):
    def __init__(self,name,salary):
        self.name = name
        self.salary = salary
       
    @abstractmethod
    def calculateBonus(self):
        pass
    
class Manager(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)
    def calculateBonus(self):
        self.salary += self.salary * 0.2
        print(f"Salary with Manager bonus is {self.salary}")
    
    def hire(self):
        print('We are Hiring!')
        
class Developer(Employee):
    def __init__(self, name, salary):
        super().__init__(name, salary)
    def calculateBonus(self):
        self.salary += self.salary * 0.1
        print(f"Salary with Developer bonus is {self.salary}")
    
    def writeCode(self):
        print('Programming in Progress!')
        
class SeniorManager(Manager):
    def __init__(self, name, salary):
        super().__init__(name, salary)
    def calculateBonus(self):
        self.salary += self.salary * 0.3
        print(f"Salary with Senior Manager bonus is {self.salary}")

m = Manager('Saif',1111)
d = Developer('Syed',2222)
s = SeniorManager('Rehman',3333)

m.calculateBonus()
m.hire()
d.calculateBonus()
d.writeCode()
s.calculateBonus()
