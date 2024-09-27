import numpy as np

a = np.random.rand(10)*10
b = np.random.rand(10)*10

np.savetxt("vec1",a)
np.savetxt("vec2",b)
print(np.dot(a,b))
