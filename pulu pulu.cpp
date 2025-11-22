#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ada unik = pulu pulu
// tidak ada unik = puluuuu
int main() {
    int jumlahangka;
    cin>>jumlahangka;
    int arr[jumlahangka];
    int elemen;
    bool gadaunik = false;
   
    for (int i = 0; i<=jumlahangka-1; ++i) {
        cin>>elemen;
        arr[i] = elemen;

    }
     sort(arr, arr + jumlahangka);


   for (int i = 1; i<=jumlahangka; ++i) {

        if (arr[i] == arr[i-1]) {
            gadaunik = true;
            break;
        }   
   }

   if (gadaunik) {
       cout<<"Puluuuu";
   } else {
       cout<<"Pulu-Pulu";
   }
    
    return 0;
}
