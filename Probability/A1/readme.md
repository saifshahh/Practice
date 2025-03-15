# Question 1
'''
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

data = {
    "ID": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    "Age": [28, 35, 42, 30, 50, 41, 29, 33, 45, 39],
    "Gender": ["Male", "Female", "Male", "Female", "Male", "Female", "Male", "Female", "Male", "Female"],
    "Department": ["IT", "HR", "Finance", "Marketing", "Sales", "HR", "IT", "Finance", "Sales", "Marketing"],
    "Salary ($)": [70000, 60000, 90000, 65000, 85000, 62000, 75000, 88000, 87000, 67000],
    "Experience (Years)": [3, 7, 12, 5, 15, 9, 4, 11, 14, 6],
    "Work Hours/Week": [40, 38, 45, 42, 50, 37, 39, 44, 48, 41],
    "Projects Completed": [5, 4, 6, 7, 8, 5, 6, 7, 9, 6],
    "Job Satisfaction (1-10)": [7, 8, 6, 9, 5, 7, 8, 6, 5, 8],
    "Training Hours": [20, 15, 18, 25, 12, 16, 22, 20, 14, 19],
    "Promotion Status": ["No", "Yes", "Yes", "No", "Yes", "No", "No", "Yes", "Yes", "No"]
}

df_emp = pd.DataFrame(data)

def employee_eda(df):
    print("Dataset Info:")
    print(df.info())
    print("\nSummary Statistics:")
    print(df.describe())
    print("\nDistinct Values in Department:")
    print(df["Department"].value_counts())
    print("\nDistinct Values in Promotion Status:")
    print(df["Promotion Status"].value_counts())
    
print("Missing Values:\n", df_emp.isnull().sum())

plt.figure(figsize=(10,5))
sns.histplot(df_emp["Salary ($)"], bins=8, kde=True, color='blue')
plt.title("Distribution of Salaries")
plt.xlabel("Salary ($)")
plt.ylabel("Frequency")
plt.show()

plt.figure(figsize=(8,5))
sns.countplot(x="Department", data=df_emp, palette='coolwarm')
plt.title("Number of Employees in Each Department")
plt.xlabel("Department")
plt.ylabel("Count")
plt.xticks(rotation=45)
plt.show()

plt.figure(figsize=(8,5))
sns.boxplot(y=df_emp["Experience (Years)"])
plt.title("Box Plot of Experience (Years)")
plt.ylabel("Years of Experience")
plt.show()
'''
