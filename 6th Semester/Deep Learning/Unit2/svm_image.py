import numpy as np
from sklearn import svm, datasets
import matplotlib.pyplot as plt
from sklearn.metrics import accuracy_score
import random
digits = datasets.load_digits()
#print(digits)
x_train = digits.data;
y_train = digits.target;
data = list(zip(x_train, y_train))
random.shuffle(data)
x_train = data[0:1700]

x_test = data[1701:]

"""
x_train = digits.data[0:1700]
y_train = digits.target[0:1700]

x_test = digits.data[1701:]
y_test = digits.target[1701:]
"""

X = []
Y = []
for i in x_train:
    X.append(i[0])
    Y.append(i[1])
X = np.array(X)
Y = np.array(Y)

xx = []
yy = []
for i in x_test:
    xx.append(i[0])
    yy.append(i[1])
xx = np.array(xx)
yy = np.array(yy)

out = svm.SVC(kernel="linear", gamma=0.05, C=1)
out.fit(X,Y)
y_pred = out.predict(xx)
print(y_pred)
print(yy)
print(accuracy_score(yy, y_pred))
plt.imshow(digits.images[7])
#plt.show()
#Always do cross fold validation for this kinda problems

