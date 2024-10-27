#include <iostream>
#include <fstream>
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
    list.print("test");
    return 0;
}
