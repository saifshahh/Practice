def add(Stud,grade,name):
    Stud[name].append(grade) 
    return Stud

def avg(Stud,name):
    if name in Stud:
        total = Stud[name]
        avg = sum(total)/len(total)
        print(f"{name}'s average grade is {avg}.")
    else:
        print(f"Student {name} not found.")

def add_stud(Stud, name):
    if name not in Stud:
        Stud[name] = []
        print(f"Added new student {name} with an empty list of grades.")
    else:
        print(f"Student {name} already exists.")

def remove(Stud,name):
    if name in Stud:
        del Stud[name]
        return Stud
    else:
        print(f"Student {name} not found.")

Stud= {}
num = int(input('Enter the number of students: '))

for i in range(num):
    name = input(f'Enter the name of student {i + 1}: ')
    grades = []
    Num = int(input(f"Enter the number of grades for {name}: "))
    
    for j in range(Num):
        grades.append(int(input(f"Enter grade {j + 1}: ")))
    
    Stud[name] = grades

print(Stud)
print(add(Stud,33,'Syed'))
print(avg(Stud,'Saif'))
print(add_stud(Stud,'Rehman'))
print(remove(Stud,'Shah'))
