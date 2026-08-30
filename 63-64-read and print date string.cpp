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

string ReadStringDate(string Massage)
{
    string DateString = "";

    cout << Massage;
    getline(cin >> ws, DateString);

    return DateString;
}

vector<string> SplitString(string S1, string delim)
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

stDate StringToDate(string DateString)
{   
    stDate Date;
    vector<string> vDate;

    vDate = SplitString(DateString, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;    
}

string DateToString(stDate Date)
{    
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
    while(true)
    {
        system("cls");

        string DateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
        stDate Date = StringToDate(DateString);
        
        cout << "\nDay:" << Date.Day << endl;
        cout << "Month:" << Date.Month << endl;
        cout << "Year:" << Date.Year << endl;

        cout << "\nYou Enterd: " << DateToString(Date)  << endl;

        system("pause>0");

    }
 
    return 0;
}
