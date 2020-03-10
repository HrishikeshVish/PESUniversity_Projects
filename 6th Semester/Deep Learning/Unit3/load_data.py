import keras
from keras.datasets import imdb
from keras.datasets import cifar100
from keras.datasets import reuters
from keras.datasets import mnist
from keras.datasets import fashion_mnist
import numpy as np
np.load.__defaults__=(None, True, True, 'ASCII')
imdb.load_data()
cifar100.load_data()
reuters.load_data()
mnist.load_data()
fashion_mnist.load_data()

print("DONE")
