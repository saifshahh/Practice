with open('file.txt', 'r') as f:
    # lines = f.readlines()
    # for line in lines:
    #     if line.find('l') != -1:
    #         line.replace('l','h')

    text = f.read()
    text = text.replace("l", "h")

with open('file.txt', 'w') as f:
        f.write(text)
        print(text)
