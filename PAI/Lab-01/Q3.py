int_list = []
count=0
size = int(input("Enter the size of the list: "))

for i in range(size):
    int_list.append(int(input(f"Enter the number {i+1}: ")))

for j in range(size):
    if int_list[j]%2==0:
        count+=1

print("The total number of even numbers in the list are: ", count)

