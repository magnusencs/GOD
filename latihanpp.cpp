#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   string hasil;
    string input;
    int jumlah_kata;
    int jumlah_spasi=0;
    cin>>jumlah_kata;
    cin.ignore();
    getline(cin, input);
    for (char spasi : input) {
        if (spasi == ' ') {
            jumlah_spasi++;
        }
    }
   //jumlah kata + jumlah spasi karena spasi juga dihitung sebagai karakter
   //jadi spasi ga di peduliin program
    for (int cek = 0; cek<=jumlah_kata+jumlah_spasi-1; ++cek)
    //saya asumsikan program hanya ngecek input sampai index yang user inputkan, karena saya kurang mengerti soalnya
    {
        switch (input[cek]) {
        case '0':
        hasil.push_back(' ');
        break;
        case '1':
        hasil.append("POP");
        break;
        case '2':
        hasil.append("DOR");
        break;
        case '3':
        hasil.append("BANG");
        break;
        case '4':
        hasil.append("BOOMMM");
        break;
        }
    }
    cout << hasil;
    return 0;
}