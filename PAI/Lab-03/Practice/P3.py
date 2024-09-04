with open('practice.txt','r+') as readWrite:
    readWrite.write('New data')

    readWrite.seek(0)
    content= readWrite.read()
    print(content)
