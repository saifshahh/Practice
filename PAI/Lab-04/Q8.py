class Account:
    __account_no = 0
    __account_bal = 0
    __security_code = ''
    
    def __init__(self,account_no,account_bal,security_code):
        self.__account_no = account_no
        self.__account_bal = account_bal
        self.__security_code = security_code
    
    def info(self):
        print(f"Account No: {self.__account_no} is having {self.__account_bal} dollars. The security code of this account is {self.__security_code}")
    
acc = Account(123,5000,'0012')
acc.info()
