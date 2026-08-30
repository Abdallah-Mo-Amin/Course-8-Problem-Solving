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

short NumberOfDaysFromTheBeginningOfYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i, Year);
    }

    TotalDays += Day;

    return TotalDays;
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

stDate GetSystemDate()
{
    stDate TimeNow;
    time_t t = time(0); // get time now
    tm* now = localtime(&t);
    TimeNow.Year = now->tm_year + 1900;
    TimeNow.Month = now->tm_mon + 1;
    TimeNow.Day = now->tm_mday;

    return TimeNow;

}

bool IsEndOfWeek(stDate Date)
{
    return (DayOfWeekOrder(Date) == 6);
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

short DaysUntilTheEndOfWeek(stDate Date)
{
    return (6 - DayOfWeekOrder(Date));
}

short DaysUntilTheEndOfMonth(stDate Date)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.Year = Date.Year;

    return GetDiffrenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilTheEndOfYear(stDate Date)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date.Year;

    return GetDiffrenceInDays(Date, EndOfYearDate, true);
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
        stDate Date1 = GetSystemDate();
        short DayOrder = DayOfWeekOrder(Date1);

        cout << "Today is " << DayShortName(DayOfWeekOrder(Date1)) << " , "
            << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;
        
        //---------------------------------
        cout << "\n\nIs it End of Week?\n";
        if (IsEndOfWeek(Date1))
            cout << "Yes it is Saturday, end of week.\n";
        else
            cout << "No Not end of week.\n";
        

        //---------------------------------
        cout << "\n\nIs it Weekend?\n";
        if (IsWeekEnd(Date1))
            cout << "Yes it is a week end.\n";
        else
            cout << "No today is " << DayShortName(DayOrder) <<  " it is NOT week end.\n";


        //---------------------------------
        cout << "\n\nIs Business Day?\n";
        if (IsBusinessDay(Date1))
            cout << "Yes it is a business day.\n";
        else
            cout << "No it is NOT a business day.\n";

        //---------------------------------
        cout << "\n\nDays Until end of week : " 
            << DaysUntilTheEndOfWeek(Date1) << " Day(s).";


        cout << "\nDays until end of month : "
            << DaysUntilTheEndOfMonth(Date1) << " Day(s).";

        cout << "\nDays until end of year  : "
            << DaysUntilTheEndOfYear(Date1) << " Day(s).\n";
        system("pause>0");
    }
    
    
    return 0;
}
