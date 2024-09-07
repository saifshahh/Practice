characters = 0
with open(r'E:\Programming\Lab-03\file.txt') as f:
    for line in f:
        characters += len(line.replace(' ','').replace('\t','').replace('\n',''))

print(characters)
