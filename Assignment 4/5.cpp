#include <iostream>

using namespace std;

int days_arr[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{
public:
    int day, month, year;

    void add_days(int d){
        while(d){
            day++;
            d--;
            if(day > days_arr[month-1])
            {
                day = 1;
                month++;
                if (month == 13)
                {
                    year++;
                    month = 1;
                }
            }
        }
    }

    void subtract_days(int d){
        while(d){
            d--;
            day--;
            if(day <= 0)
            {
                month--;
                if(month == 0)
                {
                    year--;
                    month = 12;
                }
                day = days_arr[month-1];
            }
        }
    }
};

int main()
{
    Date d1;
    int days;
    cout << "Enter date: ";
    cin >> d1.day >> d1.month >> d1.year;
    cout << endl << "Enter days to be added: ";
    cin >> days;
    d1.add_days(days);
    cout << endl << d1.day << "-" << d1.month << "-" << d1.year;
    cout << endl << "Enter days to be subtracted: ";
    cin >> days;
    d1.subtract_days(days);
    cout << endl << d1.day << "-" << d1.month << "-" << d1.year;
    return 0;
}
