#include <iostream>
using namespace std;

bool apakahgenap(int angka){
    return angka % 2 == 0;
}

int main  ()
{
    cout<<"masukkan nomor: ";
    int nomor;
    cin>>nomor;
    cout<<(apakahgenap(nomor) ? "nomor adalah genap" : "nomor adalah ganjil");
    return 0;
}