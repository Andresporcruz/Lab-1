#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    string get_title;
    string column1;
    string column2;
    string input;

    vector<string> dataStrings;
    vector<int> dataIntegers;

    cout << "Enter a title for the data:" << endl;
    getline(cin, get_title);
    cout << "You entered: " << get_title << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;

    vector<string> strings;
    vector<int> integers;

    while (true)
    {
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, input);

        if (input == "-1")
        {
            break;
        }

        int commaCount = count(input.begin(), input.end(), ',');

        if (commaCount != 1)
        {
            if (commaCount == 0)
            {
                cout << "Error: No comma in string." << endl;
                continue;
            }
            else
            {
                cout << "Error: Too many commas in input." << endl;
                continue;
            }
        }

        stringstream ss(input);
        string s;
        int i;

        getline(ss, s, ',');
        ss >> i;

        if (ss.fail())
        {
            cout << "Error: Comma not followed by an integer." << endl;
            continue;
        }
        else
        {
            ss.clear();
            ss.ignore(numeric_limits<streamsize>::max(), '\n');
            strings.push_back(s);
            integers.push_back(i);
            cout << "Data string: " << s << endl;
            cout << "Data integer: " << integers.back() << endl;
        }
    }
    cout << endl;
    cout << setw(33) << right << get_title << endl;
    cout << setw(20) << left << column1 << " | " << setw(20) << right << column2 << endl;

    cout << setfill('-') << setw(44) << "-" << setfill(' ') << endl;

    for (int i = 0; i < strings.size(); i++)
    {
        cout << setw(20) << left << strings[i] << " | " << setw(20) << right << integers[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < strings.size(); i++)
    {
        cout << setw(20) << right << strings[i] << " ";
        for (int j = 0; j < integers[i]; j++)
        {
            cout << "*";

        }
        cout << endl;
    }

    return 0;
}
