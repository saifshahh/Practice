class Vehicle:
    def __init__(self, seats):
        self.seats = seats
        
    def calculate(self):
        fare = self.seats*100
        return fare;
        
class Bus(Vehicle):
    def __init__(self, seats):
        self.seats = seats
        
    def calculate(self):
        fare = (self.seats*100) + (self.seats*100)*(10/100)
        return fare
    
b = Bus(2)
print("The total fare is: ",b.calculate())
