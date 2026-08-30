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

int ReadNumber()
{
    unsigned int Number = 0;

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

string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }



    if (Number >= 1 && Number <= 19)
    {
        string arrNumbers[] = {"", "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
            "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
            "Eighteen", "Nineteen"};
        return arrNumbers[Number] + " ";
    }


    if (Number >= 20 && Number <= 99)
    {
        string arr2[] = {"", "", "Twenty" , "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eight", "Ninety"}; 
        return arr2[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Millon " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millons " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billon " + NumberToText(Number % 1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billons " + NumberToText(Number % 1000000000);
    }
    
}

int main()
{
    while (true)
    {
        system("cls");
        unsigned int Number = ReadNumber();
        cout << NumberToText(Number) << endl;
        system("pause>0"); 
    }


    return 0;
}
