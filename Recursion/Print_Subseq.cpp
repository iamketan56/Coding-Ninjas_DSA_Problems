#include <iostream>
#include <string.h>
using namespace std;
void printsub(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    printsub(input.substr(1), output); // not include any character
    printsub(input.substr(1), output + input[0]);
}
int main()
{
    string s, o;
    cin >> s;
    o = "";
    printsub(s, o);
}
