#include <iostream>
#include <cstring>
using namespace std;

char *mystrtoken(char str[], char del)
{
    static char *input = NULL;
    if (str != NULL)
    {
        input = str;
    }
    char *out = new char[strlen(input) + 1];

    if (input == NULL)
    {
        return NULL;
    }
    int i;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != del)
        {
            out[i] = input[i];
        }
        else
        {
            out[i] = '\0';
            input = input + i + 1;
            return out;
        }
    }
    //last postion
    out[i] = '\0';
    input = NULL;
    return out;
}
int main()
{
    char str[] = "Hi,this is ketan sharma,from pai";
    char *ptr;
    ptr = mystrtoken(str, ',');
    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = mystrtoken(NULL, ',');
    }
}