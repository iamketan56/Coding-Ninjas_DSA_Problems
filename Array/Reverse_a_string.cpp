#include <iostream>
#include <cstring>
using namespace std;
void reverse(char *a)
{
    int i = strlen(a);
    int j = 0;

    while (j < i)
    {
        int temp = a[j];
        a[j] = a[i - 1];
        a[i - 1] = temp;
        i--;
        j++;
    }
}
int main()
{
    char a[100] = "DWIVEDI";
    cout << "Before:" << a << endl;
    reverse(a);
    cout << "After: " << a;
}