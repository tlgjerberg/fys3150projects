import os

times = []

with open("CPUtime.txt") as time:
    for line in time:
        col = line.split()
        times.append(float(col[1]))

n = float(len(times))

average = (1./n)*sum(times)

min_time = min(times)

max_time = max(times)


print(average)
print(min_time)
print(max_time)



time.close()

os.remove("CPUtime.txt")
