#include <iostream>
using namespace std;

int main ()
{ int angka1;
  int angka2;
  char op;
    cout<<"masukkan angka 1: ";
    cin>>angka1;
    cout<<endl;
    cout<<"masukkan angka 2: ";
    cin>>angka2;
    cout<<endl;
    cout<<"masukkan operator matematika (+*/-): ";
    cin>>op;

   if (op == '*') {
    cout<<"hasil kali "<<angka1<<" "<<"dengan "<<angka2<< " adalah: "<<angka1*angka2;

   } 
   else if (op == '+') {
     cout<<"hasil tambah "<<angka1<<" "<<"dengan "<<angka2<< " adalah: "<<angka1+angka2;
   }
   else if (op == '-') {
     cout<<"hasil kurang "<<angka1<<" "<<"dengan "<<angka2<< " adalah: "<<angka1-angka2;
   }
   else if (op == '/') {
    if (angka2 != 0) {
     cout<<"hasil bagi "<<angka1<<" "<<"dengan "<<angka2<< " adalah: "<<angka1/angka2;
   }
   else {cout<<"pembagi harus lebih besar dari 0.";
return 1;}
}

   else {
    cout<<"operator tidak valid.";
    return 1;
   }
   return 0;

}