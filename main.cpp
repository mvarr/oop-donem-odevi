#include <iostream>
#include <fstream>
#include <cmath>
#include "class.h"

using namespace std;

bool isStudentPassing(const student& ogrenciler, int index) {
    double devamOrt = 0;
    int devamSayisi = 0;
    
    for(int i = 0; i < ogrenciler.getSize(); i++) {
        if(ogrenciler.getDevamSayisi(i) > 0) { 
            devamOrt += ogrenciler.getDevamSayisi(i);
            devamSayisi++;
        }
    }
    
    if(devamSayisi > 0) {
        devamOrt = round(devamOrt / devamSayisi);
        
        if(ogrenciler.getDevamSayisi(index) <= devamOrt) {
            return false;
        }
    }
    
    double avg = ogrenciler.average(index);
    return avg >= 45;
}

int main() {
    student ogrenciler;
    ogrenciler.readFromCSV("girdi.csv");
    
    int secim;
    do {
        cout << "\n=== Ogrenci Not Sistemi ===" << endl;
        cout << "1. Tum Ogrencileri Listele" << endl;
        cout << "2. Gecen Ogrencileri Listele" << endl;
        cout << "3. Kalan Ogrencileri Listele" << endl;
        cout << "4. Sonuclari Dosyaya Kaydet" << endl;
        cout << "0. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        
        switch(secim) {
            case 1:
                cout << "\n=== Tum Ogrenci Listesi ===" << endl;
                ogrenciler.print();
                cout << "\nDevam etmek icin bir tusa basin...";
                cin.ignore();
                cin.get();
                break;
                
            case 2:
                cout << "\n=== Gecen Ogrenciler ===" << endl;
                for(int i = 0; i < ogrenciler.getSize(); i++) {
                    if(isStudentPassing(ogrenciler, i)) {
                        ogrenciler.print(i);
                    }
                }
                cout << "\nDevam etmek icin bir tusa basin...";
                cin.ignore();
                cin.get();
                break;
                
            case 3:
                cout << "\n=== Kalan Ogrenciler ===" << endl;
                for(int i = 0; i < ogrenciler.getSize(); i++) {
                    if(!isStudentPassing(ogrenciler, i)) {
                        ogrenciler.print(i);
                    }
                }
                cout << "\nDevam etmek icin bir tusa basin...";
                cin.ignore();
                cin.get();
                break;
                
            case 4:
                {
                    ofstream outFile("sonuclar.txt");
                    if(outFile.is_open()) {
                        outFile << "=== ogrenci Sonuclari ===" << endl;
                        outFile << "=========================" << endl << endl;
                        
                        outFile << "Gecen ogrenciler:" << endl;
                        outFile << "-----------------" << endl;
                        for(int i = 0; i < ogrenciler.getSize(); i++) {
                            if(isStudentPassing(ogrenciler, i)) {
                                outFile << "Ad: " << ogrenciler.getAd(i) 
                                       << ", No: " << ogrenciler.getOgrNo(i)
                                       << ", Ortalama: " << ogrenciler.average(i) << endl;
                            }
                        }
                        
                        outFile << "\nKalan ogrenciler:" << endl;
                        outFile << "----------------" << endl;
                        for(int i = 0; i < ogrenciler.getSize(); i++) {
                            if(!isStudentPassing(ogrenciler, i)) {
                                outFile << "Ad: " << ogrenciler.getAd(i) 
                                       << ", No: " << ogrenciler.getOgrNo(i)
                                       << ", Ortalama: " << ogrenciler.average(i) << endl;
                            }
                        }
                        outFile.close();
                        cout << "\nSonuclar 'sonuclar.txt' dosyasina kaydedildi." << endl;
                    } else {
                        cout << "\nDosya olusturma hatasi!" << endl;
                    }
                    cout << "\nDevam etmek icin bir tusa basin...";
                    cin.ignore();
                    cin.get();
                }
                break;
                
            case 0:
                cout << "\nProgramdan cikiliyor..." << endl;
                break;
                
            default:
                cout << "\nGecersiz secim! Lutfen tekrar deneyin." << endl;
                cout << "\nDevam etmek icin bir tusa basin...";
                cin.ignore();
                cin.get();
        }
        
        system("cls"); 
        
    } while(secim != 0);
    
    return 0;
}
