def rep(word,right,wrong):
    try:
        with open('replacement_needed.txt','r') as f:
            content = f.read()
        
        temp = ''
        length = len(word)
        index = 0
        while index<length:
            if word[index] == wrong:
                temp += right
            else:
                temp += word[index]
            index += 1

        update = content.replace(word,temp)    
    except FileNotFoundError:
        print("No such file exists.")
    except IOError:
        print("Error! Unable to read file.")
    except Exception as e:
        print(str(e))

    try:
        with open('replacement_needed.txt','w') as f:
            f.write(update)
        print("File Updated")
        
    except FileNotFoundError:
        print("No such file exists.")
    except IOError:
        print("Error! Unable to read file.")
    except Exception as e:
        print(str(e))

rep('Xyed', 'S', 'X')
