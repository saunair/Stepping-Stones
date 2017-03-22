import numpy
from sklearn.externals import joblib
from sklearn import svm
import pandas
import sys
from sklearn.cross_validation import train_test_split
sys.setrecursionlimit(6000)
seed = 7
numpy.random.seed(seed)

dataframe = pandas.read_csv("saurabhBadvaHe.csv")
dataset = dataframe.values


X = dataset[1:,0:dataset.shape[1]-2].astype(float)
Y = dataset[1:,dataset.shape[1]-1]

X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.20, random_state=42)

#clf = svm.SVC(C=1.0, cache_size=200, class_weight=None, coef0=0.0,
#    decision_function_shape='ovo', degree=3, gamma='auto', kernel='rbf',
#    max_iter=-1, probability=True, random_state=None, shrinking=True,
#    tol=0.001, verbose=True)
clf = svm.LinearSVC(C=1.0, class_weight=None, dual=True, fit_intercept=True,
     intercept_scaling=1, loss='squared_hinge', max_iter=1000,
     multi_class='ovr', penalty='l2', random_state=None, tol=0.0001,
     verbose=1)

clf.fit(X_train, y_train) 
print clf.score(X_train,y_train)
print clf.score(X_test,y_test)

clf = svm.SVC(decision_function_shape='ovo')
clf.fit(X, Y) 
joblib.dump(clf, 'svm.pkl')

