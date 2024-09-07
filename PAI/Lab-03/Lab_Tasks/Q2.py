try:
    with open(r'E:\Programming\Lab-03\file.txt', 'r') as f:
        text = f.read()
        text = text.replace("l", "h")
except Exception as e:
    print(str(e))

with open(r'E:\Programming\Lab-03\file.txt', 'w') as f:
    f.write(text)
    print(text)
