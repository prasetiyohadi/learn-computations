// program ini menggunakan bahasa C++ yang menggunakan library <random> yang
// merupakan spesifikasi C++11, cari di google bagaimana cara melakukan
// kompilasi C++ yang menggunakan spesifikasi standar C++11 jika menggunakan
// kompiler yang berjalan di windows, kalau pakai linux tambahkan flag
// -std=gnu++11 atau -std=c++11 untuk mengkompilasi program ini

#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

// definisi kelas Tree
class Tree {
        // variabel keadaan (basah = 3, kering = 2, terbakar = 1, habis = 0)
        // perubahaan keadaan (basah -> kering -> terbakar -> habis)
        // keadaan berubah jika nilai probabilitas perubahan keadaan mencapai 
        // lebih dari 1, setelah keadaan berubah probabilitas direset kembali
        int state;
        // variabel probabilitas
        float probability, next_probability;
    public:
        // konstruktor
        Tree () { 
            state = 3; 
            // probabilitas perubahan awal diatur sebesar 0.5 pada keadaan
            // basah (3)
            probability = 0.5;
        }
        Tree (int s) { 
            state = s; 
            probability = 0.5;
        }
        // fungsi untuk mengambil nilai keadaan
        int get_state() { return state; }
        // fungsi untuk mengambil nilai probabilitas perubahan keadaan
        float get_probability() { return probability; }
        // fungsi untuk mengambil nilai probabilitas baru
        float get_next_probability() { return next_probability; }
        // fungsi untuk mengambil nilai kontribusi probabilitas perubahan keadaan
        float get_contribution() { 
            switch(state) {
                // jika basah (3) kontribusi probabilitas perubahan -0.01
                case 3:
                    return -0.01;
                    break;
                // jika kering (2) kontribusi probabilitas perubahan 0.01
                case 2:
                    return 0.01;
                    break;
                // jika terbakar (1) kontribusi probabilitas perubahan 0.05
                case 1:
                    return 0.05;
                    break;
                // selain itu nilai kontribusinya 0.0
                default:
                    return 0.0;
            }
        }
        // fungsi untuk mengatur nilai keadaan
        void set_state(int s) { state = s; }
        // fungsi untuk mengatur nilai probabilitas dan mengubah keadaan sesuai
        // perubahan nilai probabilitas 
        void set_probability(float p) { 
            if (state > 0) {
                // jika nilai probabilitas baru > 0 dan > 1, ubah nilai keadaan
                if (p >= 1) {
                    state = state - 1;
                    // reset nilai probabilitas
                    p = p - 1;
                // jika nilai probabilitas baru < 0 dan nilai keadaan < 3, ubah 
                // nilai keadaan ke belakang (terbakar -> kering -> basah)
                } else if (p < 0 && state < 3) {
                    state = state + 1;
                    // reset nilai probabilitas
                    p = -p;
                // selain itu nilai probabilitas tetap
                } else probability = p;
            // jika nilai keadaan = 0 maka probabilitas = 0, tidak akan ada
            // perubahan keadaan lagi
            } else probability = 0;
        }
        // fungsi untuk menyimpan nilai probabilitas baru
        void set_next_probability(float p) { next_probability = probability + p; }
};

