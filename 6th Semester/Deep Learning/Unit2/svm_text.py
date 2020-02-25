from sklearn.feature_extraction.text import CountVectorizer
from sklearn.feature_extraction.text import TfidfTransformer
import matplotlib.pyplot as plt
import numpy as np
import  pandas
from sklearn import svm
from sklearn.metrics import accuracy_score
def get_tfidf(X_train,case, cv):
    if(case ==0):
        count_vect = CountVectorizer()
        idfvals = []
    
    
        X_train = list(X_train)
        X_train_counts = count_vect.fit_transform(X_train)
        #print(count_vect.get_feature_names())
    
    
        tfidf_transformer = TfidfTransformer()
        X_train_tfidf = tfidf_transformer.fit_transform(X_train_counts)
        #print(X_train_tfidfr)
        return X_train_tfidf, count_vect
    if(case == 1):

        idfvals = []
    
    
        X_train = list(X_train)
        X_train_counts = cv.transform(X_train)
        #print(count_vect.get_feature_names())
    
    
        tfidf_transformer = TfidfTransformer()
        X_train_tfidf = tfidf_transformer.transform(X_train_counts)
        #print(X_train_tfidf)
    return X_train_tfidf


    

data = pandas.read_csv('spam_nospam.csv', engine="python")
y_train = data['v1']
X_train = data['v2']
for i in range(len(y_train)):
    if(y_train[i] == 'spam'):
        y_train[i] = 0
    if(y_train[i] == 'ham'):
        y_train[i] = 1




X_train1 = X_train[:2100]

y_train1 = y_train[:2100]
#print(y_train1.values)
y_train1 = y_train1.astype('int')

#X_train_tfidf, count_vect = get_tfidf(X_train1, 0, 0)
count_vect = CountVectorizer()

    
    
X_train1 = list(X_train1)
X_train_counts = count_vect.fit_transform(X_train1)
#print(count_vect.get_feature_names())
    
    
tfidf_transformer = TfidfTransformer()
X_train_tfidf = tfidf_transformer.fit_transform(X_train_counts)

out = svm.SVC(kernel="rbf", gamma=0.01, C=1)
out.fit(X_train_tfidf, y_train1.values)
x_test = X_train[2101:]
y_test = y_train[2101:]
y_test = y_test.astype('int')

#x_test_tfidf = get_tfidf(x_test, 1, count_vect)
X_test = list(x_test)
x_test_counts = count_vect.transform(X_test)
x_test_tfidf = tfidf_transformer.transform(x_test_counts)
y_pred = out.predict(x_test_tfidf)
print(accuracy_score(y_test, y_pred))

