#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    system("color 3d")
    int jumlahangka;
    cin>>jumlahangka;
    int arr[jumlahangka];
    int res[jumlahangka];
    int elemen;
    for (int i = 0; i<=jumlahangka-1; ++i) {
        cin>>elemen;
        arr[i] = elemen;

    }
    
    for (int balik = jumlahangka-1; balik>=0; --balik){
        res[jumlahangka-1-balik] = arr[balik];
    }
   
    return 0;
}
