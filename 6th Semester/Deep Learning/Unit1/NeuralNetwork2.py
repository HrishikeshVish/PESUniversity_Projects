#Stochastic Gradient Descent

import tensorflow as tf
import numpy as np

X_train = np.asarray(np.random.randn(50,1)) #Input dimensions = 1, 50 instances
Y_train = X_train * X_train + 2 *X_train + 3

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

epochs = 5000

size_input = 1
size_hidden1 = 3
size_hidden2 = 6
size_output = 1


#Regression problem cannot use sigmoid/tanh because it squeezes the output to [-1,1]

wh1 = tf.Variable(tf.random_normal([size_input, size_hidden1]))
bh1 = tf.Variable(tf.random_normal([1, size_hidden1]))
    

wh2 = tf.Variable(tf.random_normal([size_hidden1, size_hidden2]))
bh2 = tf.Variable(tf.random_normal([1, size_hidden2]))

#Output Layer
wh3 = tf.Variable(tf.random_normal([size_hidden2, size_output]))
bh3 = tf.Variable(tf.random_normal([1, size_output]))


#Layer 1
net_h1 = tf.matmul(X,wh1)+bh1
act_h1 = tf.nn.relu(net_h1)

#Layer 2
net_h2 = tf.matmul(act_h1, wh2) + bh2
act_h2 = tf.nn.relu(net_h2)

#Layer 3
net_o = tf.matmul(act_h2, wh3) + bh3
pred = tf.nn.relu(net_o)

#37 weights

loss =tf.pow(Y-pred, 2.0)/2.0
opt = tf.train.GradientDescentOptimizer(learning_rate=0.02).minimize(loss)

init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    for i in range(epochs):
        for l in range(len(X_train)):
            sess.run(opt, feed_dict = {X:[X_train[l]], Y:[Y_train[l]]})
            if(i%100 == 0 and l%10 == 0):
                print("Epoch = ", i, " loss = ", loss.eval(feed_dict = {X:[X_train[l]], Y:[Y_train[l]]}))
    X_test = np.asarray([[1.1],[1.2],[1.3],[0.9],[0.8]])
    print(sess.run(pred, feed_dict = {X:X_test}))
    
