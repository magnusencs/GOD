#include <iostream>
using namespace std;
int main ()
{ char angka;
    int res=0;
    do {
            cin >> angka;
            res += (angka - '0');
    } while (angka !='E' && angka != 'e');
    cout << res;
    return 0;
}