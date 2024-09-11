class Employee:
    
    def __init__(self):
        self.name = ""
        self.salary = 0.0
        self.tax = 2.0
    
    def get_data(self):
        self.name = input("Enter the name: ")
        self.salary = float(input("Enter the age: "))
        self.tax = float(input("Enter the tax percentage: "))
        
    def Salary_after_tax(self):
        amount = self.salary * (self.tax/100)
        return self.salary - amount
        
    def update_tax_percentage(self):
        self.tax = float(input("Enter the new tax percentage: "))
        
        
e1 = Employee()
e1.get_data()
print("Salary: ",e1.Salary_after_tax())
e1.update_tax_percentage()
print("Salary after updating tax percentage: ",e1.Salary_after_tax())
