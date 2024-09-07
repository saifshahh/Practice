try:
    n1 = int(input('Enter the number 1: '))
    n2 = int(input('Enter the number 2: '))
    result = n1 / n2
    print(result)

except ZeroDivisionError as e:
    print('Division by zero is not possible!')
except ValueError as v:
    print('Error! non-integer value')
