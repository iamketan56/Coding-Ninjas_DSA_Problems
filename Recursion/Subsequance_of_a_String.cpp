#include <iostream>
#include <string.h>
using namespace std;
int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    string smallstr = input.substr(1);
    int smallpoutputsize = subs(smallstr, output);
    for (int i = 0; i <= smallpoutputsize; i++)
    {
        output[i + smallpoutputsize] = input[0] + output[i];
    }
    return 2 * smallpoutputsize;
}
int main()
{
    string s;
    cin >> s;
    string *output = new string[1000];
    int count = subs(s, output);
    for (int i = 0; i <= count; i++)
    {
        cout << output[i] << endl;
    }
}