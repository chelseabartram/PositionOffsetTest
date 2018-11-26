import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("dataYAll.csv")
ax = df.plot(kind='scatter',x='x',y='y')
ax.set_xlabel("y position")
ax.set_ylabel("A")
plt.show()
