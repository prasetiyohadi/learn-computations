## Tidal Wave

### Gejala pasang-surut karena gravitasi bulan

1. Dasar teori

Gejala pasang-surut terjadi karena gaya yang dihasilkan dari interaksi bumi
dengan benda langit seperti bulan berbeda di setiap titik di lautan yang
menyelimuti bumi.[1] Gaya pasang-surut adalah perbedaan gaya yang bekerja pada
titik di permukaan planet dengan gaya yang bekerja di pusat planet.[2]

Asumsi:

* Bumi diliputi air dengan ketebalan merata
* Gaya tarik matahari diabaikan
* Gaya sentrifugal rotasi bumi diabaikan
* Posisi awal bulan di sebelah kanan bumi sejajar di sumbu x (sudut 0 radian)
* Titik awal acuan yang diukur perubahan ketinggian airnya adalah titik permukaan di atas permukaan bumi yang berada di sumbu y positif dan sumbu x = 0
* Bulan bergerak mengitari bumi sebagai pusat di titik (0, 0) di bidang XY (ekuatorial) berlawanan arah dengan jarum jam
* Bumi berotasi berlawanan arah dengan jarum jam

Perubahan ketinggian permukaan air maksimum karena gejala pasang surut oleh
bulan yang berputar mengelilingi bumi sepanjang garis ekuator dapat dirumuskan
sebagai berikut[1]:

    h = 3/2 * m/M * (R/D)^3 * R

    dengan:
    h: perubahan ketinggian
    m: massa bulan
    M: massa bumi
    R: jari-jari bumi
    D: jarak bumi dan bulan

2. Program perhitungan ketinggian air laut sebagai fungsi dari posisi bulan

Pseudocode

    ketinggianMaksMin = 3/2 * massaBulan / massaBumi * jariBumi^4/jarakBumiBulan^3

    periodeHari = 24
    periodeBulan = periodeHari * 30
    jumlahIterasi = periodeBulan + 1

    for iterasi in [0..jumlahIterasi]:
        posisiBulan  = 2 * pi * iterasi / periodeBulan
        perubahanKetinggianMaks = ketinggianMaksMin * sin ( 2 * pi * iterasi/periodeBulan )
        perubahanKetinggianTiapJam = ketinggianMaksMin * sin ( 2 * pi * iterasi/periodeHari ) * 
        sin ( 2 * pi * iterasi/periodeBulan )    

### Referensi

[1] [The cause of the tides, and calculating tidal
   forces.](https://squishtheory.wordpress.com/the-tides/)

[2] Suryadi Siregar, Gaya Pasang Surut dan Implikasinya, Prodi Astronomi, 
FMIPA, Institut Teknologi Bandung

[3] [Lunar and Solar Tides](http://scienceprimer.com/lunar-and-solar-tides)
   bulge.](https://squishtheory.wordpress.com/the-earths-equatorial-bulge/)

[4] [Water Levels and Flow](https://www.iho.int/iho_pubs/CB/C-13/english/C-13_Chapter_5.pdf)
