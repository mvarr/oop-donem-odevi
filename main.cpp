#include <iostream>
#include "function.cpp"
using namespace std;

int main() {
    Student s; // Varsayılan kapasite 200
    s.readFromCSV();

    string input;
    cout << "Bir deger girin (0, 1 veya baska bir sey): ";
    cin >> input;

    s.print(input);
    return 0;
}
