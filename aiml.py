import pandas as pd
data=pd.read_csv("GlobalTemperatures.csv")
data.head()
data.info()
global_temp=data[['dt','LandAverageTemperature']]
global_temp.head()
global_temp=global_temp.dropna()
global_temp['dt']=pd.to_datetime(global_temp['dt'])
import matplotlib.pyplot as plt
plt.figure(figsize=(12,5))
plt.plot(global_temp['dt'],
global_temp['LandAverageTemperature'])
plt.xlabel('Year')
plt.ylabel('Average Land Temperature (C)')
plt.title('Global Average Land Temperature Over Time')
plt.show()
global_temp['Year']=global_temp['dt'].dt.year
yearly_temp=global_temp.groupby('Year')['LandAverageTemperature'].mean()
plt.figure(figsize=(12,5))
plt.plot(yearly_temp.index,yearly_temp.values)
plt.xlabel('Year')
plt.ylabel('Average Land Temperature (C)')
plt.title('Yearly Global Average Land Temperature')