import tensorflow as tf

#Variable to be learned
x = tf.Variable(5.0,trainable=True)

#function to be optimized
fx = tf.pow(x,4.0) - 2*tf.pow(x,2.0) + 3
init = tf.global_variables_initializer()

#define optimizers - basic gradient descent optimizer
opt = tf.train.GradientDescentOptimizer(learning_rate=0.02).minimize(fx)

epochs = 300


with tf.Session() as sess:
    sess.run(init)
    #find x to minimize fx
    for i in range(epochs):
        sess.run(opt)
        #if(i%50 == 0):
        print("x = " + str(x.eval())+ " f(x) = " + str(fx.eval()))
            
    
