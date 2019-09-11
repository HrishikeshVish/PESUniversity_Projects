import pandas as pd
import numpy as np
import matplotlib as plt
%matplotlib inline

df = pd.read_csv("dataset.csv")

#print(df.head(10))
#print(df.describe())
print(df['street'].value_counts())

temp1 = df['city'].value_counts(ascending=True)
print(temp1)

#temp1.plot(kind='bar')
temp2 = range(1,40)

plt.pyplot.scatter(temp1.values,temp2)

mean = np.mean(df['sq__ft'])
print(df)
print(mean)
df['sq__ft'].hist(bins=10)

print(df['sq__ft'].isnull().sum())


df['sq__ft'].fillna(df['sq__ft'].mean(), inplace=True)
print(df['sq__ft'].isnull().sum())

df['sq__ft'].hist(bins=10)

plt.pyplot.boxplot(df['sq__ft'],1)

print(df['sq__ft'].median())

print(df['sq__ft'].mean())
