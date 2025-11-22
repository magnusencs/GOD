#include <iostream>
#include <vector>
using namespace std;

int main() {
    string ekspresi;
    cout << "Masukkan ekspresi aritmatika: ";
    cin >> ekspresi;

    vector<double> angka;
    vector<char> op;

    // 1. Pisahkan angka dan operator
    string temp = "";
    for (int i = 0; i < ekspresi.size(); i++) {
        char c = ekspresi[i];
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            angka.push_back(stod(temp)); // simpan angka
            op.push_back(c);             // simpan operator
            temp = "";
        } else {
            temp += c;
        }
    }
    // simpan angka terakhir
    if (!temp.empty()) {
        angka.push_back(stod(temp));
    }

    // 2. Proses operator * dan / lebih dulu
    for (int i = 0; i < op.size(); ) {
        if (op[i] == '*' || op[i] == '/') {
            double a = angka[i];
            double b = angka[i+1];
            double hasil;
            if (op[i] == '*') hasil = a * b;
            else hasil = a / b;

            // ganti posisi angka[i] dengan hasil
            angka[i] = hasil;
            // hapus angka[i+1] dan operator[i]
            angka.erase(angka.begin() + i + 1);
            op.erase(op.begin() + i);
        } else {
            i++; // lewati kalau bukan * atau /
        }
    }

    // 3. Proses operator + dan -
    for (int i = 0; i < op.size(); ) {
        double a = angka[i];
        double b = angka[i+1];
        double hasil;
        if (op[i] == '+') hasil = a + b;
        else hasil = a - b;

        angka[i] = hasil;
        angka.erase(angka.begin() + i + 1);
        op.erase(op.begin() + i);
    }

    // 4. Tampilkan hasil
    cout << "Hasil akhir: " << angka[0] << endl;

    return 0;
}
