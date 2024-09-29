class Vehicle:
    def __init__(self, make, model, rental_price):
        self.make = make
        self.model = model
        self.rental_price = rental_price
        self.is_available = True
    
    def check_availability(self):
        return self.is_available
    
    def rent_vehicle(self):
        if self.is_available:
            self.is_available = False
        else:
            print(f"{self.make} {self.model} is not available for rent.")

    def return_vehicle(self):
        self.is_available = True
    
    def calculate_rental_cost(self, days):
        return days * self.rental_price
    
    def display_details(self):
        print(f"Vehicle: {self.make} {self.model}, Rental Price: PKR {self.rental_price} per day, "
              f"Available: {'Yes' if self.is_available else 'No'}")

class Car(Vehicle):
    def __init__(self, make, model, rental_price):
        super().__init__(make, model, rental_price)

class SUV(Vehicle):
    def __init__(self, make, model, rental_price):
        super().__init__(make, model, rental_price)

class Truck(Vehicle):
    def __init__(self, make, model, rental_price):
        super().__init__(make, model, rental_price)

class RentalReservation:
    def __init__(self, vehicle, customer, days):
        self.vehicle = vehicle
        self.customer = customer
        self.days = days
    
    def display_reservation_details(self):
        print(f"Customer: {self.customer.name}, Vehicle: {self.vehicle.make} {self.vehicle.model}, "
              f"Total Days: {self.days}, Total Cost: PKR {self.vehicle.calculate_rental_cost(self.days)}")
    
    def process_rental(self):
        if self.vehicle.check_availability():
            self.vehicle.rent_vehicle()
            self.customer.add_rental(self)
            print(f"Reservation confirmed for {self.customer.name}: {self.vehicle.make} {self.vehicle.model}")
        else:
            print(f"{self.vehicle.make} {self.vehicle.model} is not available for rent.")

class Customer:
    def __init__(self, name, contact_info):
        self.name = name
        self.contact_info = contact_info 
        self.rental_history = []
    
    def display_rental_history(self):
        if not self.rental_history:
            print(f"{self.name} has no rental history.")
        else:
            print(f"{self.name}'s Rental History:")
            for rental in self.rental_history:
                rental.display_reservation_details()
    
    def add_rental(self, rental_reservation):
        self.rental_history.append(rental_reservation)

car = Car("Toyota", "Supra", 400000)
suv = SUV("Honda", "Civic", 30000)
truck = Truck("Ford", "Mustang", 100000)

customer = Customer("Saif", "+923327851810")

days = 6 
reservation = RentalReservation(car, customer, days)

reservation.process_rental()

car.display_details()
suv.display_details()
truck.display_details()

car.return_vehicle()
customer.display_rental_history()
