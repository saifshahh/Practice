import numpy as np

data_type = [('name', 'U10'), ('class', 'i4'), ('height', 'f4')]

students = np.array([
    ('Alice', 10, 5.5),
    ('Bob', 9, 5.9),
    ('Charlie', 10, 5.4),
    ('David', 8, 5.7),
    ('Eve', 9, 5.8)
], dtype=data_type)

sorted_students = np.sort(students, order=['class', 'height'])

print("Sorted Student Data:\n", sorted_students)
