#include <iostream>
#include <cmath>
using namespace std;

float convert (int pecahan, float rating= 5.0)
 {
    if(pecahan>100){pecahan=100;}
    float hasil= (rating/100)*pecahan;
    return round(hasil*2)/2;

 }

int main() {
 char ask;
    do {
        
        cout<<"masukkan persentase suka penonton untuk di konversi menjadi rating imbd: "<<endl;
        int pecahan;
        cin>>pecahan;
        cout<<"hasilnya adalah: "<<convert(pecahan)<<endl;

        cout<<"apakah anda ingin mengulang: ";
        cin>>ask;}
    while(ask=='y' || ask == 'Y');
    
    return 0;
      }
    
