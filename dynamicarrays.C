#include<iostream>
using namespace std;
// int main(){
// int capacity;
// cout<<"how many tickets do you want to buy:\n";
// cin>>capacity;
// int* lotterytickets=new int[capacity];
// for(int i=0;i<capacity;i++){
//     cout<<"Enter a lottery number:\t2";
//     cin>>lotterytickets[i];
//     }
// for(int i=0;i<capacity;i++){
//     cout<< lotterytickets[i]<<",";

// }
// cout<<endl;
// delete[] lotterytickets;
// lotterytickets=nullptr;
// }
int main(){
    int rows,cols;
    cout<<"enter the rows:\n";
    cin>>rows;
    cout<<"enter the cols:";
    cin>>cols;
    //Dinamik 2d dizi oluştur
    int** matrix=new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new int[cols];
    }
    //Değer atama
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            matrix[i][j]=(i+1)*(j+1);//örnek değer
        }
    }
    cout<<"matris: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;++j){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
     for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[]matrix;
    
    }

