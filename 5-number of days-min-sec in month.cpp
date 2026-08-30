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

using namespace std;

short ReadYear()
{
    short Number = 0;

    cout << "Please enter a year to check? ";
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

    cout << "\nPlease enter a Month to check? ";
    cin >> Month;

    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nPlease enter a Month to check? ";
        cin >> Month;
    }

    return Month;
}

bool IsLeapYear(short Year)
{  
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    if (Month == 2)
        return (IsLeapYear(Year) ? 29 : 28);


    short arr31Days[7] = { 1,3,5,7,8,10,12 };

    for (short i = 1; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month)
        {
            return 31;
        }
    }

    //if you reach here then it's 30 days
    return 30;
    
}

short NumberOfHoursInMonth(short Month, short Year)
{
    return (NumberOfDaysInMonth(Month, Year) * 24);
}

int NumberOfMinutesInMonth(short Month, short Year)
{
    return (NumberOfHoursInMonth(Month, Year) * 60);
}

int NumberOfSecondsInMonth(short Month, short Year)
{
    return (NumberOfMinutesInMonth(Month, Year) * 60);
}

int main()
{
 
    short Year = ReadYear();
    short Month = ReadMonth();
    cout << "\nNumber of Days      in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);
    cout << "\nNumber of Hours     in Month [" << Month << "] is " << NumberOfHoursInMonth(Month, Year);
    cout << "\nNumber of Minutes   in Month [" << Month << "] is " << NumberOfMinutesInMonth(Month, Year);
    cout << "\nNumber of Seconds   in Month [" << Month << "] is " << NumberOfSecondsInMonth(Month, Year);
    cout << endl;
   
    system("pause>0");


    return 0;
}

