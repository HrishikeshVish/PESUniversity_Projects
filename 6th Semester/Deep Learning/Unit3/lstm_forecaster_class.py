import keras
from keras.models import Sequential
from keras.layers import Dense, GRU, LSTM

import numpy as np

#Build raw data
raw_seq = []
for i in range (100):
    raw_seq.append(i * 10)

#Form the training data for forecasting.
def split_sequence(sequence, n_steps):
	X, y = list(), list()
	for i in range(len(sequence)):
		# find the end of this pattern
		end_ix = i + n_steps
		# check if we are beyond the sequence
		if end_ix > len(sequence)-1:
			break
		# gather input and output parts of the pattern
		seq_x, seq_y = sequence[i:end_ix], sequence[end_ix]
		X.append(seq_x)
		y.append(seq_y)
	return np.array(X), np.array(y)

X, y = split_sequence(raw_seq, 4)
# summarize the data
for i in range(len(X)):
	print(X[i], y[i])
    
#Fill code to train and test the model

model = Sequential()
model.add(LSTM(20, activation='relu', input_shape=(4,1), return_sequences=True))
model.add(LSTM(40, activation='relu', return_sequences=True))
model.add(LSTM(50, activation='relu'))
model.add(Dense(1)) #Output has 1 value
model.summary()

model.compile(optimizer='adam', loss='mse', metrics=['accuracy'])
X = X.reshape(X.shape[0], 4,1)
model.fit(X,y, epochs=1400)
x_test = np.array([224, 225, 226, 227])
x_test = x_test.reshape(1, 4, 1)
y_test = 264
print(model.predict(x_test))


