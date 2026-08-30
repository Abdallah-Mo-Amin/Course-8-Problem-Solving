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

stDate IncreaseDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }

    return Date;

}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

int GetDiffrenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (IncludeEndDay ? (++Days) : Days);

}

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualToDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
   /* return (CompareDates(Date, Period.StartDate) == enDateCompare::After
        &&
        CompareDates(Date, Period.EndDate) == enDateCompare::Before);*/

    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before
        ||
        CompareDates(Date, Period.EndDate) == enDateCompare::After);
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

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{
    while(true)
    {
        system("cls");

        cout << "\nEnter Period :";
        stPeriod Period = ReadPeriod();

        cout << "\n\nEnter Date to check:\n";
        stDate Date = ReadFullDate();

        if (IsDateInPeriod(Date, Period))
            cout << "\nYes, Date is within Period\n";
        else
            cout << "\nNo, Date is NOT within period\n";

        system("pause>0");
    }
 
    return 0;
}
