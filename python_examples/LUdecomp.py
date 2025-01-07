import numpy as np
from scipy.linalg import lu

matrix = np.array([
    [4, 3, 2],
    [6, 3, -1],
    [2, 1, 5],
    [8, 7, 9]
])
'''
P, L, U = lu(matrix)#, permute_l=True)
print(P)
print(L)
print(U)
'''
L,U = lu(matrix,permute_l=True)
print(L)
print(U)
