import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
from keras.layers import Input, Dense, Lambda
from keras.models import Model
from keras import backend as K
from keras import objectives
from keras.datasets import fashion_mnist

# Hyperparameters
batch_size = 100
original_dim = 784
latent_dim = 2
intermediate_dim = 256
nb_epoch = 20
epsilon_std = 1.0

#encoder
x = Input(batch_shape = (batch_size, original_dim))
h = Dense(intermediate_dim, activation = 'relu')(x)
z_mean = Dense(latent_dim)(h)
z_log_var = Dense(latent_dim)(h)

def sampling(args):
 z_mean, z_log_var = args
 epsilon = K.random_normal(shape=(batch_size, latent_dim), mean=0.)
 return z_mean + K.exp(z_log_var / 2) * epsilon
 
#the sampling part. A normal layer can't do this. We need the "Lambda"
z = Lambda(sampling)([z_mean, z_log_var])

#decoder
# we instantiate these layers separately so as to reuse them later
decoder_h = Dense(intermediate_dim, activation='relu')
decoder_mean = Dense(original_dim, activation='sigmoid')
h_decoded = decoder_h(z)
x_decoded_mean = decoder_mean(h_decoded)

#loss. MSE + KL Divergence between the latent distribution and N(0,1)
# Check the formula. See if it is ok.
def vae_loss(x, x_decoded_mean):
    xent_loss = original_dim * objectives.mse(x, x_decoded_mean)
    kl_loss = -0.5 * K.mean(1 + z_log_var - K.square(z_mean) - K.exp(z_log_var), axis=-1)
    return xent_loss + kl_loss


encoder = Model(x, z_mean)
vae = Model(x, x_decoded_mean)
vae.compile(optimizer='Adam', loss=vae_loss)

# train the VAE on MNIST digits
(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

x_train = x_train.astype('float32') / 255.
x_test = x_test.astype('float32') / 255.
x_train = x_train.reshape((len(x_train), np.prod(x_train.shape[1:])))
x_test = x_test.reshape((len(x_test), np.prod(x_test.shape[1:])))


vae.fit(x_train, x_train,
 shuffle=True,
 epochs=1,
 batch_size=batch_size,
 validation_data=(x_test, x_test),verbose=1)

# build a model to project inputs on the latent space
encoder_mean = Model(x, z_mean)
encoder_sigma = Model(x, z_log_var)

# build a digit generator that can sample from the learned distribution
decoder_input = Input(shape=(latent_dim,))
_h_decoded = decoder_h(decoder_input)
_x_decoded_mean = decoder_mean(_h_decoded)
generator = Model(decoder_input, _x_decoded_mean)

(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()
x_train = x_train.astype('float32') / 255.
x_test = x_test.astype('float32') / 255.
x_train = x_train.reshape((len(x_train), np.prod(x_train.shape[1:])))
x_test = x_test.reshape((len(x_test), np.prod(x_test.shape[1:])))

# display a 2D manifold of the digits
n = 15 # figure with 15x15 digits
digit_size = 28
figure = np.zeros((digit_size * n, digit_size * n))

# linearly spaced coordinates on the unit square were transformed through the inverse CDF (ppf) of the Gaussian
# to produce values of the latent variables z, since the prior of the latent space is Gaussian. We now sample from N(0,2) instead of (0,1)

grid_x = norm.ppf(np.linspace(0.05, 0.95, n),loc=0,scale=1)
grid_y = norm.ppf(np.linspace(0.05, 0.95, n),loc=0,scale=1)

for i, yi in enumerate(grid_x):
    for j, xi in enumerate(grid_y):
        z_sample = np.array([[xi, yi]])
        x_decoded = generator.predict(z_sample)
        digit = x_decoded[0].reshape(digit_size, digit_size)
        figure[i * digit_size: (i + 1) * digit_size,
               j * digit_size: (j + 1) * digit_size] = digit

plt.figure(figsize=(10, 10))
plt.imshow(figure)

#To check what the encoder distribution is. We
# can change the loss function to only KL Divergence or only MSE
# to see the effect.
fig = plt.figure(figsize=(10,10))
x_t_encoded = encoder.predict(x_train)
plt.scatter(x_t_encoded[:, 0], x_t_encoded[:, 1], c=y_train)
plt.colorbar()
plt.show()