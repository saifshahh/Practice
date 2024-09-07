characters = 0
try:
    with open(r'E:\Programming\Lab-03\file.txt') as f:
        for line in f:
            characters += len(line.replace(' ','').replace('\t','').replace('\n',''))
except Exception as e:
    print(str(e))
    
print(characters)
