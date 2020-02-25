import matplotlib.pyplot as plt
import numpy as np
import pandas
from sklearn import svm

data = pandas.read_csv('svm_data.csv')
y_train = data['y']
X_train = data[["x1","x2"]]


X = X_train.values
y = y_train.values

for i in range(len(X)):
    if(y[i] == 1):
        plt.plot(X[i,0],X[i,1], "ro")
    else:
        plt.plot(X[i,0],X[i,1], "b+")
        

out = svm.SVC(kernel="linear")
out.fit(X,y)
w  = out.coef_[0]
print(w)
b = out.intercept_[0]
print(b)
"""
A = []
B1 = []
for i in range(0,12):
    for j in range(0,12):
        product = 0
        product += w[0]*i + w[1]*j
        product+=b
        if(abs(product)<0.1):
            A.append(i)
            B1.append(j)
            
"""    
xx = np.linspace(0,12)
yy = (-b/w[1]) - ((xx*w[0])/w[1])
y1 = 1+yy
y2 = -1+yy
plt.plot(xx,yy,color="blue")
plt.plot(xx, y1, color="red")
plt.plot(xx, y2, color="red")
plt.show()
