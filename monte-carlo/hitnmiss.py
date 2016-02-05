from collections import OrderedDict as od
from matplotlib import pyplot as plt
import csv
import random
import time


# function
def myfunc(x):
    return 5*x**2-3*x+7


# analitically integrated function
def myintfunc(x):
    return 5*x**3/3-3*x**2/2+7*x

# initial number of points
nInit = 10
# power steps
p = 6
# function ceiling
c = 117.000001
# integration boundary
a = 1
b = 5

# construct result dictionary
result = {}

# calculate analytical integration result
reint = myintfunc(b)-myintfunc(a)

# calculate hit and miss monte-carlo integration result
for x in range(0, p):
    N = nInit*10**x
    count = 0
    init = time.perf_counter()
    for i in range(0, N):
        r1 = random.uniform(0, 1)
        r2 = random.uniform(0, 1)
        if (c*r2 < myfunc(a+(b-a)*r1)):
            count = count + 1
    deltat = time.perf_counter() - init
    mcint = count/N*c*(b-a)
    result[N] = [mcint, abs(reint-mcint), deltat]

# save the result to CSV file
# sort result dictionary
oresult = od(sorted(result.items()))

# write to CSV file
with open('result.csv', 'w') as resfile:
    csvfile = csv.writer(resfile)
    csvfile.writerow(["jumlah titik", "hasil integrasi monte-carlo",
                      "kesalahan hasil integrasi", "waktu eksekusi"])
    for key, value in oresult.items():
        csvfile.writerow([key]+value)

x = [item for item in oresult.keys()]
y1 = [item[1] for item in oresult.values()]
y2 = [item[2] for item in oresult.values()]

colors = list('kymcbgr')
plt.semilogx(x, y1, color=colors.pop())
plt.title("Grafik kesalahan hasil integrasi terhadap jumlah titik")
plt.xlabel("jumlah titik (N)")
plt.ylabel("kesalahan hasil integrasi")
plt.grid(True)
plt.savefig('errorvsn.png', bbox_inches='tight')
# plt.show()
plt.close()
plt.semilogx(x, y2, color=colors.pop())
plt.title("Grafik waktu eksekusi terhadap jumlah titik")
plt.xlabel("jumlah titik (N)")
plt.ylabel("waktu eksekusi (s)")
plt.grid(True)
plt.savefig('deltatvsn.png', bbox_inches='tight')
# plt.show()
plt.close()
