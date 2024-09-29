import pandas as pd

products = pd.read_csv('products.csv')
orders = pd.read_csv('orders.csv')

print("First 5 rows of products data:")
print(products.head())
print("\nLast 10 rows of products data:")
print(products.tail(10))

print("\nFirst 5 rows of orders data:")
print(orders.head())
print("\nLast 10 rows of orders data:")
print(orders.tail(10))

merged = pd.merge(orders, products, on='ProductID')

merged['Revenue'] = merged['Quantity'] * merged['Price']

total_revenue = merged['Revenue'].sum()
print(f"\nTotal Revenue: ${total_revenue}")

product_sales = merged.groupby('ProductName')['Quantity'].sum().reset_index()
top_5_best_selling = product_sales.sort_values(by='Quantity', ascending=False).head(5)
top_5_low_selling = product_sales.sort_values(by='Quantity', ascending=True).head(5)

print("\nTop 5 Best Selling Products:")
print(top_5_best_selling)
print("\nTop 5 Low Selling Products:")
print(top_5_low_selling)

top_5_best_selling_merged = pd.merge(top_5_best_selling, products, on='ProductName')
most_common_category = top_5_best_selling_merged['Category'].mode()[0]
print(f"\nMost Common Category Among Top 5 Best-Selling Products: {most_common_category}")

avg_price_per_category = products.groupby('Category')['Price'].mean().reset_index()
print("\nAverage Price of Products in Each Category:")
print(avg_price_per_category)

merged['Order Date'] = pd.to_datetime(merged['Order Date'], format='%m-%d-%Y')
merged['Year'] = merged['Order Date'].dt.year
merged['Month'] = merged['Order Date'].dt.month
merged['Day'] = merged['Order Date'].dt.day

revenue_per_day = merged.groupby(['Year', 'Month', 'Day'])['Revenue'].sum().reset_index()
revenue_per_month = merged.groupby(['Year', 'Month'])['Revenue'].sum().reset_index()
revenue_per_year = merged.groupby('Year')['Revenue'].sum().reset_index()

highest_revenue_day = revenue_per_day.loc[revenue_per_day['Revenue'].idxmax()]
highest_revenue_month = revenue_per_month.loc[revenue_per_month['Revenue'].idxmax()]
highest_revenue_year = revenue_per_year.loc[revenue_per_year['Revenue'].idxmax()]

print(f"\nDay with Highest Revenue: {highest_revenue_day}")
print(f"Month with Highest Revenue: {highest_revenue_month}")
print(f"Year with Highest Revenue: {highest_revenue_year}")

monthly_revenue_df = merged.groupby(['Year', 'Month'])['Revenue'].sum().reset_index()
print("\nTotal Revenue for Each Month:")
print(monthly_revenue_df)

null_values = merged.isnull().sum()
print("\nNull Values in the Data:")
print(null_values)
