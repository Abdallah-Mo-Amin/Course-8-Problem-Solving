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

stDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
{
    stDate Date;
    short RemainngDays = DayOrderInYear;
    short MonthDays = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Year);
        if (RemainngDays > MonthDays)
        {
            Date.Month++;
            RemainngDays -= MonthDays;
        }
        else
        {
            Date.Day = RemainngDays;
            break;
        }
    }

    return Date;
}

stDate DateAddDays(short Days, stDate Date)
{
    short RemainngDays = Days + NumberOfDaysFromTheBeginningOfYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;

    Date.Month = 1;

    while (true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (RemainngDays > MonthDays)
        {
            RemainngDays -= MonthDays;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainngDays;
            break;
        }

    }

    return Date;
}

short ReadYear()
{
    short Number = 0;

    cout << "\nPlease enter a year? ";
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

    cout << "\nPlease enter a Month? ";
    cin >> Month;

    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nPlease enter a Month? ";
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

short ReadDaysToAdd()
{
    short Days = 0;
    cout << "\nHow many days to add? ";
    cin >> Days;

    return Days;
}

int main()
{
    stDate Date =  ReadFullDate();
    short Days = ReadDaysToAdd();
    
    Date = DateAddDays(Days, Date);
    cout << "\nDate after adding [" << Days << "] days is: "
    << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    system("pause>0");
    
    
    return 0;
}
