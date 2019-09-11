import math
import matplotlib.pyplot as plt
import numpy as np

def poisson(rate):
    x = 0
    pmf = []
    prob = 1
    while prob > 0.000000000000000000000000001:
        #goes till smallest positive number possible
        prob = math.exp(-rate) * pow(rate, x) / math.factorial(x)
        pmf.append(prob)
        x = x + 1
    n = np.arange(0,x)
    plt.bar(n,pmf,width = 1)
    plt.show()
    
#observe change in the shape of distribution as lamda increases   
#poisson(0.5)
poisson(2)
#poisson(5)
poisson(30)

