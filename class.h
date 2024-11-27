#include <ostream>
#include <string>
#include <vector>

using namespace std;
class Student {
    public:

        void average();
        bool isPass();

        Student * next;
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
        Student* head;	            
        StList();
        ~StList();

        void readFromCSV(ifstream&);
        void evalAvg();
        void print();               // tüm listeyi ekrana yazdırma
        void print(int);            // ekrana yazdırma kalanlar/gecenler
        void print(string&, int);   // dosyaya yazdirma

#ifdef DEBUG
        void printDebug(); // DEBUG için
#endif
    private:
        void add(Student*);		    // listenin sonuna ekleme
        void remove();              // listenin önünden kaldırma
        bool empty() const;
        vector<string> parseLine(string&); // satırları virgülle ayırma
};