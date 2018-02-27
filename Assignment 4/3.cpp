#include <iostream>
using namespace std;

class DistanceMC;
class DistanceFI;

class DistanceFI{
public:
    int feet, inch;
    DistanceFI(int a = 0, int b = 0){
        feet = a;
        inch = b;
    }
    DistanceMC fi_to_mc();
};

class DistanceMC{
public:
    int meter, cm;
    DistanceMC(int a = 0, int b = 0){
        meter = a;
        cm = b;
    }
    DistanceFI mc_to_fi();
};

DistanceMC DistanceFI::fi_to_mc() {
    DistanceMC d;
    int total = (feet*12+inch)*2.54;
    d.meter = total / 100;
    d.cm = total % 100;
    return d;
}

DistanceFI DistanceMC::mc_to_fi() {
    DistanceFI d;
    int total = (meter*100+cm)/2.54;
    d.feet = total/12;
    d.inch = total%12;
    return d;
}

int main()
{
    DistanceFI d1(2,4), d2;
    DistanceMC d3(8,5), d4;
    d2 = d3.mc_to_fi();
    d4 = d1.fi_to_mc();
    cout << endl << "d2 = " << d2.feet << " feet, " << d2.inch << " inches";
    cout << endl << "d4 = " << d4.meter << " metres, " << d4.cm << " centimeters";
    return 0;
}
