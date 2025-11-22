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
void SetConsoleFontSize(int fontSize) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi = { 0 };
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;              // Width, 0 berarti auto
    cfi.dwFontSize.Y = fontSize;       // Tinggi font dalam pixel
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Bisa juga "Lucida Console"
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
}

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

    

	bool firsttime = true; // Variable to track if it's the first time playing the audio
        cout << "\nMulai tampilkan lirik? (y/n): ";
        cin >> pilihan;
		do {
        if (IS_YES(pilihan)) {
            system("cls");
			system("color 3d"); 
			SetConsoleFontSize(36);
            
            PlaySound(TEXT("C:\\Users\\MyBook Hype\\Videos\\AUDIOWAVC++"), NULL, SND_FILENAME | SND_ASYNC);
            if (firsttime) {
                this_thread::sleep_for(chrono::milliseconds(1300));
                firsttime = false;
				//if you want to play the audio again, you can comment this line out.
                //because the second time the audio play, the lag disappear.
            }
            //this is to make sure the audio is loaded before the text appears.
            //above is a sleep thread designed to fit the delay of the audio when connected through speaker.
			//you can comment it out if you played it with headphone or earphone.
			//since those devices have a lower delay than speaker.
			//or if it turns out it 's not needed indicated by the audio playing without delay 
            // and thus the thread only make the text appear late, you can comment it out too.
            

            for (size_t i = 0; i < disp.text.size(); i++) {
                d.delay_print(
                    disp.text[i],
                    static_cast<int>(milliseconds[i] * 1000),
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




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
