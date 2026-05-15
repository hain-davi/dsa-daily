import pandas as pd
df=pd.read_csv("surveylung_cancer2.csv")
df.columns = df.columns.str.strip()  #cleaning column names
df = df.drop(['Coughing of Blood','Genetic Risk','Chest Pain','Shortness of Breath'], axis=1)
print(df.head())
print(df.info())