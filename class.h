#include <ostream>
#include <string>
#include <vector>

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

class StList {
    public:
        Student* head;	            // pointer to the head of list

        StList();	                // empty list constructor
        ~StList();	                // destructor

        void readFromCSV(ifstream&);
        vector<string> parseLine(string&);
        void evalAvg();
        void print(int);            // yerleri değşecek
        void print(string&, int);   // dosyaya yazdirma
        void print();               // tüm liste
        bool empty() const;         // is list empty?
        void add(Student*);		    // add to back of list
        void remove();              // remove() front item of list
        void printLine(Student*);
        void writeLine(ofstream&, Student*);
        void printDebug(); // DEBUG için
};