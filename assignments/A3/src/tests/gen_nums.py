import numpy as np

x = np.random.uniform(-10000, 10000, 10000)
np.savetxt("test3", x.astype(int), fmt='%i')
