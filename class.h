#include <string>

using namespace std;
class Student {
    public:
        Student();
        ~Student();
        void average();
        bool isPass();
        Student * next;
    private:
        string ad;
        string ogrNo;
        double sinav0;
        double sinav1;
        double odev;
        double final;
        int devamSayisi;
        double ortalama;
};


struct StList
{
    Student* head;									// pointer to the head of list

    StList();									// empty list constructor
    ~StList();								// destructor

    void readFromCSV();
    void print(int); // yerleri değşecek
    void print(string); //dosyaya yazdirma
    void print(); // tüm liste
    bool empty() const;									// is list empty?
    void addBack(const string& e, const int& i);		// add to back of list
    void removeFront();									// remove front item of list

};