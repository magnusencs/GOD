// i will learn on how to make a snake game on me own.


#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
using namespace std;

void sleep(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void setup()
{
    const int height = 50;
    const int width = 25;
    //swap; 
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
        sleep(50);
    }
}

void border()
{
   

}



int main()
{ cout<<"start game?";
    char a = getch();
    if (a == 'y' || a == 'Y');
    cout<<endl;
    system ("color 0A"); 
    border();
    return 0;
}