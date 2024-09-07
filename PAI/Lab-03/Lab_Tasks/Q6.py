s = str(input('Enter the sentence: '))

try:
    if s[len(s)-1] == '?':
        with open('questions.txt', 'w') as f:
            f.write(s)
            print('It is a question.. writing it to the file...')
    else:
        print('Not a question..')
        
except IOError as e:
    print(str(e))
except Exception as a:
    print(str(a))
