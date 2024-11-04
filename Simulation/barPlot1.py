import matplotlib.pyplot as plt

x = ["python" , "c", "c++", "java"]
y = [85,70,60,82]
c = ["r", "g", "b", "y"]
plt.xlabel("languages", fontsize = 20)
plt.ylabel("No")
plt.title("Nuces")
plt.bar(x,y, width = 0.4, edgecolor="m", linewidth=3, color=c, label = "legend")
plt.legend()
plt.show()