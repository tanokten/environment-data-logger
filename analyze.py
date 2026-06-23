import pandas as pd
import matplotlib.pyplot as plt

# Load the logged temperature and humidity data
data = pd.read_csv("LOG.csv")  # Make sure LOG.csv is in the same folder as this script
print(data)

# Plot temperature and humidity over time
plt.plot(data.index, data["temp"], label="Temperature (C)")
plt.plot(data.index, data["hum"], label="Humidity (%)")
plt.xlabel("Reading Index")
plt.ylabel("Value")
plt.title("Temperature and Humidity Over Time")
plt.legend()
plt.show()