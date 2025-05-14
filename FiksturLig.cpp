#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

void fiksturOlustur(int takimSayisi) {
    if (takimSayisi % 2 != 0) {
        takimSayisi++; 
    }

    vector<int> takimlar(takimSayisi);
    for (int i = 0; i < takimSayisi; i++) {
        takimlar[i] = i + 1;
    }

    int haftaSayisi = takimSayisi - 1;
    int macSayisi = takimSayisi / 2;
    system_clock::time_point baslangicTarihi = system_clock::now() ;
    for (int hafta = 1; hafta <= haftaSayisi; hafta++) {
        cout << hafta << ". Hafta:\n";
        system_clock::time_point macZamani = baslangicTarihi;
        for (int mac = 0; mac < macSayisi; mac++) {
            int takim1 = takimlar[mac];
            int takim2 = takimlar[takimSayisi - 1 - mac];     
            time_t macZamaniT = system_clock::to_time_t(macZamani);
            cout << "Tarih: " << put_time(localtime(&macZamaniT), "%Y-%m-%d %H:%M") 
                 << " | Takim " << takim1 << " - Takim " << takim2 << endl;
            macZamani += hours(3); 
        }
        baslangicTarihi += hours(24 * 7); 
        int sonTakim = takimlar[takimSayisi - 1];
        for (int i = takimSayisi - 1; i > 1; i--) {
            takimlar[i] = takimlar[i - 1];
        }
        takimlar[1] = sonTakim;
    }

    baslangicTarihi += hours(24 * 7);
    for (int hafta = 1; hafta <= haftaSayisi; hafta++) {
        cout << (hafta + haftaSayisi) << ". Hafta:\n";
        system_clock::time_point macZamani = baslangicTarihi;
        
        for (int mac = 0; mac < macSayisi; mac++) {
            int takim1 = takimlar[mac];
            int takim2 = takimlar[takimSayisi - 1 - mac];
            time_t macZamaniT = system_clock::to_time_t(macZamani);
            cout << "Tarih: " << put_time(localtime(&macZamaniT), "%Y-%m-%d %H:%M") 
                 << " | Takim " << takim2 << " - Takim " << takim1 << endl;
            macZamani += hours(3); 
        }
        baslangicTarihi += hours(24 * 7); 
        int sonTakim = takimlar[takimSayisi - 1];
        for (int i = takimSayisi - 1; i > 1; i--) {
            takimlar[i] = takimlar[i - 1];
        }
        takimlar[1] = sonTakim;
    }
}

int main() {
    int takimSayisi = 20;
    fiksturOlustur(takimSayisi);
    return 0;
}