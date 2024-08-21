myList = []

size = int(input("Enter the size of the list: "))
max =0
for i in range(size):
    myList.append(int(input(f"Enter the element {i+1}: ")))

for j in myList:
    if j>max:
        max=j

print("The largest number in the list is: ", max)
