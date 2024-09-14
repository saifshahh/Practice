class Restaurant:
    def __init__(self):
        self.menu = {} 
        self.booking = []  
        self.orders = []  

    def add(self):
        name = input('Enter the name of the item: ')
        price = float(input('Enter the price of the item: '))
        self.menu[name] = price
        print(f'Item "{name}" added successfully.')

    def book_tables(self):
        number = input('Enter the table number you want to book: ')
        if number not in self.booking:
            self.booking.append(number)
            print(f'Table {number} is successfully booked.')
        else:
            print(f'Sorry! Table {number} is already booked.')

    def customer_order(self):
        name = input('Enter the customer name: ')
        number = int(input('Enter the number of items to order: '))
        order = {}
        for _ in range(number):
            item = input('Enter the item name: ')
            if item in self.menu:
                amount = int(input(f'Enter amount for {item}: '))
                order[item] = amount
            else:
                print(f'Sorry, {item} is not available.')

        if order:
            self.orders.append({'customer': name, 'order': order})
            print(f"Order for {name} has been placed successfully.")

    def displayMenu(self):
        print("\n--- Menu ---")
        if self.menu:
            for item, price in self.menu.items():
                print(f"{item}: ${price}")
        else:
            print("Menu is empty.")

    def displayReservations(self):
        print("\n--- Table Reservations ---")
        if self.booking:
            print("Reserved Tables:", ', '.join(map(str, self.booking)))
        else:
            print("No tables are reserved.")

    def displayOrders(self):
        print("\n--- Customer Orders ---")
        if self.orders:
            for order in self.orders:
                print(f"Customer: {order['customer']}")
                for item, amount in order['order'].items():
                    print(f"{item}: {amount}x")
        else:
            print("No orders have been placed.")



restaurant = Restaurant()

restaurant.add()
restaurant.book_tables()
restaurant.customer_order()

restaurant.displayMenu()
restaurant.displayReservations()
restaurant.displayOrders()
