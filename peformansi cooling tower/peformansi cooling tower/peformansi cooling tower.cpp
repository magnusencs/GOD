#include <iostream>
using namespace std;

float peformansi(float watertemp_0, float watertemp_end, float wetairtemp) {
    return ((watertemp_0 - watertemp_end) / (watertemp_0 - wetairtemp)) * 100;
}

int main() {
    float watertemp_0, watertemp_end, wetairtemp;
    char loop;

    do {
        cout << "Masukkan suhu air awal (C): ";
        cin >> watertemp_0;
        cout << "Masukkan suhu air akhir (C): ";
        cin >> watertemp_end;
        cout << "Masukkan suhu udara basah (C): ";
        cin >> wetairtemp;

        float result = peformansi(watertemp_0, watertemp_end, wetairtemp);
        cout << "Efisiensi dari cooling tower: " << result << "%" << endl;
        cout << "Apakah Anda ingin mengulang? (y/n): ";
        cin >> loop;

    } while (loop == 'y' || loop == 'Y');

    if (loop != 'y' && loop != 'Y' && loop != 'n' && loop != 'N') {
        cout << "Input tidak valid." << endl;
    }
    else if (loop == 'n' || loop == 'N') {
        cout << "Program ditutup." << endl;
    }

    return 0;
}
