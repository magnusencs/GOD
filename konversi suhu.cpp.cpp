#include <iostream>
#include <string>
using namespace std;

string convertTemperature(double temp, char unitFrom, char unitTo) {
    if (unitFrom == unitTo) cout<< (temp << " "<< unitTo);

    double convertedTemp;
    switch (unitFrom) {
        case 'C': case 'c':
            if (unitTo == 'F' || unitTo == 'f') convertedTemp = (temp * 9/5) + 32;
            else if (unitTo == 'K' || unitTo == 'k') convertedTemp = temp + 273.15;
            else if (unitTo == 'R' || unitTo == 'r') convertedTemp = temp * 4/5;
            break;
        case 'F': case 'f':
            if (unitTo == 'C' || unitTo == 'c') convertedTemp = (temp - 32) * 5/9;
            else if (unitTo == 'K' || unitTo == 'k') convertedTemp = (temp + 459.67) * 5/9;
            else if (unitTo == 'R' || unitTo == 'r') convertedTemp = (temp - 32) * 4/9;
            break;
        case 'K': case 'k':
            if (unitTo == 'C' || unitTo == 'c') convertedTemp = temp - 273.15;
            else if (unitTo == 'F' || unitTo == 'f') convertedTemp = (temp * 9/5) - 459.67;
            else if (unitTo == 'R' || unitTo == 'r') convertedTemp = (temp - 273.15) * 4/5;
            break;
        case 'R': case 'r':
            if (unitTo == 'C' || unitTo == 'c') convertedTemp = temp * 5/4;
            else if (unitTo == 'F' || unitTo == 'f') convertedTemp = (temp * 9/4) + 32;
            break;
        default:
            return "Unit tidak valid";
    }

    return to_string(convertedTemp) + " " + unitTo;
}

int main() {
    double temp;
    char unitFrom, unitTo, repeat;

    do {
        cout << "Masukkan nilai temperatur: ";
        cin >> temp;

        cout << "Masukkan unit untuk dikonversi (C/F/K/R): ";
        cin >> unitFrom;

        cout << "Ke suhu mana unit akan dikonversi (C/F/K/R): ";
        cin >> unitTo;

        cout << "Temperature setelah dikonversi: " << convertTemperature(temp, unitFrom, unitTo) << endl;

        cout << "Apakah Anda ingin mengulang (y/n)? ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
