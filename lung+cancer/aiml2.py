import pandas as pd
import numpy as np

df = pd.read_csv("surveylung_cancer2.csv")

df.columns = df.columns.str.strip().str.replace(' ', '_').str.lower()
df = df.drop(['index', 'patient_id'], axis=1, errors='ignore')

# Encoding 
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
y = df['level']

from sklearn.impute import SimpleImputer
imputer = SimpleImputer(strategy='median')
X = imputer.fit_transform(X)

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()
X = scaler.fit_transform(X)

from sklearn.ensemble import RandomForestClassifier
model = RandomForestClassifier(n_estimators=30, max_depth=3, random_state=42)
model.fit(X, y)

#INPUTS
print("\nEnter patient details:")
age = int(input("Age: "))
smoking = int(input("Smoking (0=No, 1=Yes): "))
air_pollution = int(input("Air Pollution (1-10): "))
alcohol = int(input("Alcohol Use (1-10): "))
obesity = int(input("Obesity (1-10): "))
chronic = int(input("Chronic Lung Disease (0/1): "))

user_input = pd.DataFrame([[age, smoking, air_pollution, alcohol, obesity, chronic]], columns=features)
user_input = imputer.transform(user_input)
user_input = scaler.transform(user_input)

prediction = model.predict(user_input)

# OUTPUT
levels = ["Low Risk", "Medium Risk", "High Risk"]

print("\nPredicted Lung Cancer Risk:", levels[prediction[0]])