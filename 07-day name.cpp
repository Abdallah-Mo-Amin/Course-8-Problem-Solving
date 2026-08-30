#pragma warning(disable : 4996)

#include <iostream>
#include <cstdlib>  
#include <iomanip> // this library stored the std::setw
#include <cmath>
#include <string> // this library stired the string object
#include <vector>
#include <cctype>
#include<sstream>
#include <algorithm>
#include <ctime>
#include <fstream> 
#include "MyLib.h"

using namespace std;
using namespace MyLib;

short ReadYear()
{
    short Year = 0;
    cout << "Please enter a year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;
    cout << "\nPlease enter a Month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Month = 0;
    cout << "\nPlease enter a Day? ";
    cin >> Month;

    return Month;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    //short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12) ) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat" };
    return arrDayNames[DayOfWeekOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();

    short DayOrder = DayOfWeekOrder(Day, Month, Year);

    cout << "\nDate       :" << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order  : " << DayOrder << endl;
    cout << "Day Name   : " << DayShortName(DayOrder) << endl;
     


    system("pause>0"); 
    return 0;
}
