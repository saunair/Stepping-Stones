import numpy
from sklearn.externals import joblib
from sklearn import svm
import pandas
import sys
from sklearn.cross_validation import train_test_split
sys.setrecursionlimit(6000)
seed = 7
numpy.random.seed(seed)

file_name = '../../../../Matlab/Mat Files/stance_tests_20th_march/stance_tests_20th_march.csv'

dataframe = pandas.read_csv(file_name)
dataset = dataframe.values


X = dataset[1:,0:dataset.shape[1]-2].astype(float)
Y = dataset[1:,dataset.shape[1]-1]

print Y
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.1, random_state=42)

clf = svm.SVC(C=1.0, cache_size=200, class_weight=None, coef0=0.0,
    decision_function_shape='ovo', degree=3, gamma='auto', kernel='rbf',
    max_iter=-1, probability=True, random_state=None, shrinking=True,
    tol=0.001, verbose=True)
#clf = svm.LinearSVC(C=1.0, class_weight=None, dual=True, fit_intercept=True,
#     intercept_scaling=1, loss='squared_hinge', max_iter=5000,
#     multi_class='ovr', penalty='l2', random_state=None, tol=0.001,
#     verbose=1)

clf.fit(X_train, y_train) 


a = clf.predict(X_test)
b = y_test

print a, b

a1 = clf.predict(X_train)
b1 = y_train

print a1, b1

print clf.score(X_train,y_train)
print clf.score(X_test,y_test)

clf = svm.SVC(decision_function_shape='ovo')
clf.fit(X, Y) 
joblib.dump(clf, 'svm.pkl')
