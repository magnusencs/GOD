#include <iostream>
using namespace std;
int main () {
    
    /*
    string arr[] = {"Raffly", "Abdul", "Bachtiar", "khaila", "riki", "Mauli"};
    int size = sizeof(arr)/sizeof(arr[0]);
    bool find = false;
    string target = "Bachtiar";
    for (int i = 0; i < size; i++) {
          if (arr[i] == target) {
            cout<<"Nama "<<arr[i]<<" ditemukan pada indeks ke "<<i;
            find = true;
            break;
          }
    }
     if (!find) {
            cout<<"Nama "<<target<<" tidak ditemukan dalam array";
        }
        return 0; */

    int arr[] = {5,3,4,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"array sebelum diurutkan: ";
    for (int i = 0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i<n-1; ++i) //i now just found i dont need to use while for outer loop, 
    //the worst case of sorting is when the first target places last on the array which is n.
    {
        for (int j = 0; j<n-1; ++j) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout<<"Array setelah diurutkan: ";
    for (int i = 0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
    //BIG O(N^2)
        
}