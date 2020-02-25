import tensorflow as tf

#build phase
node1 = tf.constant(5.0)
node2 = tf.constant(6.0)
node4 = tf.multiply(node1, node2)
node3 = tf.placeholder(dtype = tf.float32)
node5 = node3 + node4
node7 = tf.constant([2,3,4,5,6,7],shape=(3,2))
node8 = tf.constant([2,3,4,5,6,7], shape=(2,3))
node9 = tf.matmul(node7, node8)


#Run Phase
sess = tf.Session()
print(sess.run(node4))
print(sess.run(node5, feed_dict={node3: 4.3}))
print(sess.run(node9))
print(sess.run([node5, node9], feed_dict={node3: 23.0}))
#print(node3.eval())

"""with tf.Session() as sess:
    num1 = float(input("Enter a Number"))
    print(sess.run(node5, feed_dict = {node3: num1}))
"""
