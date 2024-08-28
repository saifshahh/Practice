def checker(str):
    if(str[-1]=='a' or str[-1]=='e' or str[-1]=='i' or str[-1]=='o' or str[-1]=='u'): print("Vowel")
    else: print("Consonant")

str = input("Enter the string: ")
checker(str)
