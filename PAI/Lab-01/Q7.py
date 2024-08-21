value = input("Enter the string: ")
size = len(value)
newVal = ""

for i in range(size-1, -1, -1):
    newVal += value[i]

print("Reversed string: ", newVal)
