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

f, ax = plt.subplots(3, sharex=True)
ax[0].bar([each-0.1 for each in lst[:2]], time_oodb[:2], width=0.2, color='r', align='center')
ax[0].bar([each+0.1 for each in lst[:2]], time_direct[:2], width=0.2, color='g', align='center')
ax[1].bar([each-0.1 for each in lst[2:4]], time_oodb[2:4], width=0.2, color='r', align='center')
ax[1].bar([each+0.1 for each in lst[2:4]], time_direct[2:4], width=0.2, color='g', align='center')
ax[2].bar([each-0.1 for each in lst[4:]], time_oodb[4:], width=0.2, color='r', align='center')
ax[2].bar([each+0.1 for each in lst[4:]], time_direct[4:], width=0.2, color='g', align='center')
plt.show()

file1.close()
file2.close()
