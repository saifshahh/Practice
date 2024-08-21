physics = int(input("Enter the marks in physics: "))
chemistry = int(input("Enter the marks in chemistry: "))
maths = int(input("Enter the marks in maths: "))

mydict = {'physics': physics, 'chemistry': chemistry, 'maths': maths}
result = 0
total = 300

for key in mydict:
    result += mydict[key]

print("Average: ", result/3)
print("Percentage: ", (result/total)*100)
