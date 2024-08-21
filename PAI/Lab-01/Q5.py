int_list = []
size = int(input("Enter the size of the list: "))

for i in range(size):
    int_list.append(int(input(f"Enter the number {i+1}: ")))

number = int(input("Enter the special number: "))

newList = [j for j in int_list if number<=j]

print("Updated list: ", newList)



