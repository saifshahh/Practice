class Vehicle:
    def __init__(self,seating_capacity):
        self.seating_capacity = seating_capacity
    
    def fare(self):
        total = (self.seating_capacity * 100)
        print(f"Total fare will be {total}")

class Bus(Vehicle):
    def __init__(self,seating_capacity):
        self.seating_capacity = seating_capacity
    def fare(self):
        total = (self.seating_capacity * 100) + (self.seating_capacity * 100)*(10/100)
        print(f"Total fare will be {total}")

b = Bus(2)
b.fare()
