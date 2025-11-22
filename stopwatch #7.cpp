#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void stopwatch(int hours, int minutes, int seconds) {
    for (int h = 0; h < hours; h++) {
        for (int m = 0; m < 60; m++) {
            for (int s = 0; s < 60; s++) {
                cout << "jam: " << h << ", menit: " << m << ", detik: " << s << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
    }
    
    for (int m = 0; m < minutes; m++) {
        for (int s = 0; s < 60; s++) {
            cout << "jam: " << hours << ", menit: " << m << ", detik: " << s << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    
    for (int s = 0; s < seconds; s++) {
        cout << "jam: " << hours << ", menit: " << minutes << ", detik: " << s << endl;
        this_thread::sleep_for(chrono::seconds(1));
    
    }
}

int main() {
    cout << "masukkan nilai (satuan jam): ";
    int hours;
    cin >> hours;
    
    cout << "masukkan nilai (satuan menit): ";
    int minutes;
    cin >> minutes;
    
    cout << "masukkan nilai (satuan detik): ";
    int seconds;
    cin >> seconds;
    
    stopwatch(hours, minutes, seconds);
    
    cout << "STOPWATCH SELESAI" << endl;
    
    return 0;
}
