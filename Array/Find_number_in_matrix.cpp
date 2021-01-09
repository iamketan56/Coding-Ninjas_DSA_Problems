#include <iostream>
using namespace std;

void readmat(int a[][10], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> a[i][j];
        }
    }
}

void printmat(int a[][10], int R, int C)
{

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool findnum(int a[][10], int R, int C, int number)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (a[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int a[10][10];
    int R, C, key;
    cin >> R >> C;
    readmat(a, R, C);
    printmat(a, R, C);
    cout << "Enter number to search" << endl;
    cout << findnum(a, R, C, key);

    return 0;
}