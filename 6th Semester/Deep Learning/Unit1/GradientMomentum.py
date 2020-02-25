import numpy as np
import matplotlib.pyplot as plt
from keras.models import Sequential
from keras.layers import Dense
from keras import optimizers
#Create a a dataset
x_train = np.linspace(0,10,200)
#print(x_train)
y_train = np.cos(x_train) + np.random.randn(200)*0.15

plt.scatter(x_train, y_train,color="red")
plt.show()

#Create a model for training
model = Sequential()
model.add(Dense(25, activation="tanh", input_dim = 1))
model.add(Dense(20, activation="tanh"))
model.add(Dense(1, activation="linear"))

model.summary()
opt = optimizers.SGD()
model.compile(optimizer=opt,loss='mse')

model.fit(x_train, y_train,epochs=1000)
x_test = np.linspace(0,10, 200)
y_pred = model.predict(x_test)
plt.scatter(x_train, y_train, color='yellow')

plt.plot(x_train, y_pred, color='blue')
plt.show()

