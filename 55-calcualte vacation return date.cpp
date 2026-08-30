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

short NumberOfDaysInYear(short Year)
{
    return (IsLeapYear(Year) ? 366 : 365);
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

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat" };
    return arrDayNames[DayOfWeekOrder];
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5) || (DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return !(IsWeekEnd(Date));
}

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
    short WeekEndCounter = 0;


    //in case the day is weekend keep adding one day until you reach business day
    //we get rid of all weekends before the first business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //here we increase the vacation dates to add all weekend to it.
    for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
    {
        if (IsWeekEnd(DateFrom))
            WeekEndCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //in case the return date is weekend keep adding one day until you reach business day
    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}

short ReadVacationDays()
{
    short VacationDays = 0;

    cout << "\nPlease enter vacation days? ";
    cin >> VacationDays;

    return VacationDays;
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

        cout << "Vacation Starts:";
        stDate DateFrom = ReadFullDate();

        short VacationDays = ReadVacationDays();

        stDate DateTo = CalculateVacationReturnDate(DateFrom, VacationDays);
        cout << "\n\nReturn Date: " << DayShortName(DayOfWeekOrder(DateTo))
            << " , " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year;

        
        system("pause>0");
    }
    
    
    return 0;
}
