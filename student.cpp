#include "class.h"
#include <fstream>
#include <sstream>
#include <iostream>

student::student() {
    size = 0;
    ad = nullptr;
    ogrNo = nullptr;
    araSinav = nullptr;
    ikinciSinav = nullptr;
    odev = nullptr;
    final = nullptr;
    devamSayisi = nullptr;
}

student::~student() {
    delete[] ad;
    delete[] ogrNo;
    delete[] araSinav;
    delete[] ikinciSinav;
    delete[] odev;
    delete[] final;
    delete[] devamSayisi;
}

double student::average(int index) const {
    return (araSinav[index] * 0.20) + 
           (ikinciSinav[index] * 0.20) + 
           (odev[index] * 0.20) + 
           (final[index] * 0.40);
}

void student::readFromCSV(const string& filename) {
    ifstream file(filename);
    string line;
    
    getline(file, line);
    
    size = 0;
    while (getline(file, line)) {
        size++;
    }
    
    ad = new string[size];
    ogrNo = new string[size];
    araSinav = new double[size];
    ikinciSinav = new double[size];
    odev = new double[size];
    final = new double[size];
    devamSayisi = new int[size];
    
    file.clear();
    file.seekg(0);
    getline(file, line);
    
    int i = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        
        getline(ss, ad[i], ',');
        getline(ss, ogrNo[i], ',');
        
        getline(ss, token, ',');
        araSinav[i] = token.empty() ? 0 : stod(token);
        
        getline(ss, token, ',');
        ikinciSinav[i] = token.empty() ? 0 : stod(token);
        
        getline(ss, token, ',');
        odev[i] = token.empty() ? 0 : stod(token);
        
        getline(ss, token, ',');
        final[i] = token.empty() ? 0 : stod(token);
        
        getline(ss, token, ',');
        devamSayisi[i] = token.empty() ? 0 : stoi(token);
        
        i++;
    }
    
    file.close();
}

void student::print() const {
    for(int i = 0; i < size; i++) {
        print(i);
    }
}

void student::print(int index) const {
    cout << "Ad: " << ad[index] 
         << ", No: " << ogrNo[index]
         << ", Ara Sinav: " << araSinav[index]
         << ", 2. Sinav: " << ikinciSinav[index]
         << ", Ödev: " << odev[index]
         << ", Final: " << final[index]
         << ", Devam: " << devamSayisi[index]
         << ", Ortalama: " << average(index) << endl;
} 