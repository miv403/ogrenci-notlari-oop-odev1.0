#include <iostream>
#include <fstream>
#include "./functions.cpp"

#define NOTLAR "./data/ornek.csv"

using namespace std;

int main() {
    
    ifstream notlarDosya{};
    StList list;

    notlarDosya.open(NOTLAR);

    list.readFromCSV(notlarDosya);
    notlarDosya.close();
    list.printDebug();
    return 0;
}