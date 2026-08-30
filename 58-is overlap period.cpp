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

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return !(IsDate1BeforeDate2(Date1, Date2)) && !(IsDate1EqualToDate2(Date1, Date2));
}

enum enDateCompare {Before = -1, Equal = 0, After = 1};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualToDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

void SwapPeriod(stPeriod& Period1, stPeriod& Period2)
{
    stPeriod TempPeriod;
    TempPeriod = Period1;
    Period1 = Period2;
    Period2 = TempPeriod;

}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
{
    if (
        CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before
        || 
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After
        )
        return false;
    else
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

        cout << "\nEnter Period 1:";
        stPeriod Period1 = ReadPeriod();

        stPeriod Period2;
        cout << "\nEnter Period 2:";
        Period2 = ReadPeriod();


        if (IsOverlapPeriods(Period1, Period2))
            cout << "\nYes, Period Overlap\n";
        else
            cout << "\nNo, Period Does Not overlap\n";


        system("pause>0");
    }
    
    
    return 0;
}
