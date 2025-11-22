#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <random>
using namespace std;

void ranged_rand_fill (int howmany, int from, int to, vector<int> &result) {
    for (int i=0; i<=howmany-1; ++i) {
        random_device rd;  
        mt19937 gen(rd()); 
        uniform_int_distribution<> dist(from, to);
        result.push_back(dist(gen));
    }
}


int randgen (int min, int max) {
    static random_device rd;  
    static mt19937 gen(rd()); 
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void generateRandomDoubles()
{ int count_inside= 0;
  int amountofsleep = 0;
  int count_outside = 0;
    vector<int> rand;
    ranged_rand_fill(20, 10, 150, rand);
    vector <int> sleeprand = {10,20,30,40,50,60,70,80,90,100};
    int val = randgen(0, rand.size()-1);
    const int triple = 3;
    for (int i = 0; i<= val; ++i){
    randgen (0, rand.size()-1);
    for (int i = 1; i <randgen(0, rand.size() - 1); ++i) {
        int randomIndex = randgen(0, rand.size() - 1);
        cout << "Random number " << i << ": " << sleeprand[randomIndex] << endl;
        this_thread::sleep_for(chrono::milliseconds((sleeprand[randomIndex])*triple)); 
        count_inside++;
        amountofsleep += sleeprand[randomIndex]; 
       
    }
        count_outside++;
         cout<<"SESI KE-"<<count_outside<<" BERAKHIR"<<endl;
    }
    for (int i = 0; i < 5; ++i) {
        cout << " "<< endl;
    }
    cout<<"jumlah total loop: "<<count_inside<<endl;
    cout<<"jumlah sesi loop: "<<count_outside<<endl;
    cout<<"jumlah total sleep yang dihasilkan: "<<amountofsleep<<endl;
}

int main() {
    char yes;
    do {
        generateRandomDoubles();
        cout << "Do you want to generate again? (y/n): ";
        cin >> yes;
    } while (yes == 'y' || yes == 'Y');
    return 0;
}