#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "winmm.lib")
using namespace std;

const int WIDTH = 120;
const int HEIGHT = 30;

struct Building {
    int startX;
    int width;
    int height;
    char fill;
};

struct Layer {
    vector<Building> items;
    int baseY;       // ground reference (top of road is HEIGHT - 5)
    double speedMul; // parallax speed factor (relative to dino)
};

class Dino {
public:
    int x;
    int y;
    Dino() : x(5), y(HEIGHT - 6) {}
    void update() { x++; if (x >= WIDTH - 2) x = 1; }
};

void hideCursor() {
    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}

void moveCursor0() {
    COORD c = { 0,0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void drawChar(vector<string>& buf, int x, int y, char ch) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) buf[y][x] = ch;
}

void drawHLine(vector<string>& buf, int x0, int x1, int y, char ch) {
    if (y < 0 || y >= HEIGHT) return;
    if (x0 > x1) swap(x0, x1);
    x0 = max(0, x0); x1 = min(WIDTH - 1, x1);
    for (int x = x0; x <= x1; ++x) buf[y][x] = ch;
}

void drawRect(vector<string>& buf, int x, int yTop, int w, int h, char ch) {
    for (int yy = 0; yy < h; ++yy)
        for (int xx = 0; xx < w; ++xx)
            drawChar(buf, x + xx, yTop + yy, ch);
}

void generateLayer(Layer& L, int seedShift, int minW, int maxW, int minH, int maxH, char fill) {
    L.items.clear();
    int x = 2 + (rand() % 6);
    while (x < WIDTH - 6) {
        int gap = (rand() + seedShift) % 8 + 3;
        int w = (rand() + seedShift) % (maxW - minW + 1) + minW;
        int h = (rand() + seedShift) % (maxH - minH + 1) + minH;
        if (x + w >= WIDTH - 3) break;
        L.items.push_back({ x, w, h, fill });
        x += w + gap;
    }
}

void drawCityLayer(vector<string>& buf, const Layer& L, int groundY, int frame) {
    for (const auto& b : L.items) {
        int top = groundY - b.height;
        drawRect(buf, b.startX, top, b.width, b.height, b.fill);
        // windows twinkle
        for (int yy = top + 1; yy < groundY - 1; yy += 2) {
            for (int xx = b.startX + 1; xx < b.startX + b.width - 1; xx += 2) {
                if (((xx + yy + frame) % 7) == 0) drawChar(buf, xx, yy, '.');
            }
        }
        // building roof detail
        for (int xx = b.startX; xx < b.startX + b.width; ++xx) {
            if ((xx + frame) % 6 == 0) drawChar(buf, xx, top - 1, '_');
        }
    }
}

void render(const vector<string>& buf) {
    moveCursor0();
    for (int i = 0; i < HEIGHT; ++i) {
        DWORD written;
        WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), buf[i].c_str(), (DWORD)buf[i].size(), &written, nullptr);
        WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), "\n", 1, &written, nullptr);
    }
}

int main() {
    system("color 78");
    srand((unsigned)time(nullptr));
  
    hideCursor();

    // music loop (ubah path sesuai file kamu)
    PlaySound(TEXT("C:\\Users\\MyBook Hype\\Videos\\BILLYIDOL.WAV"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    Dino dino;

    const int groundY = HEIGHT - 5;

    Layer farL{ {}, groundY, 0.3 };   
    Layer midL{ {}, groundY, 0.6 };   
    Layer nearL{ {}, groundY, 1.0 };  

    generateLayer(farL, 11, 6, 12, 5, 9, '=');
    generateLayer(midL, 23, 6, 10, 7, 12, '#');
    generateLayer(nearL, 47, 4, 8, 6, 10, '#');

    int frame = 0;
    int dashShift = 0;

    while (true) {
        vector<string> buf(HEIGHT, string(WIDTH, ' '));

        // border
        for (int x = 0; x < WIDTH; ++x) { buf[0][x] = '*'; buf[HEIGHT - 1][x] = '*'; }
        for (int y = 0; y < HEIGHT; ++y) { buf[y][0] = '*'; buf[y][WIDTH - 1] = '*'; }

        // sky sparkles
        for (int i = 0; i < 60; ++i) {
            int sx = (i * 17 + frame * 3) % (WIDTH - 2) + 1;
            int sy = (i * 31 % (HEIGHT / 2));
            if ((i + frame) % 23 == 0) drawChar(buf, sx, sy + 1, '.');
        }

        // parallax shift (we "move" road dashes; buildings regenerate when dino wraps)
        drawCityLayer(buf, farL, groundY - 2, frame);
        drawCityLayer(buf, midL, groundY - 1, frame);
        drawCityLayer(buf, nearL, groundY, frame);

        // road & dash animation
        drawHLine(buf, 1, WIDTH - 2, groundY + 1, '-');
        for (int x = 2; x < WIDTH - 2; x += 6) {
            int dx = (x + dashShift) % (WIDTH - 3);
            drawChar(buf, 1 + dx, groundY + 2, '-');
            drawChar(buf, 2 + dx, groundY + 2, '-');
        }

        // dino
        drawChar(buf, dino.x, dino.y, 'D');

        render(buf);

        if (frame % 2 == 0) dino.update();

        // regenerate city when dino wraps
        if (dino.x == 1) {
            generateLayer(farL, rand() % 1000, 6, 12, 5, 9, '=');
            generateLayer(midL, rand() % 1000, 6, 10, 7, 12, '#');
            generateLayer(nearL, rand() % 1000, 4, 8, 6, 10, '#');
        }

        dashShift = (dashShift + 1) % (WIDTH - 3);
        frame++;

        this_thread::sleep_for(chrono::milliseconds(16)); // ~60 FPS
    }

    return 0;
}
