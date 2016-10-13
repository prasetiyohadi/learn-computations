#!/usr/bin/env python
import networkx as nx
import matplotlib
matplotlib.use('AGG')
import matplotlib.pyplot as plt

print('Input jaringan')
print('-----------------')
print('')
print('Jaringan Email-EuAll - Email network of a large European \
Institution (directed edge means at least one email was sent \
October 2003 and March 2005')
G = nx.read_edgelist('Email-EuAll.txt', create_using=nx.DiGraph(),
                     nodetype=int)
print('')

print("Properti jaringan")
print("-----------------")
print('')
N, K = G.order(), G.size()
avg_deg = float(K)/N
print('Jumlah node: %d' % N)
print('Jumlah edge: %d' % K)
print('Rata-rata edge: %.3f' % avg_deg)
print('Jumlah strongly connected component: %d' %
      nx.number_strongly_connected_components(G))
print('Jumlah weakly connected component: %d' %
      nx.number_weakly_connected_components(G))
print('')

print('Distribusi degree')
print('-----------------')
print('')
in_degrees = G.in_degree()
in_values = sorted(set(in_degrees.values()))
in_hist = [in_degrees.values().count(x) for x in in_values]
out_degrees = G.out_degree()
out_values = sorted(set(out_degrees.values()))
out_hist = [out_degrees.values().count(x) for x in out_values]

print('Pembuatan grafik...')
plt.figure()
plt.grid(True)
plt.loglog(in_values, in_hist, 'ro-')
plt.loglog(out_values, out_hist, 'bv-')
plt.legend(['In-degree', 'Out-degree'])
plt.xlabel('Degree')
plt.ylabel('Jumlah node')
plt.title('Jaringan email sebuah institusi riset Eropa yang besar')
plt.savefig('./output/distribusi_degree_jaringan.png')
plt.close()
print('Selesai')
print('')

print('Koefisien clustering')
print('--------------------')
print('')
G_ud = G.to_undirected()
print('Koefisien clustering: %.3f' % nx.average_clustering(G_ud))
