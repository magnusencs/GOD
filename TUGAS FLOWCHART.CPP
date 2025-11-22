#include <iostream>

using namespace std;

bool passwordandusername(string username, string password){
    const string usr = "habib";
    const string pw = "420";
    return (username == usr && password == pw);
}

int main ()
{ char y;
    int count = 0;
    int maxtry=3;
    bool ulang;

    do 
    {
    string username, password;
    cout<<"masukkan username:";
    cin>>username;
    cout<<"masukkan password:";
    cin>>password;
    if (passwordandusername(username, password)){
        cout<<"login berhasil";
        ulang = false;

    } 
     else {
        ulang = true;
        count++;
        if (count<maxtry) {
            cout<<"kombinasi password dan username salah, coba lagi (y/n)?";
            cin>>y;
        } else {
            cout<<"anda sudah mencoba 3x, program berhenti";
            return 1; }

    }
    } 
    while ((y=='y' || y=='Y') && ulang);
    return 0;
}