int_list = []
count=0
size = int(input("Enter the size of the list: "))

for i in range(size):
    int_list.append(int(input(f"Enter the number {i+1}: ")))

for j in int_list:
        count+=j

print("The sum of all the elements in the list is: ", count)

