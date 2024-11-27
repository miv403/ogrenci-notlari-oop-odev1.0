#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "class.h"

using namespace std;

/************************** Student *****************************/

void Student::average() {
    ortalama = (sinav0 + sinav1 + odev) * 0.2 + final * 0.4;
}

bool Student::isPass() {
    return ((ortalama >= 50) && devamSayisi >= 7 ) ? true : false;
}

/************************** StList *****************************/

StList::StList() {
    head = NULL;
}

StList::~StList() {
    while (!empty()) remove();
}

void StList::readFromCSV(ifstream& dosya) {

    string line;

    getline(dosya, line); // başlık satırı yok sayılıyor

    while(getline(dosya, line)) { //yeni satır alınıyor

        Student* student = new Student;

        vector<string> tokens = parseLine(line); 

        // ["ziya","123","456", ... ""] // string vektörü

        student->ad = tokens.at(0);
        student->ogrNo = tokens.at(1);
        student->sinav0 = stod(tokens.at(2));
        student->sinav1 = stod(tokens.at(3));
        student->odev = stod(tokens.at(4));
        student->final = stod(tokens.at(5));
        student->next = NULL;

        if(tokens.at(6) == "")
            student->devamSayisi = 0;
        else
            student->devamSayisi = stoi(tokens.at(6));
        add(student);
#ifdef DEBUG
        cout << "added!" <<endl;
#endif
    }
}

void StList::evalAvg() {

    Student* current = head;

    while(current != nullptr) {
        current->average();
        current = current->next;
    }
}

void StList::print(){
    Student* current = head;
    while(current != nullptr){
        cout << setw(12) << setfill(' ') << left;
        cout << current->ad;
        cout << setw(12) << right;
        cout << current->ortalama;
        cout << setw(18) << right;
        cout << (current->isPass() ? "gecti" : "kaldi") << endl;
        current = current->next;
    }
}

void StList::print(int opt){ // ekrana yazdırma
    
    Student* current = head;
    
    opt = !(opt == '0');
    while(current != nullptr){
        if((opt ? current->isPass() : !current->isPass())){
            cout << setw(12) << setfill(' ') << left;
            cout << current->ad;
            cout << setw(12) << right;
            cout << current->ortalama;
            cout << setw(18) << right;
            cout << (current->isPass() ? "gecti" : "kaldi") << endl;
        }
        current = current->next;
    }
}

void StList::print(string& dosyaStr, int opt){ // dosyaya yazdırma
    Student* current = head;
    ofstream dosya(dosyaStr, ios::trunc);

    dosya << "ad,ortalama,gecme durumu" << endl;

    switch (opt) {
    case '2':
        while(current != nullptr) {
            dosya << current->ad << ',';
            dosya << current->ortalama << ',';
            dosya << (current->isPass() ? "gecti" : "kaldi") << endl;
            current = current->next;
        }
    break;
    default:
        opt = (opt == '0') ? false : true;
        while(current != nullptr){
            if((opt ? current->isPass() : !current->isPass())){
                dosya << current->ad << ',' ;
                dosya << current->ortalama << ',';
                dosya << (current->isPass() ? "gecti" : "kaldi") << endl;
            }
            current = current->next;
        }
    break;
    }

}


void StList::add(Student* node) {
    if (head == NULL) head = node;
    else {
        Student* first = head;
        while (first->next != NULL) {
            first = first->next;
        }
        first->next = node;
    }
}

void StList::remove() {
    if (empty()) {
        cout << "List is empty !" << endl;
        return;
    }

    Student* temp	= head;     // save current head
    head = head->next;          // skip over old head
    delete temp;                // delete the old head
}

bool StList::empty() const {
    return head == NULL;
}

vector<string> StList::parseLine(string& line) {
    // alınan satırın virgülle vektöre eklenmesi

    vector<string> tokens; // degerlerin listesi
    size_t pos = 0;
    string token;
    string delimiter = ",";

    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line);

    return tokens;
}

#ifdef DEBUG
void StList::printDebug() {
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    Student* first = head;

    cout << "printDebug(): " << endl;
    cout << "ad\togrNo\tsinav0\tsinav1\todev\tfinal\tdevamSayisi" << endl;
    while (first != NULL)
    {
        cout << first-> ad <<  "\t";
        cout << first->ogrNo << "\t";
        cout << first->sinav0 << "\t";
        cout << first->sinav1 << "\t";
        cout << first->odev << "\t";
        cout << first->final << "\t";
        cout << first->devamSayisi << endl;
        first = first->next;
    }
}
#endif
