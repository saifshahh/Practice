physics = int(input("Enter the marks in physics: "))
chemistry = int(input("Enter the marks in chemistry: "))
maths = int(input("Enter the marks in maths: "))

mydict = {'physics': physics, 'chemistry': chemistry, 'maths': maths}
result=0
max=0
maxKey=0

for key, i in mydict.items():
    result += i
    if max<i:
        maxKey = key

print("Average: ", result/3)
print("Max Marks: ", maxKey)
