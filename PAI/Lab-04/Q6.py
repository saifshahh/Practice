class BankAccount:
    
    def __init__(self, account_number, balance, date, name):
        self.account_number = account_number
        self.balance = balance
        self.date = date
        self.name = name
    
    def deposit(self, deposit):
        self.balance = self.balance + deposit
        print(f"You have deposited {deposit} $.")
    
    def withdraw(self, withdraw):
        self.balance = self.balance - withdraw
        print(f"You have withdrawed {withdraw} $.")
        
    def check_balance(self):
        print(f"Your current balance is {self.balance} $.")
        
    def display(self):
        print("\nAccount Details:")
        print(f"Name: {self.name}")
        print(f"Account Number: {self.account_number}")
        print(f"Date of opening: {self.date}")
        print(f"Balance: {self.balance}")
        
    
b1 = BankAccount(3773921, 10000000, "27 June 2023", "Syed Saif ur Rehman Shah")
b1.deposit(3333333)
b1.withdraw(777777)
b1.check_balance()
b1.withdraw(777777)
b1.check_balance()
b1.display()
