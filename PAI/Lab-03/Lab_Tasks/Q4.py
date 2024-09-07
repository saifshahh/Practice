name = str(input('Enter your Name: '))
cnic = int(input('Enter your CNIC Number: '))
age = int(input('Enter your Age: '))
salary = int(input('Enter your Salary: '))

myList = [name,cnic,age,salary]

try:
    with open(r'E:\Programming\Lab-03\file3.txt','a') as f:
        for i in range(len(myList)):
            f.write(str(f"{myList[i]}\n"))
except Exception as nothing:
    print(str(nothing))

n = int(input('Enter your Contact Number: '))

try:
    with open(r'E:\Programming\Lab-03\file3.txt','a') as f:
        f.write(str(n))
except Exception as nothing:
    print(str(nothing))
