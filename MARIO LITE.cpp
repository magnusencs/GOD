#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <windows.h>
#include <mmstream.h>
#include <conio.h>
#include <math.h>
#inlcude <cstdlib>
#pragma comment(lib, "winmm.lib")
using namespace std;

bool has_setup = false;
const int sleeps = 50;
void sleep (int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms))
}

void setup()
{
    const int height = 50;
    const int width = 25;
    for (int i = 0; i<width; i++)
    {
        for (int j = 0; j<height; j++)
        {
            if (i==0 || i==width-1 || j==0 || j==height-1)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
        sleep(sleeps);
    }
    has_setup = true;
}


void border(){
    const int width = 30;
    const int height = 20;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                cout << "*";            
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

class mario {
    private:

    public:

    mario () {
       
    }
};


struct mov {
    int x;
    int y;
};

int main () 
{
    system("color 3d");

}