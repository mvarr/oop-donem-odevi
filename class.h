#include<string>
#ifndef CLASS_H
#define CLASS_H


class student{
public:
student();
~student();
double average(double);
void readFromCSV(const string&);
void print();

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

