physics = int(input("Enter the marks in physics: "))
chemistry = int(input("Enter the marks in chemistry: "))
maths = int(input("Enter the marks in maths: "))

mydict = {'physics': physics, 'chemistry': chemistry, 'maths': maths}
result = 0
maximum = 0
maxKey = ''

for key, i in mydict.items():
    result += i
    if maximum < i:
        maxKey = key

print("Average: ", result/3)
print("Max Marks: ", maxKey)
