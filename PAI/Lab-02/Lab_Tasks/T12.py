def Convert(list1,list2):
    dict = {}
    for i in range(len(list1)):
        dict[list1[i]] = list2[i]
    
    return dict

size = int(input('Enter the number elements for the list: '))
l1 = []
l2 = []
for i in range(size):
    l1.append(int(input(f'Enter the element {i+1} for list 1: ')))

for i in range(size):
    l2.append(int(input(f'Enter the element {i+1} for list 2: ')))

print(Convert(l1,l2))
