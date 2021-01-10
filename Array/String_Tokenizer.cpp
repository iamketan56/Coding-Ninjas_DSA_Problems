#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "Hi this , is ketan , sharma";
    char *ptr;
    ptr = strtok(str, ",");
    while (ptr != NULL)
    {
        cout << ptr << endl;

        ptr = strtok(NULL, ",");
    }
}