characters = 0
with open(r'Q1.txt') as f:
    for line in f:
        characters += len(line.replace(' ','').replace('\t','').replace('\n',''))

print(characters)

