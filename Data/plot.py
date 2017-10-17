import matplotlib.pyplot as plt
import plotly.plotly as py

file1 = open("extime_direct.txt", 'r')
file2 = open("extime_oodb.txt", 'r')

lst = [float(each) for each in range(7)]
lst1 = [each.strip() for each in file1]
lst2 = [each.strip() for each in file2]

time_direct = []
time_oodb = []

def mm_avg(lst):
    lst = [float(each) for each in lst]
    return(sum(lst)-max(lst)-min(lst))/(len(lst) - 2)

for i in range(7):
    time_direct.append(mm_avg(lst1[i*11+1:(i+1)*11]))
    time_oodb.append(mm_avg(lst2[i*11+1:(i+1)*11]))

print(time_oodb)
print(time_direct)

plot = plt.figure()
ax = plt.subplot(111)
ax.bar([each-0.1 for each in lst], time_oodb, width=0.2, color='r', align='center')
ax.bar([each+0.1 for each in lst], time_direct, width=0.2, color='g', align='center')
plt.show()

file1.close()
file2.close()
