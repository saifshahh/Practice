int_list = []
count=0
size = int(input("Enter the size of the list: "))

for i in range(size):
    int_list.append(int(input(f"Enter the number {i+1}: ")))

number = int(input("Enter the special number: "))

for j in range(size):
    if int_list[j-1]<number:
        del int_list[j-1]

print("Updated list: ")
for k in int_list:
    print("\n", k)


