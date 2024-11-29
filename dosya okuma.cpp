#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream iFile;
    const int MAX_SIZE = 200;
    string line = "", AD[MAX_SIZE] = {""};
    int location = 0, Count = 0, Final[MAX_SIZE] = {0}, ogrno[MAX_SIZE] = {0}, Arasinav[MAX_SIZE] = {0}, ikinciSinav[MAX_SIZE] = {0}, Odev[MAX_SIZE] = {0};

    iFile.open("girdi.csv");
    if (!iFile.is_open()) {
        cout<< "Girdi dosyası açılamadı!" << endl;
        return 1;
    }

    // İlk satır başlık olduğu için atlanıyor
    getline(iFile, line);

    while (getline(iFile, line) && Count < MAX_SIZE) {
        location = line.find(',');
        AD[Count] = line.substr(0, location);
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        ogrno[Count] = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        Arasinav[Count] = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        ikinciSinav[Count] = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(',');
        Odev[Count] = stoi(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        Final[Count] = stoi(line);
        Count++;
    }

    iFile.close();

    // Ekrana yazdırma
    for (int i = 0; i < Count; i++) {
        cout << "AD: " << AD[i] << endl;
        cout << "OgrNo: " << ogrno[i] << endl;
        cout << "Arasinav: " << Arasinav[i] << endl;
        cout << "Ikinci Sinav: " << ikinciSinav[i] << endl;
        cout << "Odev: " << Odev[i] << endl;
        cout << "Final: " << Final[i] << endl;
        cout << "------------------" << endl;
    }

    // Verileri dosyaya yazdırma
    ofstream oFile("cikti.txt");
    if (!oFile.is_open()) {
        cerr << "Çıkış dosyası açılamadı!" << endl;
        return 1;
    }

    for (int i = 0; i < Count; i++) {
        oFile << "AD: " << AD[i] << endl;
        oFile << "OgrNo: " << ogrno[i] << endl;
        oFile << "Arasinav: " << Arasinav[i] << endl;
        oFile << "Ikinci Sinav: " << ikinciSinav[i] << endl;
        oFile << "Odev: " << Odev[i] << endl;
        oFile << "Final: " << Final[i] << endl;
        oFile << "----------------------------" << endl;
    }
    oFile.close();

    cout << "Veriler cikti.txt dosyasına yazıldı." << endl;

    return 0;
}
