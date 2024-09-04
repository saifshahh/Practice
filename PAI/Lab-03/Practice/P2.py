with open(r'practice.txt','a') as writeFile:
    writeFile.write('\nWritten to the file')

with open(r'practice.txt') as openFile:
    content = openFile.read()
print(content)
