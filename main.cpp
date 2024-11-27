#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "./functions.cpp"

#define NOTLAR "./data/notlar.csv"

using namespace std;

void printMenu();
void BASLIK();

int main() {

    BASLIK();

    ifstream notlarDosya{};

    notlarDosya.open(NOTLAR);
    
    if(!notlarDosya){
        cerr << "Hata: " << NOTLAR << " dosyasi bulunamadi!" << endl;
        return 1;
    }

    StList list;

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
        }while(girdi < '0' || girdi > '2');

        list.print(dosyaYolu, girdi);

    }else if(girdi == 'H' || girdi == 'h') {
        do{
            printMenu();
            cin >> girdi;
        }while(girdi < '0' || girdi > '2');

        cout << setw(12) << setfill(' ') << left;
        cout << "ad";
        cout << setw(12) << right;
        cout << "ortalama";
        cout << setw(18) << right;
        cout << "gecme durumu" << endl;
        cout << setw(44) << setfill('-') << "" << endl;

        girdi == '2' ? list.print() : list.print(girdi);
    }
    return 0;
}

void printMenu() {
            cout <<  setw(14) << setfill('-') << "" << endl;
            cout << "0. kalanlar" << endl;
            cout << "1. gecenler" << endl;
            cout << "2. tum liste" << endl;
            cout << "? ";
}

void BASLIK() {

    const string MAGENTA = "\033[35m";
    const string BGREEN = "\033[92m";
    const string RESET = "\033[0m";  // Resets to default color

    cout << MAGENTA << "              _/                      " << endl;
    cout << MAGENTA << "   _/_/_/_/      _/    _/    _/_/_/   " << endl;
    cout << MAGENTA << "      _/    _/  _/    _/  _/    _/    " << endl;
    cout << MAGENTA << "   _/      _/  _/    _/  _/    _/     " << endl;
    cout << MAGENTA << "_/_/_/_/  _/    _/_/_/    _/_/_/      " << endl;
    cout << MAGENTA << "                   _/                 " << endl;
    cout << MAGENTA << "              _/_/                    " << endl;

    cout <<BGREEN << "                                            _/           " << endl;
    cout <<BGREEN << "     _/_/_/        _/_/    _/_/_/  _/_/        _/_/_/    " << endl;
    cout <<BGREEN << "  _/    _/      _/_/_/_/  _/    _/    _/  _/  _/    _/   " << endl;
    cout <<BGREEN << " _/    _/      _/        _/    _/    _/  _/  _/    _/    " << endl;
    cout <<BGREEN << "  _/_/_/  _/    _/_/_/  _/    _/    _/  _/  _/    _/     " << endl;
    cout << RESET << endl << endl;
}

