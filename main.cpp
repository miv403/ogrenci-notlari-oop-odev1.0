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

    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string BCYAN = "\033[96m";
    const string RESET = "\033[0m";  // Resets to default color

cout <<" .---,.-..-..-..---. " << endl;
cout <<"  / / | | >  / | | | " << endl;
cout <<" `---'`-' `-'  `-^-' " << endl;
cout <<"             o88                         " << endl;
cout <<" ooooooooooo oooo oooo   oooo ooooooo    " << endl;
cout <<"      8888    888  888   888  ooooo888   " << endl;
cout <<"   8888       888   888 888 888    888   " << endl;
cout <<" o888ooooooo o888o    8888   88ooo88 8o  " << endl;
cout <<"                  o9o888                 " << endl;

cout << RED <<     "              _/                      " << endl;
cout << GREEN <<   "   _/_/_/_/      _/    _/    _/_/_/   " << endl;
cout << YELLOW <<  "      _/    _/  _/    _/  _/    _/    " << endl;
cout << BLUE <<    "   _/      _/  _/    _/  _/    _/     " << endl;
cout << MAGENTA << "_/_/_/_/  _/    _/_/_/    _/_/_/      " << endl;
cout << CYAN <<    "                   _/                 " << endl;
cout <<           "              _/_/                    " << endl;

cout <<RED <<     "                                            _/           " << endl;
cout <<BCYAN <<   "     _/_/_/        _/_/    _/_/_/  _/_/        _/_/_/    " << endl;
cout <<RED <<  "  _/    _/      _/_/_/_/  _/    _/    _/  _/  _/    _/   " << endl;
cout <<BCYAN <<    " _/    _/      _/        _/    _/    _/  _/  _/    _/    " << endl;
cout <<RED << "  _/_/_/  _/    _/_/_/  _/    _/    _/  _/  _/    _/     " << endl;
cout <<BCYAN <<    " " << endl;
cout <<           " " << endl;


    cout << RED <<     "This text is red."     << RESET << std::endl;
    cout << GREEN <<   "This text is green."   << RESET << std::endl;
    cout << YELLOW <<  "This text is yellow."  << RESET << std::endl;
    cout << BLUE <<    "This text is blue."    << RESET << std::endl;
    cout << MAGENTA << "This text is magenta." << RESET << std::endl;
    cout << CYAN <<    "This text is cyan."    << RESET << std::endl;

    const string DENEME = "\033[91m";
    cout << DENEME <<    "This text is DENEME."    << RESET << std::endl;
}

