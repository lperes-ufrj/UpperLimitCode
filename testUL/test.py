import matplotlib.pyplot as plt
import numpy as np

# Generate some data
data = np.random.randn(1000)

# Create the histogram
counts, bins, patches = plt.hist(data, bins=30, alpha=0.75, edgecolor='black')

# Define the vertical line
vline = 1  # Example value for the vertical line
plt.axvline(vline, color='r', linestyle='--')

# Fill the area between the vertical line and the histogram
for i in range(len(bins) - 1):
    if bins[i] < vline:
        plt.fill_betweenx([0, counts[i]], bins[i], min(bins[i+1], vline), color='blue', alpha=0.3)

# Display the plot
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Histogram with Filled Area')
plt.show()
