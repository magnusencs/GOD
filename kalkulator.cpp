#include <iostream>

using namespace std;

int main() {
    char op;
    float num1, num2, result;

    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;

    cout << "Masukkan dua bilangan: ";
    cin >> num1 >> num2;

    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        cout << "Operator yang dimasukkan tidak valid";
        return 0;
    }

    cout << "Hasil: " << num1 << " " << op << " " << num2 << " = " << result;

    return 0;
}