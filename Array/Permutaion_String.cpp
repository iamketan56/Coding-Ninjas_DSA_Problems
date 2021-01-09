#include <iostream>
#include <cstring>
using namespace std;
bool ispermutaion(char *s1, char *s2)
{
    int l1, l2;
    int freq[26] = {0}; // a-z
    l1 = strlen(s1);
    l2 = strlen(s2);

    if (l1 != l2)
    {
        return false;
    }
    //for string 1
    for (int i = 0; i < l1; i++)
    {
        freq[s1[i] - 'a']++;
    }

    //for string 2
    for (int i = 0; i < l1; i++)
    {
        freq[s2[i] - 'a']--;
    }
    for (int i = 0; i < l1; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char s1[100] = {"ababa"};
    char s2[100] = {"abbba"};
    cout << ispermutaion(s1, s2);
}