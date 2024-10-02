import pandas as pd

df = pd.read_csv("heart (1).csv")
df = df.rename(columns = {"sex":"Gender"})
df["Gender"][df["Gender"]==0] = "female"
df["Gender"][df["Gender"]==1] = "male"
print(df.groupby('Gender').mean())
print((df['chol']).max())
print(df)
