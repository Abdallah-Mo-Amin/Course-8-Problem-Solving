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

string ReplaceWordsInStringUsingBuildInFunction(string S1, string StringToReplace, string ReplaceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), ReplaceTo);
        pos = S1.find(StringToReplace); // find next
    }
    return S1;
}


string FormatDate(stDate Date, string DateFormat= "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = ReplaceWordsInStringUsingBuildInFunction(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordsInStringUsingBuildInFunction(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordsInStringUsingBuildInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{
    while(true)
    {
        system("cls");

        string DateString = ReadStringDate("Please Enter Date dd/mm/yyyy? ");
        stDate Date = StringToDate(DateString);
        

        cout << FormatDate(Date) << endl;

        cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << endl;

        cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << endl;

        cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << endl;

        cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << endl;

        cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;


        system("pause>0");

    }
 
    return 0;
}
