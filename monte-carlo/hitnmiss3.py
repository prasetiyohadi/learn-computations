from collections import OrderedDict as od
from matplotlib import pyplot as plt
import csv
import operator
import random
import time


# function
def myfunc(x, y, z):
    return x*y**2*z+x**3*y*z**2-x*y*z**3


# analitically integrated function
def myintfunc(xa, ya, za, xb, yb, zb):
    return (xb**2-xa**2)*(yb**3-ya**3)*(zb**2-za**2)/12 +\
        (xb**4-xa**4)*(yb**2-ya**2)*(zb**3-za**3)/24 -\
        (xb**2-xa**2)*(yb**2-ya**2)*(zb**4-za**4)/16

# initial number of points
nInit = 10
# power steps
p = 6
# integration boundary
xa = 1
xb = 3
ya = 0
yb = 5
za = 2
zb = 4

# find maximum value of myfunc in integration range
maxvals = {}
for i in range(xa, xb+1):
    for j in range(ya, yb+1):
        for k in range(za, zb+1):
            maxvals["%s%s%s" % (i, j, k)] = [myfunc(i, j, k)]

maxval = sorted(maxvals.items(), key=operator.itemgetter(1))
print("Nilai maximum fungsi = %s dengn nilai xyz = %s" %
      (maxval[-1][1][0], maxval[-1][0]))

# function ceiling
c = maxval[-1][1][0]

# construct result dictionary
result = {}

# calculate analytical integration result
reint = myintfunc(xa, ya, za, xb, yb, zb)


# define monte-carlo version of myfunc
def mymcfunc(xr, yr, zr):
    return myfunc((xa+(xb-xa)*xr), (ya+(yb-ya)*yr), (za+(zb-za)*zr))

# calculate hit and miss monte-carlo integration result
for x in range(0, p):
    N = nInit*10**x
    count = 0
    init = time.perf_counter()
    xrh = []
    yrh = []
    zrh = []
    vrh = []
    for i in range(0, N):
        xr = random.uniform(0, 1)
        yr = random.uniform(0, 1)
        zr = random.uniform(0, 1)
        vr = random.uniform(0, 1)
        if (c*vr < mymcfunc(xr, yr, zr)):
            count = count + 1
        xrh = xr
        yrh = yr
        zrh = zr
        vrh = vr
    deltat = time.perf_counter() - init
    mcint = count/N*c*(xb-xa)*(yb-ya)*(zb-za)
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
