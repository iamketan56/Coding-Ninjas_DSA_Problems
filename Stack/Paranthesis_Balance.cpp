#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
    stack<char> s;
    char str[100];
    char x;
    cout << "Enter a equation" << endl;
    cin.get(str, 100);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] == '(' || str[i] == '[' || str[i] == '{'))
        {
            s.push(str[i]);
        }
        if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            switch (str[i])
            {
            case ')':
                x = s.top();
                if (x == '(')
                {
                    s.pop();
                }
                break;
            case ']':
                x = s.top();
                if (x == '[')
                {

                    s.pop();
                }
                break;
            case '}':
                x = s.top();
                if (x == '{')
                {

                    s.pop();
                }
                break;
            }
        }
    }
    if (s.empty())
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not Balanced";
    }
}