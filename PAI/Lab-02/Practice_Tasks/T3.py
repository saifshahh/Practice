def find_maximum(*numbers):
    max = numbers[0]
    for i in range(len(numbers)):
        if max < numbers[i]:
            max = numbers[i]
    return max

print(find_maximum(1,2,3,4,5,6))
