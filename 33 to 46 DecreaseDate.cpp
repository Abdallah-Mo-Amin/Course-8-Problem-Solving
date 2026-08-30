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

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

stDate DecreaseDateByXDays(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.Year--;
    }
    else
    {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

stDate DecreaseDateByXMonths(short Months,stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}

stDate DecreaseDateByXYears(short Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYearsFaster(short Years, stDate Date)
{
    Date.Year -= Years;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}

stDate DecreaseDateByXDecades(short Decades, stDate Date)
{
    for (short i = 1; i <= Decades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecadesFaster(short Decades, stDate Date)
{
    Date.Year -= (Decades * 10);
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
    Date.Year -= 100;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
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
        stDate Date1 = ReadFullDate();
        
        cout << "\nDate After:\n\n";

        Date1 = DecreaseDateByOneDay(Date1);
        printf("01-Subtracting one day is         : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXDays(10, Date1);
        printf("02-Subtracting 10 days is         : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneWeek(Date1);
        printf("03-Subtracting One Week is        : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXWeeks(10, Date1);
        printf("04-Subtracting 10 Weeks is        : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneMonth(Date1);
        printf("05-Subtracting One Month is       : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXMonths(5, Date1);
        printf("06-Subtracting 5 Months is        : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneYear(Date1);
        printf("07-Subtracting One Year is        : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXYears(10, Date1);
        printf("08-Subtracting 10 Years is        : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXYearsFaster(10, Date1);
        printf("09-Subtracting 10 Years (Faster) is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneDecade(Date1);
        printf("10-Subtracting One Decade is      : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXDecades(10, Date1);
        printf("11-Subtracting 10 Decades is      : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByXDecadesFaster(10, Date1);
        printf("12-Subtracting 10 Decades (Faster) is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneCentury(Date1);
        printf("13-Subtracting One Century is    : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = DecreaseDateByOneMillennium(Date1);
        printf("14-Subtracting One Millennium is : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        system("pause>0");
    }
    
    
    return 0;
}
