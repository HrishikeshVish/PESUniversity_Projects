import tensorflow as tf
import numpy as np

#Regression Problem

x_train = np.asarray([1,2,3,4,5,6,7,8,9,10])
y_train = np.asarray([3,5,7,9,11,13,15,17,19,21])

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

epochs = 500

#define parameters to be learned

w = tf.Variable(0.3) #between 0 and 1. mean 0 std = 1 normal distribution
b = tf.Variable(0.2)

#predict the output
pred = w*X + b

#define the loss function
loss = tf.reduce_mean(tf.pow(Y - pred,2.0))/2.0 #reduces the dimensions (to 1) of the tensor computes the mean of the dataset

opt = tf.train.GradientDescentOptimizer(learning_rate=0.02).minimize(loss)
init = tf.global_variables_initializer()
with tf.Session() as sess:
    sess.run(init)
    for i in range(epochs):
        sess.run(opt, feed_dict = {X:x_train, Y:y_train})
        print("W = " + str(w.eval()) + " b = " + str(b.eval())+ "\n Pred = " + str(pred.eval(feed_dict = {X:x_train, Y:y_train})))
        """for j in range(10):
            #print(type(x_train[j]))
            sess.run(opt, feed_dict = {X:float(x_train[j]), Y:float(y_train[j])})
            print("W: ", w.eval(), " b:", b.eval(), " Pred:", pred.eval(feed_dict = {X:float(x_train[j]), Y:float(y_train[j])}));
            #print("w = " + str(w.eval())+ " f(x) = " + str(loss.eval()))
        """
