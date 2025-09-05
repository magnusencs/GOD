#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void loopA()
{ for (int a = 1; a <= 20; a++)
    int i = 1;
    while (i <= a)
    {
        cout << "Loop A: " << i + a<< "     " << endl;
        i+2;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void loopB()
{
    int i = 1;
    while (i <= 20)
    {
        cout << "     " << "Loop B: " << i << endl;
        i += 2;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

int main()
{
    thread tB(loopB);  // Start loopB first
    tB.join();         // Wait for loopB to finish
    cout << "Loop B finished!" << endl;

    thread tA(loopA);  // Start loopA after loopB has finished
    tA.join();         // Wait for loopA to finish
    cout << "Loop A finished!" << endl;

    return 0;
}
