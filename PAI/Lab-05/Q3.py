class Account:
    __account_no = 0
    __account_bal = 0
    __security_code = ''
    
    def __init__(self,account_no,account_bal,security_code):
        self.__account_no = account_no
        self.__account_bal = account_bal
        self.__security_code = security_code
    
    def info(self):
        print(f"Account Number: {self.__account_no}\nBalance: {self.__account_bal} dollars\nSecurity Code: {self.__security_code}")
    
acc = Account(111,3000,'0032')
acc.info()
