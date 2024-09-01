def exchanger(c1,a,r,c2):
    result = a*r
    print(f"{c1} currency having amount {a} is converted into {c2} currency and the converted amount is {result}")

c1 = input('Enter the currency that needs to be converted: ')
c2 = input('Enter the currency in which it is converted: ')
rate = float(input('Enter the exchange rate: '))
amount = int(input('Enter the amount to be converted: '))

exchanger(c1,amount,rate,c2)
