import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
plt.hist(x , color='b', edgecolor = 'r')
plt.xlabel("X")
plt.ylabel("Y")
plt.title("Histogram")
plt.show()


import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
plt.hist(x,'auto', (0,100), color='skyblue', edgecolor='black')
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram with auto and range specified")
plt.show()


import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
plt.hist(x,bins = 'auto', color='skyblue', edgecolor='black')
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram with 'auto' Bins")
plt.show()

import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
l = [10,20,30,40,50,60]
plt.hist(x, bins=l, color='skyblue', edgecolor='black')
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram with 'l' Bins")
plt.show()


import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
plt.hist(x, bins='auto', edgecolor='green', histtype='step')
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram with type 'steps' ")
plt.show()


import matplotlib.pyplot as plt

x = [10, 20, 20, 22, 30, 35, 35, 40, 42, 50]
plt.hist(x, bins='auto', color='skyblue', edgecolor='black', orientation = 'horizontal' )
plt.xlabel("Value")
plt.ylabel("Frequency")
plt.title("Histogram with 'horizontal' oreintation")
plt.show()
