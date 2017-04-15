###Author: Saurabh Nair
### Code to map velocity using force and imu data from the skates

import numpy as np
import pandas as pd
from keras.models import Sequential
from keras.layers import Dense
from keras.wrappers.scikit_learn import KerasRegressor
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline

# dataset
dataframe = pd.read_csv("/home/saurabh/Stepping-Stones/Matlab/Mat Files/kinect_velocity/velocity_saurabh_2017-04-09-00-22-46.csv")

#print dataframe
dataset = dataframe.values
# split into input (X) and output (Y) variables
feature_names = ['LeftFeedback_ImuQuatX', 'LeftFeedback_ImuQuatY', 'LeftFeedback_ImuQuatZ', 'LeftFeedback_ImuQuatW', 'LeftFeedback_ImuAccelX', 'LeftFeedback_ImuAccelY' , 'LeftFeedback_ImuAccelZ' , 'LeftFeedback_ImuRateX' , 'LeftFeedback_ImuRateY', 'LeftFeedback_ImuRateZ', 'RightFeedback_ImuQuatX', 'RightFeedback_ImuQuatY', 'RightFeedback_ImuQuatZ', 'RightFeedback_ImuQuatW', 'RightFeedback_ImuAccelX', 'RightFeedback_ImuAccelY', 'RightFeedback_ImuAccelZ', 'RightFeedback_ImuRateX', 'RightFeedback_ImuRateY', 'RightFeedback_ImuRateZ', 'NormalizedForce_LeftNormalFrontOuter', 'NormalizedForce_LeftNormalFrontInner', 'NormalizedForce_LeftNormalRear', 'NormalizedForce_RightNormalFrontOuter', 'NormalizedForce_RightNormalFrontInner',   'NormalizedForce_RightNormalRear', 'NormalizedForce_RightNormalTotal', 'NormalizedForce_LeftNormalTotal', 'NormalizedForce_NormalTotal']


no_features = len(feature_names)

target_velocities = 'RightCommand_CommandTarget'
X = dataframe[feature_names]
Y = dataframe[target_velocities]

# define base model
def baseline_model():
# create model
    global no_features
    model = Sequential()
    model.add(Dense(no_features, input_dim=no_features, kernel_initializer='normal', activation='sigmoid'))
    model.add(Dense(1, kernel_initializer='normal'))
    # Compile model
    model.compile(loss='mean_squared_error', optimizer='adam')
    return model

# fix random seed for reproducibility
seed = 7

# evaluate model with standardized dataset
def larger_model():
    # create model
    global no_features
    model = Sequential()
    model.add(Dense(no_features, input_dim=no_features, kernel_initializer='normal', activation='sigmoid'))
    model.add(Dense(6, kernel_initializer='normal', activation='sigmoid'))
    model.add(Dense(1, kernel_initializer='normal', activation= 'linear'))
    # Compile model
    model.compile(loss='mean_squared_error', optimizer='adam')
    return model


np.random.seed(seed)
estimators = []
estimators.append(('standardize', StandardScaler()))
estimators.append(('mlp', KerasRegressor(build_fn=larger_model, epochs=50, batch_size=5, verbose=0)))

#print estimators[1][1].predict(X.iloc[[2]])
#print build_fn.predict(X[1,:])
pipeline = Pipeline(estimators)
kfold = KFold(n_splits=10, random_state=seed)
results = cross_val_score(pipeline, X, Y, cv=kfold)
f = X.values

print("Larger: %.2f (%.2f) MSE" % (results.mean(), results.std()))
pipeline.predict(f[2,:])

