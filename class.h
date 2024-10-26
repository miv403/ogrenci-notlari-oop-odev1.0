#include <string>

using namespace std;
class Student {
    public:
        void average();
        bool isPass();
        Student * next;
// private kaldırdım: readFromCSV ile içeriye ekleme olmuyor
        string ad;
        string ogrNo;
        double sinav0;
        double sinav1;
        double odev;
        double final;
        int devamSayisi;
        double ortalama;
};


class StList
{
    public:
    Student* head;	// pointer to the head of list

    StList();	// empty list constructor
    ~StList();	// destructor

    void readFromCSV(ifstream&);
    void evalAvg();
    void print(int); // yerleri değşecek
    void print(string); //dosyaya yazdirma
    void print(); // tüm liste
    bool empty() const;									// is list empty?
    void addBack(Student*);		// add to back of list
    void removeFront();									// remove front item of list

    void printDebug(); // DEBUG için

};