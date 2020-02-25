from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfTransformer

data = ["This is a good piece of text", "This is ok", "This is poor"] 

count_vect = CountVectorizer()
X_train_counts = count_vect.fit_transform(data)
print(count_vect.get_feature_names())


tfidf_transformer = TfidfTransformer()
X_train_tfidf = tfidf_transformer.fit_transform(X_train_counts)
print(X_train_tfidf)

#L2 Normalization
tf_idf = []
sq_sum = 0
for i in X_train_counts:
    sq_sum += i**2
sq_sum = sq_sum**0.5
for i in X_train_counts:
    tf_idf.append(i/sq_sum)
print(tf_idf)
