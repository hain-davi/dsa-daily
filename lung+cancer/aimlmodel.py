import pandas as pd
import numpy as np

df = pd.read_csv("surveylung_cancer2.csv")

df.columns = df.columns.str.strip().str.replace(' ', '_').str.lower()

df = df.drop([
    'coughing_of_blood',
    'genetic_risk',
    'chest_pain',
    'shortness_of_breath',
    'patient_id',
    'index'
], axis=1, errors='ignore')

#ENCODING 
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
df['gender'] = le.fit_transform(df['gender'])
df['level'] = le.fit_transform(df['level'])

features = [
    'age',
    'smoking',
    'air_pollution',
    'alcohol_use',
    'obesity',
    'chronic_lung_disease'
]

X = df[features]
Y = df['level']

X = X.apply(pd.to_numeric, errors='coerce')

#IMPUTATION
from sklearn.impute import SimpleImputer
imputer = SimpleImputer(strategy='median')
X = imputer.fit_transform(X)

np.random.seed(42)
X = X + np.random.normal(0, 0.3, X.shape)

from sklearn.model_selection import train_test_split

X_train, X_test, Y_train, Y_test = train_test_split(
    X, Y, test_size=0.3, stratify=Y, random_state=42
)

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

#RANDOM FOREST & LOGISTIC REGRESSION
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier

lr = LogisticRegression(max_iter=1000)
rf = RandomForestClassifier(n_estimators=30, max_depth=3, random_state=42)

lr.fit(X_train, Y_train)
rf.fit(X_train, Y_train)


from sklearn.metrics import accuracy_score, f1_score
train_acc_lr = accuracy_score(Y_train, lr.predict(X_train))
train_acc_rf = accuracy_score(Y_train, rf.predict(X_train))

test_acc_lr = accuracy_score(Y_test, lr.predict(X_test))
test_acc_rf = accuracy_score(Y_test, rf.predict(X_test))

print("Training Accuracy (LR):", train_acc_lr)
print("Testing Accuracy (LR):", test_acc_lr)
print("Training Accuracy (RF):", train_acc_rf)
print("Testing Accuracy (RF):", test_acc_rf)

f1_lr = f1_score(Y_test, lr.predict(X_test), average='weighted')
f1_rf = f1_score(Y_test, rf.predict(X_test), average='weighted')

print("F1 Score (LR):", f1_lr)
print("F1 Score (RF):", f1_rf)

from sklearn.model_selection import cross_val_score
cv_scores = cross_val_score(rf, X_train, Y_train, cv=5)
print("Validation Accuracy (CV mean):", cv_scores.mean())

from sklearn.preprocessing import label_binarize
from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt

Y_test_bin = label_binarize(Y_test, classes=[0,1,2])
y_prob = rf.predict_proba(X_test)

plt.figure()

for i in range(3):
    fpr, tpr, _ = roc_curve(Y_test_bin[:, i], y_prob[:, i])
    roc_auc = auc(fpr, tpr)
    plt.plot(fpr, tpr, label=f"Class {i} (AUC={roc_auc:.2f})")

plt.plot([0,1],[0,1],'--')
plt.title("ROC Curve")
plt.xlabel("False Positive Rate")
plt.ylabel("True Positive Rate")
plt.legend()
plt.show()


from sklearn.metrics import precision_recall_curve
plt.figure()

for i in range(3):
    precision, recall, _ = precision_recall_curve(Y_test_bin[:, i], y_prob[:, i])
    plt.plot(recall, precision, label=f"Class {i}")

plt.title("Precision-Recall Curve")
plt.xlabel("Recall")
plt.ylabel("Precision")
plt.legend()
plt.show()

importances = rf.feature_importances_

plt.barh(features, importances)
plt.title("Feature Importance")
plt.show()