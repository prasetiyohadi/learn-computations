from collections import OrderedDict as od
from matplotlib import pyplot as plt
import matplotlib as mpl
import csv
import numpy


def waterheight(m, M, d, R, Re):
    return 3*(m/M)*(R/d)**3*Re/2


def harmonic(t, T):
    return numpy.sin(2*numpy.pi*t/T)

M = 1
m = 0.0125
Rr = 1
dr = 60
R = 6371000
res = {}

maxHeight = waterheight(m, M, dr, Rr, R)

for i in range(0, 721):
    t = 2*numpy.pi*i/720
    h1 = maxHeight*harmonic(i, 720)
    h2 = maxHeight*harmonic(i, 12)*harmonic(i, 720)
    res[i] = [t, h1, h2]

ores = od(sorted(res.items()))

with open('result.csv', 'w') as resfile:
    csvfile = csv.writer(resfile)
    csvfile.writerow(["jam ke-", "posisi bulan terhadap sumbu X (rad)",
                      "perubahan ketinggian maksimal/minimal (m)",
                      "perubahan ketinggian tiap jam (m)"])
    for key, value in ores.items():
        csvfile.writerow([key]+value)

x = [item for item in ores.keys()]
t = [item[0] for item in ores.values()]
y1 = [item[1] for item in ores.values()]
y2 = [item[2] for item in ores.values()]

fig = plt.figure()
ax1 = fig.add_subplot(111)
ax2 = ax1.twiny()

mpl.rcParams['text.usetex'] = True
unit1 = 0.25
unit2 = 1
x1_tick = numpy.arange(-0.5, 2.5, unit1)
x2_tick = numpy.arange(0, 31, unit2)
x1_label = [r"$" + format(r, ".3g") + r"\pi$" for r in x1_tick]
x2_label = [r"$" + format(round(r)) + r"$" for r in x2_tick]
ax1.set_xticks(x1_tick*numpy.pi)
ax1.set_xticklabels(x1_label)
ax1.set_xlabel("posisi bulan (rad)")
ax1.set_ylabel("perubahan ketinggian air laut (m)")
ax1.set_title("Grafik perubahan ketinggian permukaan air laut terhadap posisi \
          dan hari", y=1.08)
ax2.set_xticks(x2_tick/24)
ax2.set_xticklabels(x2_label)
ax2.set_xlabel("hari ke- ")

colors = list('kymcbgr')
ax1.plot(t, y1, color=colors.pop())
ax1.plot(t, y2, color=colors.pop())
plt.grid(True)
plt.savefig('resultgraph.png', bbox_inches='tight')
# plt.show()
