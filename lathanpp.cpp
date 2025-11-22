#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int elemen;
    int n;
    cin>>n;
    int arr[n];
     int terbesar = 0;
    
    for (int i = 0; i<n; ++n) {
        cin>>elemen;
        arr[i] = elemen;
    }
   
    
 //cari terbesar;
    for (int j = 0; j<n; ++j) 
        {
            if (arr[j]>terbesar) {terbesar = arr[j];}
    }
    cout<<terbesar;
    
    
    return 0;
}
