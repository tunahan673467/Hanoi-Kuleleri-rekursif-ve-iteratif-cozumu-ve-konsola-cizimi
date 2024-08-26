#include <iostream>
#include <cmath>

void diskitasi(char diskten, char diske, int disk) {
    std::cout <<   disk << ". diski "<<  diskten << "  den "<< diske << " e tasi"<< std::endl;
}

void hanoi(int disksayisi) {
    char cubuklar[3] = {'A', 'B', 'C'};
    int toplamhareket = pow(2, disksayisi) - 1;

    // Eğer disk sayısı çift ise hedef ve yardımcı çubukları değiştir
    if (disksayisi % 2 == 0) {
        std::swap(cubuklar[1], cubuklar[2]);
    }

    // Disklerin başlangıç pozisyonları
    int kaynak = 0, hedef = 2, yardimci = 1;

    // Disk pozisyonlarını izleyen dizi
    int diskpozisyonu[disksayisi];

    // Başlangıçta tüm diskler kaynak çubuğunda
    for (int i = 0; i < disksayisi; i++) {
        diskpozisyonu[i] = kaynak;
    }

    for (int i = 1; i <= toplamhareket; i++) {
        int diskinhareketi = 0;

        // Hareket ettirilecek diski bul
        while ((i & (1 << diskinhareketi)) == 0) {
            diskinhareketi++;
        }

        // Diskin şu anki pozisyonunu alın
        int asayfa = diskpozisyonu[diskinhareketi];

        // Diskin yeni pozisyonunu hesaplayın
        int ysayfa;
        if (asayfa == kaynak) {
            ysayfa = (i % 3 == 1) ? hedef : yardimci;
        } else if (asayfa == hedef) {
            ysayfa = (i % 3 == 1) ? yardimci : kaynak;
        } else {
            ysayfa = (i % 3 == 1) ? kaynak : hedef;
        }

        // Diskin yeni pozisyonunu güncelle
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
