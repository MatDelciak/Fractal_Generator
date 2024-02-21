import matplotlib.pyplot as plt

# Read the output file
points = []
with open('./resources/Koch_Snowflake_OUT.txt', 'r') as file:
    for line in file:
        x, y = map(float, line.split())
        points.append((x, y))

# Plot the points
plt.scatter(*zip(*points), s=1)
plt.show()
