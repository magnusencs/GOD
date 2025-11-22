#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class storage {
    public:
    vector<tuple<int, string>> akumul = 
    {
        {{1, "pengertian sains dan filsafat sains"}, 
        {2, "perkembangangan pola berfikir manusia"},
        {3, "peranan sains terhadap perkembangan masyarakat"}, 
        {4, "hakikat dan fungsi sains"},
        {5, "anatomi sains"},
        {6, "metode ilmiah"},
        {7, "nilai nilai dan keterbatasan sains"},
        {8, "Matematika sebagai sarana berfikir deduktif"},
        {9, "statistika sebagai sarana berfikir induktif"},
        {10, "sains dan teknologi"},
        {11, "sains dan masa depan"},
        {12, "hakikat materi dan energi"},
        {13, "energi baru dan terbarukan"},
        {14, "data dan variabel"},
        {15, "besaran, satuan dan manfaatnya dalam kehidupan manusia"}
        }
    };
};

class fungsi {
    public:
    int kelompok;
    fungsi(int kel) {
        kelompok = kel;
    }
    void showkel (storage &store) {
      int id = get<0>(store.akumul[kelompok - 1]);
      string topik = get<1>(store.akumul[kelompok - 1]);
cout << "\nAnda memilih kelompok " << id
     << " dengan topik: " << topik << endl;
    }
};

int main () {
    cout << "masukkan nomor kelompok mu: ";
    int kelompok;
    cin >> kelompok;
    storage store;
    if (kelompok < 1 || kelompok > static_cast<int>(store.akumul.size())) {
        cout << "Nomor kelompok tidak valid\n";
        return 0;
    }

    fungsi f(kelompok);
    f.showkel(store);
    return 0;
}