#include <string>

using namespace std;
class Student {
    public:
        Student();
        ~Student();
        void readFromCSV();
        void average();
        void print(int);
        void print(string);
    private:
        string ad;
        string ogrNo;
        double sinav0;
        double sinav1;
        double odev;
        double final;
        int devamSayisi;
        double ortalama;
        Student * next;
        


};


struct StList
{
    Student* head;									// pointer to the head of list

    StList();									// empty list constructor
    ~StList();								// destructor

    bool empty() const;									// is list empty?
    void addBack(const string& e, const int& i);		// add to back of list
    void removeFront();									// remove front item of list

};