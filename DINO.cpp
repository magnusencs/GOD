#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

const int width = 80;
const int height = 20;

class Dino {
public:
    int dino_position;

    Dino() : dino_position(40) {}

    void update() {
        dino_position += 1;
        if (dino_position >= width - 2) {
            dino_position = 1;  // Reset ke kiri kalau mentok kanan
        }
    }
};

void border(const Dino& play) {
    const int range_above = 5;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            // Border atas, bawah, kiri, kanan
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << "*";
            }
            // Garis tanah
            else if (i == height - range_above) {
                cout << "-";
            }
            // Dino di atas tanah
            else if (i == height - (range_above + 1) && j == play.dino_position) {
                cout << "D";
            }
            // Ruang kosong
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    Dino play;

    int frameCounter = 0;
    const int frameTime = 5;       // Refresh layar tiap 5ms → super smooth
    const int moveDelay = 18;      // Dino gerak tiap 18 frame = ±90ms

    while (true) {
        border(play);

        // Dino update posisi hanya tiap 18 frame
        if (frameCounter % moveDelay == 0) {
            play.update();
        }

        frameCounter++;

        this_thread::sleep_for(chrono::milliseconds(frameTime));
        system("cls");
    }
    return 0;
}
