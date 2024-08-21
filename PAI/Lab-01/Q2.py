n1 = int(input("Number 1: "))
n2 = int(input("Number 2: "))
operation = input("Operation: ")

match operation:

    case '+':
        print("Result: ", n1+n2)

    case '-':
        print("Result: ", n1-n2)

    case '*':
        print("Result: ", n1*n2)

    case '/':
        print("Result: ", n1/n2)

    case _:
        print("Invalid operator.")
