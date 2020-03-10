# LSTM for sequence classification in the IMDB dataset
import keras
import numpy as np
from keras.datasets import imdb
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import LSTM, GRU
from keras.layers.embeddings import Embedding
from keras.preprocessing import sequence

word_to_id = imdb.get_word_index()
word_to_id = {k:(v+3) for k,v in word_to_id.items()}
word_to_id["<PAD>"] = 0
word_to_id["<START>"] = 1
word_to_id["<UNK>"] = 2

# load the dataset but only keep the top n words, zero the rest
top_words = 5000
np.load.__defaults__=(None, True, True, 'ASCII')
(X_train1, y_train), (X_test1, y_test) = imdb.load_data(path="imdb.npz",num_words=top_words)
# truncate and pad input sequences
max_review_length = 500
X_train = sequence.pad_sequences(X_train1, maxlen=max_review_length)
X_test = sequence.pad_sequences(X_test1, maxlen=max_review_length)

#train now
model = Sequential()
#16 = size of the output vector
model.add(Embedding(top_words, 16, input_length=500))
model.add(GRU(10, activation='relu', return_sequences=True))
model.add(GRU(40, activation='relu'))
model.add(Dense(1, activation='sigmoid'))
model.summary()
model.compile(loss='binary_crossentropy', optimizer='Adam', metrics=['accuracy'])
model.fit(X_train, y_train, epochs=3, batch_size=64)
#Predict now
bad = "pathetic movie felt like leaving the theatre half way"
good = "i really liked the movie and had fun"
for review in [good,bad]:
    tmp = []
    for word in review.split(" "):
        tmp.append(word_to_id[word])
    tmp_padded = sequence.pad_sequences([tmp], maxlen=max_review_length) 
    print("%s. Sentiment: %s" % (review,model.predict(tmp_padded)))


id_to_word = {value:key for key,value in word_to_id.items()}
print(' '.join(id_to_word[id] for id in X_train[0] ))
