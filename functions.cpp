#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "class.h"

using namespace std;

vector<string> StList::parseLine(string& line) {

    vector<string> tokens;
    // alınan satırın virgülle vektöre eklenmesi
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

void StList::readFromCSV(ifstream& dosya) {

    string line;

    getline(dosya, line); // başlık satırı yok sayılıyor

    while(getline(dosya, line)) { //yeni satır alınıyor

        Student* student = new Student;

        vector<string> tokens = parseLine(line); // ["ziya","123","456", ... ""] // string vektörü

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

void Student::average() {
    ortalama = (sinav0 + sinav1 + odev) * 0.2 + final * 0.4;
}

bool Student::isPass() {
    return ((ortalama >= 50) ) ? true : false;
}

StList::StList() {
    head = NULL;
}

StList::~StList() {
    while (!empty()) remove();
}

bool StList::empty() const {
    return head == NULL;
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

void StList::print(int){

    Student* first = head;
    void printimsi(Student*);
    int sayi;
    cout << "0/1 (0, kalanlar; 1, gecenler)" << endl;
    cin >> sayi;
    switch (sayi){
        case 0:
           while(first!=NULL){
            if(!first->isPass()){
                printimsi(first);
            }
            first=first->next;
           }
        break;
        case 1:
            while(first!=NULL){
            if(first->isPass()){
                printimsi(first);
            }
            first=first->next;
           }
           break;
        default:
            cout << "Gecersiz sayi" << endl;
            break;
    }

}
void printimsi(Student* ptr){
    cout << ptr-> ad <<  "\t";
    cout << ptr->ogrNo << "\t";
    cout << ptr->sinav0 << "\t";
    cout << ptr->sinav1 << "\t";
    cout << ptr->odev << "\t";
    cout << ptr->final << "\t";
    cout << ptr->devamSayisi << endl;
}
void StList::print(string dosyastr){
    Student* first=head;
    ofstream dosya(dosyastr, ios::trunc);
    while(first!=NULL){
        if(first->isPass())
            dosya << first->ad << ": Gecti "<< first->ortalama<< endl;
        else if(!first->isPass())
            dosya << first->ad << ": Kaldi "<< first->ortalama<< endl;
        first=first->next;
    }
}

void StList::print(){
    void printimsi(Student*);
    Student* first=head;
    while(first !=NULL){
        printimsi(first);
        first=first->next;
    }
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
