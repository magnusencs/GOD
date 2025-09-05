#include <iostream>
#include <map>
#include <iomanip> // untuk setprecision
#include <algorithm> // untuk transform
#include <cctype> // untuk toupper

using namespace std;

// Fungsi untuk mengubah string menjadi huruf kecil semua
string toLowercase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    // Membuat map untuk menyimpan item dan harganya
    map<string, double> shoppingList;

    // Menambahkan item dan harga ke dalam map
    shoppingList["apple"] = 1.99;
    shoppingList["banana"] = 0.99;
    shoppingList["milk"] = 2.49;
    shoppingList["bread"] = 1.79;
    shoppingList["eggs"] = 3.99;

    char choice;
    double totalPrice = 0.0;

    do {
        // Menampilkan menu
        cout << "Daftar barang yang tersedia:\n";
        for (const auto& item : shoppingList) {
            cout << item.first << " - Rp" << fixed << setprecision(2) << item.second << endl;
        }

        // Meminta pengguna memilih item
        cout << "\nMasukkan nama barang yang ingin Anda tambahkan ke daftar belanja: ";
        string itemChoice;
        cin >> itemChoice;

        // Mengubah input pengguna menjadi huruf kecil
        itemChoice = toLowercase(itemChoice);

        // Mengecek apakah item ada di daftar
        auto it = shoppingList.find(itemChoice);
        if (it != shoppingList.end()) {
            totalPrice += it->second; // Menambahkan harga ke total
            cout << it->first << " berhasil ditambahkan ke daftar belanja Anda.\n";
        } else {
            cout << "Maaf, barang tersebut tidak tersedia.\n";
        }

        // Tanya apakah ingin menambah item lagi
        cout << "\nApakah Anda ingin menambah barang lagi? (Y/T): ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    // Menampilkan total harga
    cout << "Total harga belanjaan Anda: Rp" << fixed << setprecision(2) << totalPrice << endl;
    if (totalPrice > 7) {
        cout << "Silakan bayar dengan kartu kredit." << endl;
    }

    return 0;
}