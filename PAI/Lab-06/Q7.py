import pandas as pd
df = pd.read_excel("employee.xlsx")
year = df[df["Year_Joined"]==2018]
print(year)
