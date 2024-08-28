def averageMonth(myList):
    count=0
    average=0
    for i in range(len(myList)):
        count+=1
        average+=myList[i]

    return average/count


def max_min(myList):
    # maximum=max(myList)
    # minimum=min(myList)
    # return maximum,minimum
    max=0
    min=0
    for i in range(len(myList)):
        if(max<myList[i]): max = myList[i]
        if(min>myList[i]): min = myList[i]
    return max,min


def sorting(myList):
    for i in range(len(myList)-1):
        for j in range(i+1, len(myList)):
            if myList[i]>myList[j]:
                temp = myList[i]
                myList[i] = myList[j]
                myList[j] = temp
    return myList


def delete(myList):
    n=int(input("Enter the day you wish to remove the record of: "))
    myList.pop(n)
    return myList


myList = [-15, -5, 0, 7, 12, 18, 21, 24, 29, 32, 35, 37, 40, 43, 47, 50, -10, 2, 9, 15, 22, 28, 33, 39, 42, 46, -20, 6, 13, 20, 25]
print("Average temperature: ", averageMonth(myList))
print("Maximum and Minimum values of the list: ", max_min(myList))
print("List in ascending order: ", sorting(myList))
print(delete(myList))
