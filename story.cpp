#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;

void jeda(const string& teks, int speed) {
    for (char c : teks) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << endl; 
}

void ending(bool win) {
    if (win) {
        cout << "Anda menang!" << endl;
    } else {
        cout << "Coba lagi." << endl;
    }
}
void endchoice(char pilih_A, char pilih_B)
{
    if (pilih_A)
    {/*TODO: return ending A}*/} 
    else {/* RETURN ENDING B*/}

}
int main() {
    char a;
    bool win;
    int m = 50;
    do {
        jeda("Tes teks untuk game", 200);
        jeda(". . .", 500);
        cout << "BEGIN" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << endl;
        jeda("Anda terbangun di dalam saluran sempit", m);
        cout << endl;
        jeda("Anda melihat tangan anda di ikat.", m);
        cout << "Pilih: A. Lepas ikatan B. Memberontak. Pilih: ";
        
        char pilih;
        cin >> pilih;
        if (tolower(pilih) == 'a') {
            jeda("Anda berhasil melepaskan ikatan", m);
            win = true;
            cout << endl;
            jeda("Setelah anda berjalan pelan-pelan disana", m);
            jeda("Anda mengintip ke sesosok figur hitam tinggi", m);
            cout << "Apa yang ingin anda lakukan?" << endl;
            cout << "A. Menghampirinya." << endl;
            cout << "B. Melanjutkan perjalanan." << endl;
            cout << "Pilih: ";
          
            string pilih2;
            cin.ignore(); 
            getline(cin, pilih2);
            if (tolower(pilih2[0]) == 'a') {
                jeda("MC: Halo.. apakah anda mengenal tempat ini?", m);
                jeda("Sihitam: Halo, kau pasti orang baru disini. Bagaimana dia menangkapmu?", m);
               
                cout << "a. menangkap- apa? apa maksudnya?" << endl;
                cout << "b. menangkap? aku rasa aku sedang berjalan sendirian malam lalu aku.." << endl;
                char pilih3;
                cin >> pilih3;
                if (tolower(pilih3) == 'a') {
                    jeda("sihitam: yaa", m);
                    jeda("...", 200);
                    jeda(" memang biasanya orang baru disini lupa apa yang barusan terjadi. ", m);
                } else {
                    jeda("cerita yang klasik..", m);
                }
                jeda("sihitam: aku disini sudah sangat lama..", m); // Menambahkan percakapan tambahan setelah percakapan dengan MC
                win = false;
            } else {
                jeda("Pilihan yang belum diimplementasikan", m);
            }
        } else if (tolower(pilih) == 'b') {
            jeda("Anda membuat kegaduhan. Dia datang.", m);
            win = false;
        } else {
            jeda("Anda memilih tidak melakukan pilihan di atas.", m);
            jeda("Anda berakhir mati kelaparan disana.", m);
            win = false;
        }
        ending(win);
        
        cout << "Apakah anda ingin mengulang? (Y/T): ";
        cin >> a;
    } while (tolower(a) == 'y');

    return 0;
}
