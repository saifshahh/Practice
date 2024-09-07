import json

dict = {}
myList = []
flag = False

try:
    n = int(input('Enter the number of people: '))
    for i in range(n):
        name = str(input('Enter your name: '))
        age = int(input('Enter your age: '))
        dict[name] = age

    with open('Q5.json','w') as f:
        json.dump(dict,f)

except FileNotFoundError:
    print("No such file exists")
except IOError:
     print("Error! Unable to read the file")
except Exception as e:
    print(str(e))

try:
    with open('Q5.json','r') as f:
        myList = json.load(f)
        max = myList[name]

        for i in myList:
            if max < myList[i]:
                max = myList[i]
        print('Max age is: ',max)

        for i in myList:
            for j in myList:
                if myList[i] == myList[j]:
                    temp = myList[i]
                    flag = True
                    break
            if flag:
                break  
        print('Same age is: ', temp)

except FileNotFoundError:
    print("No such file exsist")
except IOError:
    print("Error! Unable to read the file")
except Exception as e:
    print(str(e))
