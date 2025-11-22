#include <iostream>
#include <windows.h>
using namespace std;

void persegi_panjang() {
    int baris = 30;
    int kolom = 100;

    for (int i = 0; i < baris; ++i){
        for (int j = 0; j< kolom; ++j) {
           if ( i == 0 || i == baris-1)
           {
            cout<<"-";
           }
        else{
            if ( j == 0 || j == kolom-1){
                cout<<"|";
            }
            else{
                cout<<" ";
            }
        }
}
        cout<<endl;
        Sleep(150);

}
}
int main (){
    persegi_panjang();
    return 0;
}