#include <iostream>  
using namespace std; //agar tidak perlu menulis std:: pada setiap sintaks dengan namespace std

void siku_kiri (int baris) //fungsi untuk membuat segitiga siku-siku kiri
{
    for (int luar = 0; luar<baris; ++luar) //loop paling luar yang mengatur jumlah baris
    {
        for (int space = baris; space>luar; --space) 
        {
            cout<<" "; //karena bentuknya miring ke kanan, maka perlu ada spasi di depan bintang
        }
        for (int bintang = 0; bintang<=luar; ++bintang){
            cout<<"*"; //setelah spasi, cetak bintang sesuai jumlah baris
        } 
        cout<<endl; //pindah baris setelah sukses pada baris ini
    }
}
void siku_kebalik (int baris) //fungsi untuk membuat segitiga siku-siku kiri terbalik
{
    for (int luar = 0; luar<baris; ++luar) //loop paling luar yang mengatur jumlah baris
    {
     for(int bintang = baris; bintang>luar; --bintang) 
     {
            cout<<"*"; //karena kebalik, bintang dicetak dari paling banyak ke paling sedikit
        } 
    for (int space =0; space<=luar; ++space){
            cout<<" "; //setelah bintang, cetak spasi sesuai jumlah baris agar membentuk siku
        }
        cout<<endl; //pindah baris setelah sukses pada baris ini
    }
    
}
void piramida_ganjil(int baris) //fungsi untuk membuat piramida dengan jumlah bintang ganjil
{
    if (baris < 1)
     {
        return; //jika baris kurang dari 1, tidak perlu mencetak apa-apa
    }
    for (int i = 1; i <= baris; ++i) //loop untuk setiap baris
     {
     
        for (int space = 0; space < baris - i; ++space) {
            cout << " "; //mencetak spasi di depan bintang agar membentuk piramida
        }
      
        for (int j = 0; j < 2 * i - 1; ++j) {
            cout << "*"; //mencetak bintang dengan jumlah ganjil (2*i-1) 
        }
        cout << endl; //pindah baris setelah sukses pada baris ini
    }
}
int main () //fungsi utama
{
    cout<<"masukkan jumlah baris: ";
    int bar;
    cin>>bar; //menerima input jumlah baris
   siku_kiri (bar); //memanggil fungsi siku_kiri
    cout<<endl; //membuat jarak antar bentuk
   siku_kebalik (bar); //memanggil fungsi siku_kebalik
    cout<<endl; //membuat jarak antar bentuk
   piramida_ganjil (bar); //memanggil fungsi piramida_ganjil
    return 0; //mengembalikan nilai 0 menandakan program berjalan sukses
}