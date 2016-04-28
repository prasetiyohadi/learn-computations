## Particle Motion Simulation

1. motion.cpp : Particle motion inside triangle in 2D


### Particle motion inside triangle in 2D

Gerakan partikel di dalam ruang yang dibatasi oleh segitiga 2 dimensi.
Definisi segitiga:

* segitiga dibentuk oleh garis-garis y = 4x/3; y = -4x/3+8; dan y = 0
* garis-garis tersebut menjadi syarat batas posisi partikel (y > 4x/3; y > -4x/3+8; y < 0)
* garis y = 4x/3 mempunyai gradien m = 4/3 sehingga sudut garis tersebut terhadap sumbu +x adalah alpha1 = 0.927 rad
* garis y = -4x/3+8 mempunyai  gradien m = -4/3 sehingga sudut garis tersebut terhadap sumbu +x adalah alpha2 = 2.214 rad
* garis y = 0 mempunyai gradien m = 0 sehingga sudut garis tersebut terhadap sumbu +x adalah 0

Definisi partikel

* posisi awal partikel x = 3 dan y = 2
* kecepatan awal vx = 0.1 dan vy = -1 (variabel vxt & vyt sebagai variabel sementara)
* sudut arah gerak partikel awal adalah theta0 = arctan (vy/vx)

Definisi gerakan
* time step dt = 0.1 detik
* partikel yang terpantul di garis y = 4x/3 mempunyai matriks transformasi posisi 2x2 yaitu T1
* partikel yang terpantul di garis y = -4x/3+8 mempunyai matriks transformasi posisi 2x2 yaitu T2
* iterasi untuk gerakan menggunakan GLB biasa x = x + vx\*dt dan y = y + vy\*dt
* pada setiap iterasi simpan posisi dan kecepatan serta sudut arah pada variabel sementara xt, yt, vxt, vyt, thetat
* uji posisi pada syarat batas
* jika syarat batas y > 4x/3 terpenuhi ubah sudut arah kecepatan dengan persamaan theta0 = 2\*PI + 2\*alpha1 - thetat
* hitung kecepatan baru berdasarkan resultan kecepatan dan sudut arah yang baru
* cerminkan posisi partikel ke sisi yang benar dengan matriks transformasi T1
* jika syarat batas y > -4x/3+8 terpenuhi ubah sudut arah kecepatan dengan persamaan theta0 = 2\*PI + 2\*alpha2 - thetat
* hitung kecepatan baru berdasarkan resultan kecepatan dan sudut arah yang baru
* cerminkan posisi partikel ke sisi yang benar dengan matriks transformasi T2
* jika syarat batas y < 0 terpenuhi ubah sudut arah kecepatan dengan persamaan theta0 = 2\*PI - thetat
* hitung kecepatan baru berdasarkan resultan kecepatan dan sudut arah yang baru
* cerminkan posisi partikel ke sisi yang benar dengan mengubah tanda posisi y
* ulangi iterasi

#### Referensi

* Refleksi terhadap dinding segitiga: [http://www.cimt.plymouth.ac.uk/projects/mepres/alevel/fpure_ch9.pdf](http://www.cimt.plymouth.ac.uk/projects/mepres/alevel/fpure_ch9.pdf)
