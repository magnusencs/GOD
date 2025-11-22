// i will learn on how to make a snake game on me own.


#include <iostream>
#include <conio.h>  
#include <windows.h>
using namespace std;


void draw()
{
    const int height = 40;
    const int width = 40;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                cout << "#"; // Draw border
            }
            else
            {
                cout << " "; // Draw empty space
            }
        }
        cout << endl;
    }
}