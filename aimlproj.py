#Lung Cancer Risk Prediction using Machine Learning with Data Preprocessing

#PROBLEM STATEMENT
###
#loading dataset from kaggle 
import pandas as pd
df=pd.read_csv("surveylung_cancer2.csv")
df.columns = df.columns.str.strip()  #cleaning column names
df = df.drop(['Coughing of Blood','Genetic Risk','Chest Pain','Shortness of Breath'], axis=1)
print(df.head())
print(df.info())
#libraries
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.impute import SimpleImputer
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import classification_report,accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import label_binarize
from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score


#encoding categorical columns
le=LabelEncoder()
df['Gender']=le.fit_transform(df['Gender'])
df['Level']=le.fit_transform(df['Level'])
print(df.isnull().sum())
df['Gender'] = df['Gender'].fillna(df['Gender'].mode()[0])
df.columns=df.columns.str.replace(' ','_')

X = df.drop(['Level', 'Patient_Id'], axis=1, errors='ignore')
Y=df['Level']
#Scaling
print(X.dtypes)

X = X.apply(pd.to_numeric, errors='coerce')
print(X.isnull().sum())
X = X.dropna(axis=1, how='all')
X = X.fillna(X.median())

imputer = SimpleImputer(strategy='median')
X = imputer.fit_transform(X)


scalar=StandardScaler()
X_scaled = scalar.fit_transform(X)

X_train,X_test,Y_train,Y_test=train_test_split(
    X_scaled,Y,test_size=0.3,random_state=42,stratify=Y
)

scalar=StandardScaler()
X_train = scalar.fit_transform(X_train)
X_test = scalar.transform(X_test)


#Training model using Logistic Regression

lr=LogisticRegression(max_iter=1000)
lr.fit(X_train,Y_train)

#Training model using Random forest

rf=RandomForestClassifier(n_estimators=100,max_depth=None,random_state=42)
rf.fit(X_train,Y_train)

y_pred_lr=lr.predict(X_test)
y_pred_rf=rf.predict(X_test)


print("Logistic Regression:")
print(accuracy_score(Y_test,y_pred_lr))
print(classification_report(Y_test,y_pred_lr))

print("Random Forest:")
print(accuracy_score(Y_test,y_pred_rf))
print(classification_report(Y_test,y_pred_rf))

print(confusion_matrix(Y_test, y_pred_rf))

y_test_bin = label_binarize(Y_test, classes=[0,1,2])

# get probabilities for ALL classes
y_prob = rf.predict_proba(X_test)

plt.figure()

for i in range(3):
    fpr, tpr, _ = roc_curve(y_test_bin[:, i], y_prob[:, i])
    roc_auc = auc(fpr, tpr)
    plt.plot(fpr, tpr, label=f"Class {i} (AUC = {roc_auc:.2f})")

plt.plot([0,1], [0,1], linestyle="--")
plt.xlabel("False Positive Rate")
plt.ylabel("True Positive Rate")
plt.title("Multiclass ROC Curve (One-vs-Rest)")
plt.legend()
plt.show()

importances = rf.feature_importances_

plt.barh(X.columns, importances)
plt.title("Feature Importance")
plt.show()

print(cross_val_score(rf, X_scaled, Y, cv=5))