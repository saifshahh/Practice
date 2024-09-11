a = ["He", "th", "i", "sal"]
b = ["llo", "is", "s", "man"]
c = [a+b for a,b in zip(a,b)]
print(tuple(c))
