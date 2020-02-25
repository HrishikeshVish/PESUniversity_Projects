import matplotlib.pyplot as plt
import numpy as np
import pandas
from sklearn import svm
from kernelsvm import make_meshgrid, plot_contours

data = pandas.read_csv('multi_class_svm.csv')
y_train = data['y']
X_train = data[["x1", "x2"]]

X = X_train.values
y = y_train.values

for i in range(len(X)):
    if (y[i] == 1):
        plt.plot(X[i,0],X[i,1],"ro")
    if(y[i] == 2):
        plt.plot(X[i,0],X[i,1],"b+")
    if(y[i] == 3):
        plt.plot(X[i,0],X[i,1],"y*")
    if(y[i] == 4):
        plt.plot(X[i,0],X[i,1],"g^")


y2 = y.copy()
y3 = y.copy()
y4 = y.copy()
y5 = y.copy()

for i in range(len(y2)):
    if(y2[i] !=1):
        y2[i] = 2
out1 = svm.SVC(kernel="linear")
out1.fit(X,y2)
for i in range(len(y3)):
    if(y3[i] !=2):
        y3[i] = 1
out2 = svm.SVC(kernel="linear")
out2.fit(X,y3)
print(y4)
for i in range(len(y4)):
    if(y4[i] == 3):
        continue
    if(y4[i] !=3):
        y4[i] = 1
print(y4)
out3 = svm.SVC(kernel="linear")
out3.fit(X,y4)
for i in range(len(y5)):
    if(y5[i] !=4):
        y5[i] = 1
out4 = svm.SVC(kernel="linear")
out4.fit(X,y5)

w1  = out1.coef_[0]
b1 = out1.intercept_[0]

w2  = out2.coef_[0]
b2 = out2.intercept_[0]

w3  = out3.coef_[0]
b3 = out3.intercept_[0]

w4  = out4.coef_[0]
b4 = out4.intercept_[0]


xx = np.linspace(0,12)
yy = (-b1/w1[1]) - ((xx*w1[0])/w1[1])
y1 = 1+yy
y2 = -1+yy
plt.plot(xx,yy,color="blue")
plt.axis([0,15,0,15])


xx = np.linspace(0,12)
yy = (-b2/w2[1]) - ((xx*w2[0])/w2[1])
y1 = 1+yy
y2 = -1+yy
plt.plot(xx,yy,color="green")
plt.axis([0,15,0,15])

xx = np.linspace(0,12)
yy = (-b3/w3[1]) - ((xx*w3[0])/w3[1])
y1 = 1+yy
y2 = -1+yy
plt.plot(xx,yy,color="yellow")
plt.axis([0,15,0,15])


xx = np.linspace(0,12)
yy = (-b4/w4[1]) - ((xx*w4[0])/w4[1])
y1 = 1+yy
y2 = -1+yy
plt.plot(xx,yy,color="red")
plt.axis([0,15,0,15])
plt.show()
