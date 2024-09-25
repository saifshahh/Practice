import pandas as pd

movies = ["Movie A", "Movie B", "Movie C", "Movie D", "Movie E", "Movie F", "Movie G", "Movie H"]
revenue = [2500000, 3000000, 4000000, 500000, 3200000, 2800000, 3500000, 5000000]
moneySpent = [800000, 500000, 900000, 700000, 600000, 400000, 95000000, 300000]

df = pd.DataFrame({
    'Movies' : movies,
    'Revenue' : revenue,
    'Money Spent' : moneySpent
})

df.set_index('Movies', inplace=True)
print(df[(df['Revenue']>2000000) & (df['Money Spent']<1000000)])
