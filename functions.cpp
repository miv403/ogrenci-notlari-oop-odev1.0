#include <fstream>
#include <iostream>
#include <cstring> //strtok()
#include <string>
#include <vector>
#include "class.h"

using namespace std;

Student::Student() {


}

void StList::readFromCSV(ifstream& dosya){

    string line{};

    getline(dosya, line);

    while(getline(dosya, line)) {

        Student* student = new Student;

        std::vector<string> tokens;
        size_t pos = 0;
        string token;
        string delimiter = ",";
        while ((pos = line.find(delimiter)) != string::npos) {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        tokens.push_back(line);

        cout << tokens.at(0) << "\t";
        cout << tokens.at(1) << "\t";
        cout << tokens.at(2) << "\t";
        cout << tokens.at(6) << endl;

        student->ad = tokens.at(0);
        student->ogrNo = tokens.at(1);
        student->sinav0 = stod(tokens.at(2));
        student->sinav1 = stod(tokens.at(3));
        student->odev = stod(tokens.at(4));
        student->final = stod(tokens.at(5));

        this->addBack(student);
    /*
        if(tokens.at(6) == "\n")
            student->devamSayisi = 0;
        else 
            student->devamSayisi = stoi(tokens.at(6));
    */
    }
}

void Student::average() {

    ortalama = (sinav0 + sinav1 + odev) * 0.2 + final * 0.4;
}

bool Student::isPass() {

    return ortalama >= 50 ? true : false;
}

StList::StList()							// constructor
{
    head = NULL;
}

StList::~StList()							// destructor
{
    while (!empty()) removeFront();
}

bool StList::empty() const							// is list empty?
{
    return head == NULL;
}

void StList::addBack(Student* node)
{
    if (head == NULL) head = node;
    else
    {
        Student* first = head;
        while (first->next != NULL) first = first->next;
        first->next = node;
    }
}

void StList::removeFront()							// remove front item
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    Student* temp	= head;									// save current head
//  head				= head->next;							// skip over old head
    delete temp;												// delete the old head
}

void StList::printDebug()
{
    if (empty())
    {
        cout << "List is empty !" << endl;
        return;
    }

    Student* first = head;
    while (first != NULL)
    {
        cout << first-> ad <<  "\t" << first->ogrNo << endl;
        first = first->next;
    }
}