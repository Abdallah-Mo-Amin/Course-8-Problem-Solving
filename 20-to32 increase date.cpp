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

stDate IncreaseDateBy_x_Days(short Days, stDate Date)
{
    for (short i = 1; i <= Days; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

stDate IncreaseDateBy_x_Weeks(short Weeks, stDate Date)
{
    for (short i = 1; i <= Weeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Month = 1;
        Date.Year++;
    }
    else
    {
        Date.Month++;
    }
    /*
    last check date should not exeed max days in the current month
    example if date is 31/12/2022 increasing one month should not be 31/2/2022,
    it should be 28/2/2022
    */
    short NumberofDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
    if (Date.Month > NumberofDaysInCurrentMonth)
    {
        Date.Day = NumberofDaysInCurrentMonth;
    }

    return Date;
}

stDate IncreaseDateBy_x_Months(short Months, stDate Date)
{
    for (short i = 1; i <= Months; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate IncreaseDateBy_x_Years(int Years, stDate Date)
{
    for (short i = 1; i <= Years; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateBy_x_YearsFaster(int Years, stDate Date)
{
    Date.Year += Years;
    return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return (Date);
}

stDate IncreaseDateByXDecades(short Decade, stDate Date)
{
    for (short i = 1; i <= Decade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

stDate IncreaseDateByXDecadesFaster(short Decade, stDate Date)
{
    Date.Year += (Decade * 10);
    return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
    Date.Year += 100;
    return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
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

        Date1 = IncreaseDateByOneDay(Date1);
        printf("01-Adding one day is    : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateBy_x_Days(10, Date1);
        printf("02-Adding 10 day is     : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateByOneWeek(Date1);
        printf("03-Adding One Week is   : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateBy_x_Weeks(10, Date1);
        printf("04-Adding 10 Weeks is   : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateByOneMonth(Date1);
        printf("05-Adding One Month is  : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateBy_x_Months(5, Date1);
        printf("06-Adding 5 Months is   : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateByOneYear(Date1);
        printf("07-Adding One Year is   : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateBy_x_Years(10, Date1);
        printf("08-Adding 10 Years is   : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateBy_x_YearsFaster(10, Date1);
        printf("09-Adding 10 Years (Faster) is  : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateByOneDecade(Date1);
        printf("10-Adding One Decade is : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateByXDecades(10, Date1);
        printf("11-Adding 10 Decades is : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateByXDecadesFaster(10, Date1);
        printf("12-Adding 10 Decades (Faster) is : %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);
        
        Date1 = IncreaseDateByOneCentury(Date1);
        printf("13-Adding One Century is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);

        Date1 = IncreaseDateByOneMillennium(Date1);
        printf("14-Adding One Millennium is: %d/%d/%d\n", Date1.Day, Date1.Month, Date1.Year);


        system("pause>0");
    }
    
    
    return 0;
}