// definisi kelas Environment
class Environment {
        // variabel kernel matriks 3x3 untuk perhitungan probabilitas perubahan
        float kernel[3][3];
        // variabel wind untuk indikator arah angin (utara/atas = 1,
        // timur/kanan = 2, selatan/bawah = 3, barat/kiri = 4)
        int wind;
    public:
        // konstruktor, nilai awal komponen matriks kernel 1.0
        Environment() { 
            for (int i=0; i<3; i++)
                for (int j=0; j<3; j++)
                    kernel[i][j] = 1.0;
            wind = 0;
        }
        // fungsi untuk mengambil nilai arah angin
        int get_wind() { return wind; }
        // fungsi untuk mengambil nilai komponen matriks kernel versi 1
        // (mengabaikan komponen area paling luar) dan tidak ada perubahan
        // pada nilai kernel
        int get_kernel(int i, int j) { return kernel[i][j]; }
        // fungsi untuk mengambil nilai komponen matriks kernel versi 2
        // (mengabaikan komponen area paling luar) dan nilai kernel tetap 1.0
        // untuk selain tetangga yang keadaannya terbakar (1), 
        // selain itu nilai kernel tetap sesuai dengan yang sudah diatur
        int get_kernel(int i, int j, int s) { 
            if (s == 1) return kernel[i][j];
            else return 1.0;
        }
        // fungsi untuk mengambil nilai komponen matriks kernel versi 3
        // (mengabaikan komponen area paling luar) dan nilai kernel tetap 1.0
        // untuk selain tetangga yang keadaannya terbakar (1), 
        // kontribusi dari tetangga yang keadaannya basah ke pohon yang
        // keadaannya basah diabaikan (nilai kernel = 0.0), 
        // selain itu nilai kernel tetap sesuai dengan yang sudah diatur
        int get_kernel(int i, int j, int s1, int s2) { 
            if (s1 == 3 && s2 == 3) return 0.0;
            else if (s2 == 1) return kernel[i][j];
            else return 1.0;
        }
        // fungsi untuk mengambil nilai komponen matriks kernel versi 4,
        // tidak mengabaikan komponen area paling luar dan nilai kernel tetap 1.0
        // untuk selain tetangga yang keadaannya terbakar (1), 
        // kontribusi dari tetangga yang keadaannya basah ke pohon yang
        // keadaannya basah diabaikan (nilai kernel = 0.0), 
        // selain itu nilai kernel tetap sesuai dengan yang sudah diatur
        int get_kernel(int i, int j, int l, int m, int n, int s1, int s2) {
            if (m == 0 && n == 0) {
                if (i == 0 && j == 0) return 0.0;
                else if (i == 0 && j == 1) return 0.0;
                else if (i == 0 && j == 2) return 0.0;
                else if (i == 1 && j == 0) return 0.0;
                else if (i == 2 && j == 0) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (m == 0 && n == l) {
                if (i == 0 && j == 0) return 0.0;
                else if (i == 0 && j == 1) return 0.0;
                else if (i == 0 && j == 2) return 0.0;
                else if (i == 1 && j == 2) return 0.0;
                else if (i == 2 && j == 2) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (m == l && n == 0) {
                if (i == 0 && j == 0) return 0.0;
                else if (i == 1 && j == 0) return 0.0;
                else if (i == 2 && j == 0) return 0.0;
                else if (i == 2 && j == 1) return 0.0;
                else if (i == 2 && j == 2) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (m == l && n == l) {
                if (i == 0 && j == 2) return 0.0;
                else if (i == 1 && j == 2) return 0.0;
                else if (i == 2 && j == 2) return 0.0;
                else if (i == 2 && j == 1) return 0.0;
                else if (i == 2 && j == 0) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (m == 0 && (n != 0 || n != l)) {
                if (i == 0 && j == 0) return 0.0;
                else if (i == 0 && j == 1) return 0.0;
                else if (i == 0 && j == 2) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (m == l && (n != 0 || n != l)) {
                if (i == 2 && j == 0) return 0.0;
                else if (i == 2 && j == 1) return 0.0;
                else if (i == 2 && j == 2) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if ((m != 0 || m != l) && n == 0) {
                if (i == 0 && j == 0) return 0.0;
                else if (i == 1 && j == 0) return 0.0;
                else if (i == 2 && j == 0) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if ((m != 0 || m != l) && n == l) {
                if (i == 0 && j == 2) return 0.0;
                else if (i == 1 && j == 2) return 0.0;
                else if (i == 2 && j == 2) return 0.0;
                else if (s1 == 3 && s2 == 3) return 0.0;
                else if (s2 == 1) return kernel[i][j];
                else return 1.0;
            }
            else if (s1 == 3 && s2 == 3) return 0.0;
            else if (s2 == 1) return kernel[i][j];
            else return 1.0;
        }
        // fungsi untuk mengatur nilai arah angin dan menentukan nilai kernel
        // berdasarkan arah angin
        void set_wind(int d) {
            switch(d) {
                case 1:
                    wind = 1;
                    kernel[0][0] = 0.5; kernel[0][1] = 1.0; kernel [0][2] = 0.5;
                    kernel[1][0] = 1.0; kernel[1][1] = 1.0; kernel [1][2] = 1.0;
                    kernel[2][0] = 1.5; kernel[2][1] = 2.0; kernel [2][2] = 1.5;
                    break;
                case 2:
                    wind = 2;
                    kernel[0][0] = 1.5; kernel[0][1] = 1.0; kernel [0][2] = 0.5;
                    kernel[1][0] = 2.0; kernel[1][1] = 1.0; kernel [1][2] = 1.0;
                    kernel[2][0] = 1.5; kernel[2][1] = 1.0; kernel [2][2] = 0.5;
                    break;
                case 3:
                    wind = 3;
                    kernel[0][0] = 1.5; kernel[0][1] = 2.0; kernel [0][2] = 1.5;
                    kernel[1][0] = 1.0; kernel[1][1] = 1.0; kernel [1][2] = 1.0;
                    kernel[2][0] = 0.5; kernel[2][1] = 1.0; kernel [2][2] = 0.5;
                    break;
                case 4:
                    wind = 4;
                    kernel[0][0] = 0.5; kernel[0][1] = 1.0; kernel [0][2] = 1.5;
                    kernel[1][0] = 1.0; kernel[1][1] = 1.0; kernel [1][2] = 2.0;
                    kernel[2][0] = 0.5; kernel[2][1] = 1.0; kernel [2][2] = 1.5;
                    break;
                default:
                    wind = 0;
            }
        }
};

// fungsi untuk mengeluarkan nilai keadaan acak untuk satu pohon berdasarkan distribusi 
// eksponensial (output paling sering: 3/basah, output jarang: 2/kering, output langka: 1/terbakar)
int state_gen() {
    // variabel generator nilai acak
    random_device generator;
    // variabel template distribusi eksponensial
    exponential_distribution<double> distribution(4.0);
    double rand = distribution(generator);
    // pemilihan output nilai keadaan
    if (rand < 0.3)
        return 3;
    else if (rand >= 0.3 && rand < 0.8)
        return 2;
    else 
        return 1;
}

int main () {
    // variabel generator nilai acak
    random_device generator;
    // variabel template distribusi uniform untuk mengatur arah angin
    uniform_int_distribution<int> distribution(1, 4);

    // inisialisasi variabel
    // variabel sum: penampung nilai probabilitas perubahan baru
    float sum;
    // variabel length: ukuran area pohon dan iter: jumlah iterasi
    int length = 25, iter = 90;
    // inisialisasi matriks dengan komponen kelas Tree (pohon) dengan ukuran
    // length x length sebagai obyek trees
    Tree trees[length][length];
    // inisialisasi kelas Environment sebagai obyek env
    Environment env;
    // atur arah angin berdasarkan nilai random uniform (1/utara atau 2/timur
    // atau 3/selatan atau 4/barat)
    env.set_wind(distribution(generator));

    // atur nilai komponen-komponen pohon anggota obyek trees dengan nilai
    // keadaan yang dikeluarkan secara acak berdasarkan distribusi eksponensial
    // yang digunakan oleh fungsi state_gen()
    for (int i=0; i<length; i++) 
        for (int j=0; j<length; j++) 
            trees[i][j].set_state(state_gen());

    // tampilkan keadaan awal
    cout << "initial state" << " ( wind: " << env.get_wind() << " )" << endl;

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) 
            cout << trees[i][j].get_state() << "\t";
        cout << endl;
    }

    // mulai iterasi untuk simulasi forest fire dengan algoritma cellular
    // automata sebanyak iter kali
    for (int a=0; a<iter; a++) {
        cout << "iterasi ke: " << a+1 << " ( wind: " << env.get_wind() << " )" << endl;

        for (int i=0; i<length; i++)  
            for (int j=0; j<length; j++) {
                sum = 0;
                for (int m=0; m<3; m++) 
                    for (int n=0; n<3; n++) 
                        // hitung nilai probabilitas keadaan baru berdasarkan
                        // nilai kontribusi tetangga yang diambil dengan fungsi
                        // obyek trees[][].get_contribution() dan nilai kernel yang diperoleh
                        // dari fungsi obyek env.get_kernel()
                        //sum += trees[i+(m-1)][j+(n-1)].get_contribution()*env.get_kernel(m, n);
                        //sum += trees[i+(m-1)][j+(n-1)].get_contribution()*env.get_kernel(m, n, trees[i+(m-1)][j+(n-1)].get_state());
                        //sum += trees[i+(m-1)][j+(n-1)].get_contribution()*env.get_kernel(m, n, trees[i][j].get_state(), trees[i+(m-1)][j+(n-1)].get_state());
                        sum += trees[i+(m-1)][j+(n-1)].get_contribution()*env.get_kernel(m, n, length, i, j, trees[i][j].get_state(), trees[i+(m-1)][j+(n-1)].get_state());
                // atur nilai probabilitas perubahan keadaan baru untuk setiap komponen matriks obyek trees
                trees[i][j].set_next_probability(sum);
            }

        // ubah nilai probabilitas perubahan keadaan sesuai nilai probabilitas
        // perubahan keadaan baru untuk setiap komponen matriks obyek trees
        for (int i=0; i<length; i++)  
            for (int j=0; j<length; j++) 
                trees[i][j].set_probability(trees[i][j].get_next_probability());

        // tampilkan keadaan baru berdasarkan nilai probabilitas perubahan
        // keadaan yang telah diubah berdasarkan nilai probabilitas perubahan 
        // keadaan baru hasil perhitungan cellular automata
        for (int i=0; i<length; i++) { 
            for (int j=0; j<length; j++) 
                cout << trees[i][j].get_state() << "\t";
            cout << endl;
        }
    }

    return 0;
}

