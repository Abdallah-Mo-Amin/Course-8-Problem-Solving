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

    cout << "Enter a Number? ";
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

int main()
{
    
    short Year = ReadYear();

    if (IsLeapYear(Year))
    {
        cout << "\nYes, Year [" << Year << "] is leap year\n";
    }
    else
    {
        cout << "\nNo, Year  [" << Year << "] is NOT leap year\n";
    }


    system("pause>0");
    return 0;
}

