#include <iostream>
#include <cmath>

void diskitasi(char diskten, char diske, int disk) {
    std::cout <<   disk << ". diski "<<  diskten << "  den "<< diske << " e tasi"<< std::endl;
}

void hanoi(int disksayisi) {
    char cubuklar[3] = {'A', 'B', 'C'};
    int toplamhareket = pow(2, disksayisi) - 1;

    // E�er disk say�s� �ift ise hedef ve yard�mc� �ubuklar� de�i�tir
    if (disksayisi % 2 == 0) {
        std::swap(cubuklar[1], cubuklar[2]);
    }

    // Disklerin ba�lang�� pozisyonlar�
    int kaynak = 0, hedef = 2, yardimci = 1;

    // Disk pozisyonlar�n� izleyen dizi
    int diskpozisyonu[disksayisi];

    // Ba�lang��ta t�m diskler kaynak �ubu�unda
    for (int i = 0; i < disksayisi; i++) {
        diskpozisyonu[i] = kaynak;
    }

    for (int i = 1; i <= toplamhareket; i++) {
        int diskinhareketi = 0;

        // Hareket ettirilecek diski bul
        while ((i & (1 << diskinhareketi)) == 0) {
            diskinhareketi++;
        }

        // Diskin �u anki pozisyonunu al�n
        int asayfa = diskpozisyonu[diskinhareketi];

        // Diskin yeni pozisyonunu hesaplay�n
        int ysayfa;
        if (asayfa == kaynak) {
            ysayfa = (i % 3 == 1) ? hedef : yardimci;
        } else if (asayfa == hedef) {
            ysayfa = (i % 3 == 1) ? yardimci : kaynak;
        } else {
            ysayfa = (i % 3 == 1) ? kaynak : hedef;
        }

        // Diskin yeni pozisyonunu g�ncelle
        diskpozisyonu[diskinhareketi] = ysayfa;

        // Diski hareket ettir
        diskitasi(cubuklar[asayfa], cubuklar[ysayfa], diskinhareketi + 1);
    }
}

int main() {
    int disksayisi;
    std::cout << "Disk sayisini giriniz ";
    std::cin >> disksayisi;
    std::cout << " Hanoi kulelerinin  " << disksayisi << " diskli sistemi \n";
    hanoi(disksayisi);
    return 0;
}
