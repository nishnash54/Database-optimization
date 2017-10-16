import string
import random

lst = []
datalst = [[10, 10], [10, 20]]
for one_set in range(len(datalst)):

    del lst[:]
    f = open('set_'+ str(one_set) + '.txt', 'w')

    num1 = datalst[one_set][0]
    num2 = datalst[one_set][1]

    f.write(str(num1) + '\n')
    for i in range(num1):
        data = ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.digits) for _ in range(10))
        lst.append(data)
        f.write(data +' '+ str(random.randint(0, 100) - 1) + '\n')

    f.write(str(num2) + '\n')
    for i in range(num2):
        f.write(lst[random.randint(0, num1) - 1] + ' ' + str(random.randint(0, 100)) + '\n')

    f.close()
