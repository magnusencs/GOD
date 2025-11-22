#include <iostream>
#include <math.h> //library untuk sintaks pow (nomor, pangkat)
using namespace std; //template std:: agar semua sintaks yang adalah standard iostream tidak perlu ditulis ulang std:: nya

float kuadrat(float nom){
  return pow(nom, 2);  // mengembalikan nilai pangkat dua dari nomor yang di input
}

float kubik(float nom) {
 return pow(nom, 3);  //mengembalikan nilai pangkat tiga dari nomor yang di input
}

unsigned int faktorial (int nom) {
    if (nom == 0 || nom == 1)  //jika bilangan adalah 0 atau 1, maka hasil faktorialnya sudah pasti adalah 1
    {
        return 1;
    }
    return nom*faktorial(nom-1); // ini adalah rekursif, jadi dia akan mengembalilkan nilai bilangan dikali bilangan -1
    //namun terus berputar sampai nom = 1 karena fungsi memanggil dirinya sendiri, sehingga nilai nomor dan nomor-1 berkurang satu untuk setiap putaran.
    //disini, nilai di parameter diubah menjadi unsigned integer karena faktorial hanya menerima bilangan bulat positif
}
int main () {
 cout<<"masukkan bilangan yang akan dioperasikan: ";
 float num; //deklarasi tipe data
 cin>>num; //menanyakan input
 cout<<"hasil dari kuadrat nomor tersebut: "<<kuadrat(num)<<endl;       //menaruh input kedalam parameter fungsi, dioperasikan lalu dicetak.
 cout<<"hasil dari pangkat tiga nomor tersebut: "<<kubik(num)<<endl;
 cout<<"hasil faktorial nomor tersebut: "<<faktorial(num);
 return 0; //mengembalikan nilai karena fungsi int main yang notabene adalah integer harus mengembalikan bilangan bulat.
           // dalam norma programming, nilai 0 mengindikasikan bahwa program berjalan dengan sukses.
}
