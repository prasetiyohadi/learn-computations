## Particle Motion Simulation

1. motion.cpp : Particle motion inside triangle in 2D
2. motion1.cpp : Particle motion inside triangle in 2D with collision between
  particles and the output is displayed as OpenGL window
3. motion2.cpp : Particle motion inside triangle in 2D with collision between
  particles and the output is displayed as OpenGL window as well as streamed to
  stdout for recording using ffmpeg


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

### Kompilasi program

Untuk melakukan kompilasi program motion1.cpp dan motion2.cpp, gunakan langkah
berikut ini

    g++ motion1.cpp -lGL -lglut -o motion1
    g++ motion2.cpp -lGL -lglut -o motion2

Khusus untuk program motion2.cpp gunakan langkah berikut untuk melakukan
penyimpanan ke video MP4

    ./motion2 | ffmpeg -r 240 -f rawvideo -pix_fmt rgb24 -s 660x440 -i pipe:0 -vcodec libx264 -threads 4 -pix_fmt yuv420p -vf vflip output.mp4

Jika video output terlalu lambat, percepat dengan ffmpeg

    ffmpeg -i output.mp4 -filter:v "setpts=0.25*PTS" output-fast.mp4

### Video output program

Berikut ini adalah output dari program motion2.cpp

<a href="http://www.youtube.com/watch?feature=player_embedded&v=8aVqEdP0xcU" target="_blank"><img src="http://img.youtube.com/vi/8aVqEdP0xcU/0.jpg" alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>

### Referensi

* Refleksi terhadap dinding segitiga: [http://www.cimt.plymouth.ac.uk/projects/mepres/alevel/fpure_ch9.pdf](http://www.cimt.plymouth.ac.uk/projects/mepres/alevel/fpure_ch9.pdf)
