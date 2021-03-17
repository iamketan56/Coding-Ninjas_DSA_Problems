#include <iostream>
#include <cstring>
using namespace std;
void filterChar(char *a, int n)
{
    int i = 0;
    while (n > 0)
    {
        (n & 1) ? cout << a[i] : cout << "";
        i++;
        n = n >> 1;
    }
    cout << endl;
}
void generateSubset(char *a)
{
    int l = strlen(a);
    int r = (1 << l);
    for (int i = 0; i <= r; i++)
    {
        filterChar(a, i);
    }
}
int main()
{
    char a[100];
    cin >> a;
    generateSubset(a);
}