#include <iostream>
#include <cmath>
#include <limits> // For std::numeric_limits
#include <ios>    // For std::streamsize
using namespace std;

int main() {
    int a, b;
    bool answer;
    int point = 0; // Initialize point to 0

    cout << "Jika a = 5 dan b = 6, apakah nilai a + b lebih besar dari 10? (true/false): ";
    cin >> boolalpha >> answer;
    if (answer == (5 + 6 > 10)) {
        cout << "Jawaban benar!" << endl;
        point++;
    } else {
        cout << "Jawaban salah!" << endl;
    }

    cout << "Jika a = 3 dan b = 2, apakah nilai a x b kurang dari 10? (true/false): ";
    cin >> boolalpha >> answer;
    if (answer == (3 * 2 < 10)) {
        cout << "Jawaban benar!" << endl;
        point++;
    } else {
        cout << "Jawaban salah!" << endl;
    }

    cout << "Jika a = 25 dan b = 5, apakah nilai a / b sama dengan 6? (true/false): ";
    cin >> boolalpha >> answer;
    if (answer == (25 / 5 == 6)) {
        cout << "Jawaban benar!" << endl;
        point++;
    } else {
        cout << "Jawaban salah!" << endl;
    }

    cout << "Jika a = 4 dan b = 3, apakah nilai a^2 - b^2 sama dengan 7? (true/false): ";
    cin >> boolalpha >> answer;
    if (answer == (pow(4, 2) - pow(3, 2) == 7)) {
        cout << "Jawaban benar!" << endl;
        point++;
    } else {
        cout << "Jawaban salah!" << endl;
    }

    cout << "Jika a = 10 dan b = 2, apakah nilai a / b sama dengan 5 atau lebih besar dari 5? (true/false): ";
    cin >> boolalpha >> answer;
    if (answer == (10 / 2 == 5 || 10 / 2 > 5)) {
        cout << "Jawaban benar!" << endl;
        point++;
    } else {
        cout << "Jawaban salah!" << endl;
    }

    // Check if input failed
    if (cin.fail()) {
        cout << "Input tidak valid. Program berakhir." << endl;
        return 1; // Exit with error code
    }

    cout << "point anda: " << point * 20 << endl;

    return 0;
}
