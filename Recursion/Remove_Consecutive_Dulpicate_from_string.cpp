#include <iostream>
using namespace std;
int length(char s[])
{
    if (s[0] == '\0')
    {
        return 0;
    }
    return 1 + length(s + 1);
}

void remove_duplicate(char s[])
{
    if (length(s) < 1)
    {
        return;
    }

    remove_duplicate(s + 1);

    if (s[0] != s[1])
    {
        return;
    }
    else
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }

        s[i - 1] = s[i];
    }
}

int main()
{
    char s[100];
    cout << "Enter String to Remove consucative char" << endl;
    cin >> s;
    cout << s << endl;
    cout << "After Removing duplicate" << endl;
    remove_duplicate(s);
    cout << s;
}