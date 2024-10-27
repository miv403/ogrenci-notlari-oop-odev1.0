#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "./functions.cpp"

#define NOTLAR "./data/notlar.csv"

using namespace std;

void printMenu();
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
    char girdi{};
    string dosyaYolu{};

    cout << "sonuclari dosyaya yazdirmak ister misiniz [E/h]" << endl << "? ";
    cin >> girdi;

    if(girdi == 'E' || girdi == 'e') {
        cout << "dosya yolunu giriniz: ";
        cin >> dosyaYolu;
        do{
            printMenu();
            cin >> girdi;
            list.print(dosyaYolu, girdi);
        }while(girdi < '0' && girdi > '2');
    }else if(girdi == 'H' || girdi == 'h') {
        do{
            printMenu();
            cin >> girdi;
            girdi == '2' ? list.print() : list.print(girdi);
           // list.print(girdi); //FIXME: 2 durumu için çalışmıyor
                                    // bkz. -> functions.cpp StList::print(int)
        }while(girdi < '0' && girdi > '2');
    }
    return 0;
}

void printMenu() {
            cout <<  setw(14) << setfill('-') << "" << endl; // FIXME: hizalama hatası var.
            cout << "0. kalanlar" << endl;
            cout << "1. gecenler" << endl;
            cout << "2. tum liste" << endl;
            cout << "? ";
}
