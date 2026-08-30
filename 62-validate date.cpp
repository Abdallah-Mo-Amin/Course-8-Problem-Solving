#pragma warning(disable : 4996)
#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include<sstream>

using namespace std;

struct stDate
{
    short Day = 0;
    short Month = 0;
    short Year = 0;
};

bool IsLeapYear(short Year)
{
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
    return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsValidDate(stDate Date)
{
    if (Date.Day < 1 || Date.Day > 31)
        return false;

    if (Date.Month < 1 || Date.Month > 12)
        return false;

    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else
        {
            if (Date.Day > 28)
                return false;
        }
    }


    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > DaysInMonth)
        return false;
    
    return true;


}

short ReadYear()
{
    short Number = 0;

    cout << "Please enter a year? ";
    cin >> Number;

    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Number , Enter a valid one : ";
        cin >> Number;

    }

    return Number;

}

short ReadMonth()
{
    short Month = 0;

    cout << "Please enter a Month? ";
    cin >> Month;

    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a Month? ";
        cin >> Month;
    }

    return Month;
}

short ReadDay()
{
    short Day = 0;
    cout << "\nPlease enter a Day? ";
    cin >> Day;

    return Day;
}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

int main()
{
    while(true)
    {
        system("cls");

        stDate Date = ReadFullDate();

        if (IsValidDate(Date))
            cout << "\n\nYes, Date is a valide date.\n";
        else
            cout << "\n\nNo, Date is NOT a valide date.\n";

        system("pause>0");

    }
 
    return 0;
}
