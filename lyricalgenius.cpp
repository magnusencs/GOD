// wav audio testing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <windows.h>
#include <mmstream.h>
#pragma comment(lib, "winmm.lib")
#define IS_YES(pilihan) ((pilihan) == 'y' || (pilihan) == 'Y')

using namespace std;

class delay {
public:
    void delay_print(const string& text, int milliseconds, int delperline) {
        for (char c : text) {
            cout << c;
            this_thread::sleep_for(chrono::milliseconds(milliseconds));
        }
        cout << endl; 
            this_thread::sleep_for(chrono::milliseconds(delperline));
    }
};

class display {
public:
    vector<string> text = {

        "Touch my body tender",
        "'Cause the feeling makes me weak",
        "Kicking off the covers",
        "I see the ceiling while you're looking down at me",
        "How ",
        "can",
        "we",
        "go",
        "back",
        "to",
        "being",
        "friends",
        "When we just shared a bed?",
        "How can you look at me and pretend",
        "I'm someone you've never met?",
    };
};

int main() {
    display disp;
    delay d;
    vector<float> milliseconds = {
        0.108571f, 0.080882f, 0.100000f, 0.077843f, 0, 0, 0, 0, 0, 0, 0, 0, 0.102564f, 0.108571f,
        0.100000f
    };

    vector<float> delperline = {
        2.04f, 3.0f, 1.89f, 1.85f, 0.66f, 0.15f, 0.50f, 0.96f, 0.44f, 0.75f, 0.82f, 0.50f,
        3.0f, 0.8f, 1.75f
    };

    char pilihan;
    do {
        cout << "\nMulai tampilkan lirik? (y/n): ";
        cin >> pilihan;

        if (IS_YES(pilihan)) {
            system("cls");

            
            PlaySound(TEXT("C:\\Users\\MyBook Hype\\Videos\\AUDIOWAVC++"), NULL, SND_FILENAME | SND_ASYNC);

            for (size_t i = 0; i < disp.text.size(); i++) {
                d.delay_print(
                    disp.text[i],
                    <static_cast<int>(milliseconds[i] * 1000),
                    static_cast<int>(delperline[i] * 1000)
                );
            }
            for (int j = 0; j <= 5; j++) {
                cout << "-back to be friends-" << endl;
            }


            PlaySound(NULL, NULL, 0);
        }

        cout << "\nMau jalankan lagi? (y/n): ";
        cin >> pilihan;
        system("cls");

    } while (IS_YES(pilihan));
    return 0;
}






