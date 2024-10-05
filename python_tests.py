import numpy as np
# from scipy.special import sph_harm

# print(sph_harm(0,0,0,0))


# test for Gaussians

import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

res_A = open("src/testA.txt","r").readlines()
res_B = open("src/testB.txt","r").readlines()
res_new = open("src/test_new.txt","r").readlines()

x = []
y_A = []
y_B = []
y_new = []
for a in range(len(res_A)):
    line = res_A[a].split()
    x.append(float(line[0]))
    y_A.append(float(line[1]))
    line = res_B[a].split()
    y_B.append(float(line[1]))
    line = res_new[a].split()
    y_new.append(float(line[1]))

x = np.array(x)
y_A = np.array(y_A)
y_B = np.array(y_B)
y_new = np.array(y_new)

plt.plot(x,y_A)
plt.plot(x,y_B)
plt.plot(x,y_new)
plt.show()
plt.close()


    
def gaussian(r,r_A,alpha_A):
    dist = (r-r_A)**2
    # gaus_y = (2*alpha_A/np.pi)*np.exp(-alpha_A*dist)
    gaus_y = np.exp(-alpha_A*dist)
    return gaus_y

def prod_r(alpha_A,r_A,alpha_B,r_B):
    return (alpha_A*r_A+alpha_B*r_B)/(alpha_A + alpha_B)


def prod_pref(alpha_A,r_A,alpha_B,r_B):
    temp = (alpha_A*alpha_B)/(alpha_A + alpha_B)
    temp = np.exp(-temp*(r_A-r_B)**2)
    return temp

x = np.linspace(-1,9,1000)
r_A = 3;
r_B = 4;
sigma_A = 2;
sigma_B = 1.4;
alpha_A = 1/(np.sqrt(np.pi)*sigma_A);
alpha_B = 1/(np.sqrt(np.pi)*sigma_B);
y = gaussian(x,r_A,alpha_A)
y2 = gaussian(x,r_B,alpha_B)
y_prod = y*y2
r_prod = prod_r(alpha_A,r_A,alpha_B,r_B)
pref_prod = prod_pref(alpha_A,r_A,alpha_B,r_B)
distance = (x - r_prod)**2
y_prod_an = pref_prod*np.exp(-(alpha_A+alpha_B)*distance)
plt.plot(x,y)
plt.plot(x,y2)
plt.plot(x,y_prod)
plt.plot(x,y_prod_an)
plt.show()
