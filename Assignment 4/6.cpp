#include <iostream>

using namespace std;

class US_Currency;

class Indian_Currency{
    int rupees, paise;
public:
    Indian_Currency(int r = 0, int p = 0){
        rupees = r;
        paise = p;
    }
    friend Indian_Currency Add_Currency(Indian_Currency, US_Currency);

};

class US_Currency{
    int dollar, cents;
public:
    US_Currency(int d = 0, int c = 0){
        dollar = d;
        cents = c;
    }
    friend Indian_Currency Add_Currency(Indian_Currency, US_Currency);
};

Indian_Currency Add_Currency(Indian_Currency I, US_Currency U){
    Indian_Currency S;
    S.rupees = I.rupees + U.dollar * 62 + (I.paise + U.cents * 62)/100;
    S.paise = (I.paise + U.cents * 62)%100;
    cout << S.rupees << " Rupees, " << S.paise << " Paise";
    return S;
}

int main(){
    Indian_Currency I(25, 50);
    US_Currency U(11, 23);
    Indian_Currency J = Add_Currency(I, U);
    return 0;
}
