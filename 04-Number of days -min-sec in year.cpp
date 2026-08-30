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

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Number , Enter a valid one : ";
        cin >> Number;

    }

    return Number;

}

bool IsLeapYear(short Year)
{  
    return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

short NumberOfDaysInYear(short Year)
{
    return (IsLeapYear(Year) ? 366 : 365);
}

short NumberOfHoursInYear(short Year)
{
    return (NumberOfDaysInYear(Year) * 24);
}

int NumberOfMinutesInYear(short Year)
{
    return (NumberOfHoursInYear(Year) * 60);
}

int NumberOfSecondsInYear(short Year)
{
    return (NumberOfMinutesInYear(Year) * 60);
}

int main()
{
 

    short Year = ReadYear();
    cout << "\nNumber of Days      in Year [" << Year << "] is " << NumberOfDaysInYear(Year);
    cout << "\nNumber of Hours     in Year [" << Year << "] is " << NumberOfHoursInYear(Year);
    cout << "\nNumber of Minutes   in Year [" << Year << "] is " << NumberOfMinutesInYear(Year);
    cout << "\nNumber of Seconds   in Year [" << Year << "] is " << NumberOfSecondsInYear(Year);

    system("pause>0");


    return 0;
}

