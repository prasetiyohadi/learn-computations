Learn-NetworkX
=============

Files for simple network analysis using networkx python package using datasets from [SNAP](https://snap.stanford.edu/data/).

Setup
-----

- Install Python 2.7 and git.
- Run `setup.sh` (Linux, OS X, Cygwin) or `setup.bat` (Windows)
- Run `./network_analysis.py` or `python network_analysis.py`

Output
------

**Shell output:**

    Input jaringan
    -----------------
    Jaringan Email-EuAll - Email network of a large European Institution (directed
    edge means at least one email was sent October 2003 and March 2005

    Properti jaringan
    -----------------
    Jumlah node: 265214
    Jumlah edge: 420045
    Rata-rata edge: 1.584
    Jumlah strongly connected component: 231000
    Jumlah weakly connected component: 15836

    Distribusi degree
    -----------------
    Pembuatan grafik...
    Selesai

    Koefisien clustering
    --------------------
    Koefisien clustering: 0.067

**File output:**

- ./output/distribusi\_degree\_jaringan.png

![Grafik distribusi degree](output/distribusi_degree_jaringan.png)
