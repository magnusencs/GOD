#include <iostream>
#include <map>
#include <iomanip> // untuk setprecision
#include <algorithm> // untuk transform
#include <cctype> // untuk toupper

using namespace std;


string kecilin(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    
    map<string, double> shoppingList;

   
    shoppingList["apple"] = 1.99;
    shoppingList["banana"] = 0.99;
    shoppingList["milk"] = 2.49;
    shoppingList["bread"] = 1.79;
    shoppingList["eggs"] = 3.99;

    char choice;
    double totalPrice = 0.0;

    do {
       
        cout << "Daftar barang yang tersedia:\n";
        for (const auto& item : shoppingList) {
            cout << item.first << " - Rp" << fixed << setprecision(2) << item.second << endl;
        }

        
        cout << "\nMasukkan nama barang yang ingin Anda tambahkan ke daftar belanja: ";
        string itemChoice;
        cin >> itemChoice;

     
        itemChoice = kecilin(itemChoice);

       
        auto it = shoppingList.find(itemChoice);
        if (it != shoppingList.end()) {
            totalPrice += it->second; 
            cout << it->first << " berhasil ditambahkan ke daftar belanja Anda.\n";
        } else {
            cout << "Maaf, barang tersebut tidak tersedia.\n";
        }
        cout << "\nApakah Anda ingin menambah barang lagi? (Y/T): ";
        cin >> choice;

    } while (toupper(choice) == 'Y');

    cout << "Total harga belanjaan Anda: Rp" << fixed << setprecision(2) << totalPrice*1000 << endl;
    if (totalPrice > 7) {
        cout << "Silakan bayar dengan kartu kredit." << endl;
    }

    return 0;
}