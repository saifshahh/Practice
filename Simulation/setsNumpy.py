# import numpy as np

# a = np.array([1,1,1,1,2,2,3,3,3,4,5,6,7])
# x = np.unique(a)
# print(x)

# import numpy as np

# a = np.array([1,3,4,6])
# b = np.array([5,6,7])
# x = np.union1d(a,b)
# print(x)

# import numpy as np

# a = np.array([1,3,4,6])
# b = np.array([5,6,7])
# x = np.setdiff1d(a,b)
# print(x)

# import numpy as np

# a = np.array([1,3,4,6])
# b = np.array([5,6,7])
# x = np.intersect1d(a,b)
# print(x)

# import numpy as np

# a = np.array([1,3,4,6])
# b = np.array([5,6,7])
# x = np.setxor1d(a,b)
# print(x)

import numpy as np

a = np.array([1,3,4,6])
b = np.array([5,6,7])
x = np.isin(a,b)
print(x)
