characters = 0
with open(r'file.txt') as f:
    for line in f:
        characters += len(line.replace(' ','').replace('\t','').replace('\n',''))

print(characters)
