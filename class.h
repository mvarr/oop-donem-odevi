#ifndef CLASS_H
#define CLASS_H

#include <string>
using namespace std;

class Student {
private:
    string* AD;
    int* ogrno;
    int* Arasinav;
    int* ikinciSinav;
    int* Odev;
    int* Final;
    int* Devam;
    int Count;          // Öğrenci sayısı
    int capacity;       // Maksimum kapasite

public:
    Student(int max_capacity = 200);  // Constructor
    ~Student();                       // Destructor

    void readFromCSV();
    double average(int index) const;
    void print(const string& input);
};

#endif
