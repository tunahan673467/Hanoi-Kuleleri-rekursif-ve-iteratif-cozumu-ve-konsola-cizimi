#include <iostream>

using namespace std;

// Maksimum disk say�s� i�in sabit
const int MAKS_DISK_SAYISI = 10;

// Her kuledeki diskleri tutan diziler
int diskler[3][MAKS_DISK_SAYISI];

// Kulelerdeki disklerin y�ksekli�i
int yukseklikler[3] = {0, 0, 0};

// Disklerin durumunu ekrana yazd�ran fonksiyon
void kuleleriGoster(int maxYukseklik) {
    for (int seviye = maxYukseklik - 1; seviye >= 0; --seviye) {
        for (int kule = 0; kule < 3; ++kule) {
            if (seviye < yukseklikler[kule]) {
                cout << "[" << diskler[kule][seviye] << "] ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }
    cout << " A   B   C " << endl;
}

// Bir disk ta��ma i�lemini ger�ekle�tiren fonksiyon
void diskTasi(int kaynak, int hedef) {
    int disk = diskler[kaynak][--yukseklikler[kaynak]];
    diskler[hedef][yukseklikler[hedef]++] = disk;
}

// Hanoi kuleleri ��z�m algoritmas�
void hanoiCoz(int diskSayisi, int kaynakKule, int hedefKule, int yardimciKule, int& hareketSayisi) {
    if (diskSayisi == 1) {
        diskTasi(kaynakKule, hedefKule);
        hareketSayisi++;
        cout << "Hareket " << hareketSayisi << ":" << endl;
        kuleleriGoster(MAKS_DISK_SAYISI);
        cout << endl;
        return;
    }
    hanoiCoz(diskSayisi - 1, kaynakKule, yardimciKule, hedefKule, hareketSayisi);
    diskTasi(kaynakKule, hedefKule);
    hareketSayisi++;
    cout << "Hareket " << hareketSayisi << ":" << endl;
    kuleleriGoster(MAKS_DISK_SAYISI);
    cout << endl;
    hanoiCoz(diskSayisi - 1, yardimciKule, hedefKule, kaynakKule, hareketSayisi);
}

int main() {
    int diskSayisi;
    cout << "Disk sayisini girin (maksimum " << MAKS_DISK_SAYISI << "): ";
    cin >> diskSayisi;

    if (diskSayisi > MAKS_DISK_SAYISI) {
        cout << "Disk say�s� maksimum de�eri asiyor!" << endl;
        return 1;
    }

    // Ba�lang��ta t�m diskleri ilk kuleye yerle�tir
    for (int i = 0; i < diskSayisi; ++i) {
        diskler[0][i] = diskSayisi - i;
        yukseklikler[0]++;
    }

    int hareketSayisi = 0;
    cout << "Baslangic durumu" << endl;
    kuleleriGoster(MAKS_DISK_SAYISI);
    cout << endl;

    hanoiCoz(diskSayisi, 0, 2, 1, hareketSayisi);

    return 0;
}
