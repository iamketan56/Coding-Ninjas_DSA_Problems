#include <iostream>
#include <string.h>
using namespace std;
int subs(string input, string *output)
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

void keypadsub(string input1, string input2, string *output)
{
    int count = subs(input1, output);
    string output1[count];
    for (int i = 0; i < count; i++)
    {
        output1[i] = output[i];
    }
    for (int i = 0; i < count; i++)
    {
        output[i] = input2[0] + output1[i];
        cout << output[i] << endl;
    }
    for (int i = 0; i < count; i++)
    {
        output[i + count] = input2[1] + output1[i];
        cout << output[i + count] << endl;
    }
    for (int i = 0; i < count; i++)
    {
        output[i + 2 * count] = input2[2] + output1[i];
        cout << output[i + 2 * count] << endl;
    }
}
int main()
{
    string s1, s2;
    cout << "Enter first key" << endl;
    cin >> s1;
    cout << "Enter first key" << endl;
    cin >> s2;
    string *output = new string[1000];
    keypadsub(s1, s2, output);
}