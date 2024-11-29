#include<string>
#ifndef CLASS_H
#define CLASS_H
using namespace std;

class student{
public:
student();
~student();
double average(int index) const;
void readFromCSV(const string&);
void print() const;
void print(int index) const;
int getSize() const { return size; }

string getAd(int index) const { return ad[index]; }
string getOgrNo(int index) const { return ogrNo[index]; }
int getDevamSayisi(int index) const { return devamSayisi[index]; }
double getAraSinav(int index) const { return araSinav[index]; }
double getIkinciSinav(int index) const { return ikinciSinav[index]; }
double getOdev(int index) const { return odev[index]; }
double getFinal(int index) const { return final[index]; }

private:
string* ad; 
string* ogrNo; 
double* araSinav;
double* ikinciSinav;
double* odev;
double* final;
int* devamSayisi;
int size;

} ;
#endif
