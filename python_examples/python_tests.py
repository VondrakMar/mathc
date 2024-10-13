import numpy as np
import matplotlib.pyplot as plt
# from scipy.special import sph_harm
# print(sph_harm(0,0,0,0))

def gaus2D(r_X,r_Y,alpha):
    return np.exp(-alpha * (r_x**2 + y**2))

from ase.build import molecule

h2o = molecule("H2O")
pos = h2o.get_positions()



# x = np.linspace(-5, 5, 200)
# y = np.linspace(-5, 5, 200)
# X, Y = np.meshgrid(x, y)


# alpha = 2.0

# Z = gaus2D(X,Y)
