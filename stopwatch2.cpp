#include <iostream>
#include <windows.h>

using namespace std;



void stp(int &h, int& m, int& s) {
   int whole = h*3600 + m*60 + s;

  if (m>59) {
    h += (m/60);
    m = m%60;}
  if (s>59) {
    m += (s/60);
    s = s%60;}

   for (int i = whole; i>=0; --i)
   {
     cout<<(h<10?"0":"")<<h<<":"<<(m<10?"0":"")<<m<<":"<<(s<10?"0":"")<<s<<"\r"<<flush;
     s--;
     if (s<0) {s = 59; m--;}
        if (m<0) {m = 59; h--;}
        Sleep(1000);
        if (h<0) {cout<<"Waktu Habis\n"; break;}

 
   }
}
int main() {
    int h, m, s;
    cout<<"Masukkan jam: "; cin>>h;
    cout<<"Masukkan menit: "; cin>>m;
    cout<<"Masukkan detik: "; cin>>s;
    system("color 78");
    stp(h, m, s);
    return 0;
}