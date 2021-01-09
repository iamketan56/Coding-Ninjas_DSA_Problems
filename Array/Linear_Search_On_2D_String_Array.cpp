#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[10][100];
    char key[100];
    int n;
    cout << "Enter number of entries" << endl;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        cin.getline(a[i], 100);
    }

    cout << "Enter the key to seacrh" << endl;

    cin.getline(key, 100);

    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(key, a[i]) == 0)
        {
            cout << key << " is found at index: " << i;
            break;
        }
    }
    if (i == n)
    {
        cout << "Not Found";
    }
}