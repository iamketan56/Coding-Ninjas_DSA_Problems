#include <iostream>
using namespace std;
void removechar(char s[])
{
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] != 'b')
    {
        removechar(s + 1);
    }

    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }

        s[i - 1] = s[i];

        removechar(s);
    }
}
int main()
{
    char str[100];

    cin >> str;
    removechar(str);
    cout << str;
}