#include <iostream>
#include <cstring>
using namespace std;

class publication{
public:
    char title[50];
    float price;
    void getdata(char *str, float p){
        strcpy(title, str);
        price = p;
    }

    void displaydata(){
        cout << endl << "Title: " << title
             << endl << "Price: " << price;
    }
};

class book: public publication{
public:
    int pages;
    void getdata(char *str, float p, int pg){
        publication::getdata(str, p);
        pages = pg;
    }

    void displaydata(){
        publication::displaydata();
        cout << endl << "Pages: " << pages;
    }
};

class tape: public publication{
public:
    float time;
    void getdata(char *str, float p, float t){
        publication::getdata(str, p);
        time = t;
    }

    void displaydata(){
        publication::displaydata();
        cout << endl << "Time: " << time;
    }
};

int main(){
    publication p;
    book b;
    tape t;
    p.getdata("HIMYM", 1050.5);
    b.getdata("F.R.I.E.N.D.S", 6550.45, 12345);
    t.getdata("Prison Break", 35461.86, 45.50);
    p.displaydata();
    cout << endl;
    b.displaydata();
    cout << endl;
    t.displaydata();
    return 0;
}
