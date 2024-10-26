#include <iostream>
#include "class.h"

Student::Student() {


}

void StList::readFromCSV(){
    //stlist içine taşınacak

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

void StList::addBack(const string& e, const int& i)
{
    Student* v	= new Student;
//  v->elem			= e;
//  v->score		= i;
//  v->next			= NULL;

    if (head == NULL) head = v;
    else
    {
        Student* first = head;
//      while (first->next != NULL) first = first->next;
 //     first->next = v;
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
