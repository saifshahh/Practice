import matplotlib.pyplot as plt

x = ["python" , "c", "c++", "java"]
y = [85,70,60,82]
z = [20,30,40,50]
plt.xlabel("languages", fontsize = 20)
plt.ylabel("No")
plt.title("Nuces")
plt.bar(x,y, width = 0.4, edgecolor="r", linewidth=1, color='r', label = "p1")
plt.bar(x,z, width = 0.4, edgecolor="r", linewidth=1, color='b', label = "p2")
plt.legend()
plt.show()