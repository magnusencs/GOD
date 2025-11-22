#include <iostream>
#include <string>
using namespace std;

int main() {
    string password, username;

    cout << "Masukkan password: ";
    cin >> password;

    if (password == "password123") {
        cout << "Password benar. Silakan masukkan username: ";
        cin >> username;

        if (username == "user123") {
            cout << "Selamat datang, " << username << "!" << endl;
        } else {
            cout << "Username salah. Akses ditolak." << endl;
        }

    } else {
        cout << "Password salah. Akses ditinju" << endl;
    }

    return 0;
}