#include <iostream>
#include <fstream>
#include <string>
#include "./functions.cpp"

#define NOTLAR "./data/notlar.csv"

using namespace std;

int main() {

    ifstream notlarDosya{};
    
    if(!notlarDosya)
        cerr << "Hata: " << NOTLAR << " dosyasi bulunamadi!" << endl;

    StList list;
    
    notlarDosya.open(NOTLAR);

    list.readFromCSV(notlarDosya);
    notlarDosya.close();
#ifdef DEBUG
    list.printDebug(); //DEBUG
#endif
    list.evalAvg();

#ifdef DEBUG
    Student * current = list.head; // DEBUG

    while(current != nullptr) {
        cout << current->ad << ": " <<  current->ortalama << endl;
        current = current->next;
    }
    //END DEBUG
#endif
    string girdi{};
    string dosyaYolu{};

    cout << "sonuclari dosyaya yazdirmak ister misiniz [E/h]" << endl << "? ";
    getline(cin, girdi);
    
    if(girdi == "E" || girdi == "e") {
        cout << "dosya yolunu giriniz: ";
        getline(cin, dosyaYolu);
        do{                   // FIXME: dosya yolu fonksiyonu 
            cout << endl << "0. kalanlar" << endl;
            cout <<         "1. geçenler" << endl;
            cout <<         "2. tüm liste" << endl;
            getline(cin, girdi);
            if      (girdi == "0") {list.print(0); break;}
            else if (girdi == "1") {list.print(1); break;}
            else if (girdi == "2") {list.print(dosyaYolu); break;}
            else    cerr << "gecersiz secenek!" << endl;
        }while(true);
    }else if(girdi == "H" || girdi == "h") {
        do{
            cout << "0. kalanlar" << endl;
            cout << "1. geçenler" << endl;
            cout << "2. tüm liste" << endl;
            getline(cin, girdi);
            if      (girdi == "0") {list.print(0); break;}
            else if (girdi == "1") {list.print(1); break;}
            else if (girdi == "2") {list.print(); break;}
            else    cerr << "gecersiz secenek!" << endl;
    }while(true);
    }
    return 0;
}
