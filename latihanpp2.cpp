#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int terkecil;
    int terbesar;
    vector<int>bilangan;
    int input;
    for (int i = 0; i<5; ++i){
        cin>>input;
        bilangan.push_back(input);
    }
   
      terkecil = bilangan[0];
    for (int i = 0; i < bilangan.size(); i++) {
        if (bilangan[i] < terkecil) {
            terkecil = bilangan[i];
        } 
    }
    terbesar = bilangan[0];
  
    for (int i = 0; i < bilangan.size(); i++) {
        
        if (bilangan[i] > terbesar) {
            terbesar = bilangan[i];
        }
    }
    cout<<"Bilangan terbesar adalah "<<terbesar<<endl; 
    cout<<"Bilangan terkecil adalah "<<terkecil<<endl;
}