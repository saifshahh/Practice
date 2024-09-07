num = int(input('Enter the length of lists: '))
l1 = []
l2 = []
dict = {}

print('Input for list 1: ')
for i in range(num):
    l1.append(int(input('Enter the number: ')))

print('Input for list 2: ')
for i in range(num):
    l2.append(int(input('Enter the number: ')))

for i in range(len(l1)):
    dict[l1[i]] = l2[i]

try:
    with open(r'E:\Programming\Lab-03\file2.txt', 'w') as fileObj:
       fileObj.write(str(dict))
except Exception as e:
    print(str(e))
