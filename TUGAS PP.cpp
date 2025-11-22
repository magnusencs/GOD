#include <iostream>
using namespace std; 

int tugaspp() {
    cout<<"masukkan nilai suhu: ";
    float suhu;
    cin>>suhu;
    cout<<"masukkan satuan suhu (C/F/K/R): ";
    char satuan;
    cin>>satuan;
    cout<<"masukkan satuan suhu akhir (C/F/K/R): ";
    char satuanakhir;
    cin>>satuanakhir;


    if (satuan == 'C' || satuan == 'c') {
        if (satuanakhir == 'F' || satuanakhir == 'f') {
            float hasil = (suhu * 9/5) + 32;
            cout<<"hasil konversi: "<<hasil<<" F"<<endl;
        } else if (satuanakhir == 'K' || satuanakhir == 'k') {
            float hasil = suhu + 273.15;
            cout<<"hasil konversi: "<<hasil<<" K"<<endl;
        } else if (satuanakhir == 'R' || satuanakhir == 'r') {
            float hasil = suhu * 4/5;
            cout<<"hasil konversi: "<<hasil<<" R"<<endl;
        } else {
            cout<<"satuan akhir tidak valid"<<endl;
        }
    } else if (satuan == 'F' || satuan == 'f') {
        if (satuanakhir == 'C' || satuanakhir == 'c') {
            float hasil = (suhu - 32) * 5/9;
            cout<<"hasil konversi: "<<hasil<<" C"<<endl;
        } else if (satuanakhir == 'K' || satuanakhir == 'k') {
            float hasil = (suhu + 459.67) * 5/9;
            cout<<"hasil konversi: "<<hasil<<" K"<<endl;
        } else if (satuanakhir == 'R' || satuanakhir == 'r') {
            float hasil = (suhu - 32) * 4/9;
            cout<<"hasil konversi: "<<hasil<<" R"<<endl;
        } else {
            cout<<"satuan akhir tidak valid"<<endl;
        }
    } else if (satuan == 'K' || satuan == 'k') {
        if (satuanakhir == 'C' || satuanakhir == 'c') {
            float hasil = suhu - 273.15;
            cout<<"hasil konversi: "<<hasil<<" C"<<endl;
        } else if (satuanakhir == 'F' || satuanakhir == 'f') {
            float hasil = (suhu * 9/5) - 459.67;
            cout<<"hasil konversi: "<<hasil<<" F"<<endl;
        } else if (satuanakhir == 'R' || satuanakhir == 'r') {
            float hasil = (suhu - 273.15) * 4/5;
            cout<<"hasil konversi: "<<hasil<<" R"<<endl;
        } else {
            cout<<"satuan akhir tidak valid"<<endl;
        }
        return 0;

}


int main () {
    const string NPM = "2517051004";
    const string nama = "habiburahman Al-Qomairi";
    cout<<"halo semua, nama saya "<< nama <<endl;
    cout<<"NPM saya: "<< NPM <<endl;
    cout<<"saya akan membuat kalkkulator suhu";
    cout<<endl;
    tugaspp();
    return 0;

}