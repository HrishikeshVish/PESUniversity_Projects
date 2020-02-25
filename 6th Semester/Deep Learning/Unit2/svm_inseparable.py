import matplotlib.pyplot as plt
import numpy as np
import pandas
from sklearn import svm
from kernelsvm import make_meshgrid,  plot_contours
data = pandas.read_csv('svm_data_kernel.csv')
y_train = data['y']
X_train = data[["x1","x2"]]


X = X_train.values
y = y_train.values

for i in range(len(X)):
    if(y[i] == 1):
        plt.plot(X[i,0],X[i,1], "ro")
    else:
        plt.plot(X[i,0],X[i,1], "b+")
        

#out = svm.SVC(kernel="rbf", C=1)
#out = svm.SVC(kernel="rbf", gamma=10, C=1)
#out = svm.SVC(kernel="rbf", gamma=20, C=1)
out = svm.SVC(kernel="rbf", gamma=.5, C=1)

out.fit(X,y)
xx = np.linspace(0,12)
yy = np.linspace(0,12)
xx, yy = make_meshgrid(xx, yy)
print(xx, yy)
plot_contours(out, xx,yy)
