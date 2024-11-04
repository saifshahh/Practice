import matplotlib.pyplot as plt

y = [85,70,60,82]
x = [20,30,40,50]
sizes = [100, 200 ,300 , 400]
color = ['r', 'g', 'b', 'm']
plt.scatter(x,y , s = sizes, color = color, marker = '*', edgecolor = 'g')
plt.xlabel("X")
plt.ylabel("Y")
plt.title("X-Y Plane", fontsize=20)
plt.show()