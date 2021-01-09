#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{

    return s1.length() < s2.length(); // length wise
    //return s1 > s2; // reserve
}
int main()
{
    string s("Hello World");
    cout << s;

    cout << endl;
    string s1 = "Another way";
    cout << s1;
    cout << endl;
    //Acess char of a string
    for (int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << "-";
    }

    cout << endl;
    string s3;
    getline(cin, s3);
    cout << s3;
    cout << endl;

    //Array of String
    string ar[] = {"h", "hello", "hey", "namsate"};
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << ar[i] << endl;
    // }

    sort(ar, ar + 4, compare);
    for (int i = 0; i < 4; i++)
    {
        cout << ar[i] << " ";
    }
}