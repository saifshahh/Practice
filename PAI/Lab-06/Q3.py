import pandas as pd
import numpy as np

exam_data = {
    'Name': ['Anastasia', 'Dima', 'Katherine', 'James', 'Emily', 'Michael',
    'Matthew', 'Laura', 'Kevin', 'Jonas'],
    'Score': [12.5, 9, 16.5, np.nan, 9, 20, 14.5, np.nan, 8, 19],
    'Attempts': [1, 3, 2, 3, 2, 3, 1, 1, 2, 1],
    'Qualify': ['yes', 'no', 'yes', 'no', 'no', 'yes', 'yes', 'no', 'no', 'yes'] 
    }
labels = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j']

df = pd.DataFrame(index=labels, data=exam_data)
print(df)
