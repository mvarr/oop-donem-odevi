#include "class.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Constructor
Student::Student(int max_capacity) : capacity(max_capacity), Count(0) {
    AD = new string[capacity];
    ogrno = new int[capacity];
    Arasinav = new int[capacity];
    ikinciSinav = new int[capacity];
    Odev = new int[capacity];
    Final = new int[capacity];
    Devam = new int[capacity];
}

// Destructor
Student::~Student() {
    delete[] AD;
    delete[] ogrno;
    delete[] Arasinav;
    delete[] ikinciSinav;
    delete[] Odev;
    delete[] Final;
    delete[] Devam;
}

// CSV Dosyasından Verileri Okuma
void Student::readFromCSV() {
    ifstream iFile("girdi.csv");
    if (!iFile.is_open()) {
        cout << "Girdi dosyasi acilamadi!" << endl;
        return;
    }

    string line;
    getline(iFile, line); // Başlık satırını atla

    while (getline(iFile, line) && Count < capacity) {
        stringstream ss(line);
        string temp;

        // AD
        getline(ss, temp, ',');
        AD[Count] = temp;

        // Öğrenci No
        getline(ss, temp, ',');
        ogrno[Count] = stoi(temp);

        // Ara Sınav
        getline(ss, temp, ',');
        Arasinav[Count] = stoi(temp);

        // İkinci Sınav
        getline(ss, temp, ',');
        ikinciSinav[Count] = stoi(temp);

        // Ödev
        getline(ss, temp, ',');
        Odev[Count] = stoi(temp);

        // Final
        getline(ss, temp, ',');
        Final[Count] = stoi(temp);

        // Devam
        if (getline(ss, temp, ',')) {
            Devam[Count] = stoi(temp);
        } else {
            Devam[Count] = 0; // Varsayılan değer
        }

        Count++;
    }

    iFile.close();
    cout << "Veriler basariyla okundu. Toplam ögrenci: " << endl;
}

// Ortalama Hesaplama
double Student::average(int index) const {
    if (index < 0 || index >= Count) {
        return 0.0;
    }
    return (Arasinav[index] * 0.2) + (ikinciSinav[index] * 0.2) +
           (Odev[index] * 0.2) + (Final[index] * 0.4);
}

// Verileri Yazdırma
void Student::print(const string& input) {
    int sayac=0;
    int sayac0=0;
    if (input == "0") {
        cout << "Ortalamasi 50'nin altinda olan ögrenciler:\n";
        for (int i = 0; i < Count; i++) {
            if (average(i) < 50) {
                
                cout << "AD: " << AD[i] << endl;
                cout << "OgrNo: " << ogrno[i] << endl;
                cout << "Ara Sinav: " << Arasinav[i] << endl;
                cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
                cout << "Ödev: " << Odev[i] << endl;
                cout << "Final: " << Final[i] << endl;
                cout << "Devam: " << Devam[i] << endl;
                cout << "Ortalama: " << average(i) << endl;
                cout << "---------------------------" << endl;
                sayac++;
            }
             }
        cout<<"Siniftan kalan sayisi: "<<sayac<<endl;
    } else if (input == "1") {
        cout << "Ortalamasi 50'nin üzerinde olan ögrenciler:\n";
        for (int i = 0; i < Count; i++) {
            if (average(i) >= 50) {
             sayac0++;
                cout << "AD: " << AD[i] << endl;
                cout << "OgrNo: " << ogrno[i] << endl;
                cout << "Ara Sinav: " << Arasinav[i] << endl;
                cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
                cout << "Ödev: " << Odev[i] << endl;
                cout << "Final: " << Final[i] << endl;
                cout << "Devam: " << Devam[i] << endl;
                cout << "Ortalama: " << average(i) << endl;
                cout << "---------------------------" << endl;
            }
        }
           cout<<"Siniftan gecen sayisi: "<<sayac0<<endl;
    } else {
        cout << "Tüm veriler cikti.txt dosyasina yaziliyor...\n";
        ofstream oFile("cikti.txt");
        if (!oFile.is_open()) {
            cout << "Cikis dosyasi acilamadi!" << endl;
            return;
        }
        for (int i = 0; i < Count; i++) {
            oFile << "AD: " << AD[i] << endl;
            oFile << "OgrNo: " << ogrno[i] << endl;
            oFile << "Ara Sinav: " << Arasinav[i] << endl;
            oFile << "Ikinci Sinav: " << ikinciSinav[i] << endl;
            oFile << "Ödev: " << Odev[i] << endl;
            oFile << "Final: " << Final[i] << endl;
            oFile << "Devam: " << Devam[i] << endl;
            oFile << "Ortalama: " << average(i) << endl;
            oFile << "---------------------------" << endl;
        }
        oFile.close();
        cout << "Veriler basariyla cikti.txt dosyasina yazildi.\n";
    }
}
