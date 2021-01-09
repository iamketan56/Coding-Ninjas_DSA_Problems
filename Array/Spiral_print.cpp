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
void spiralprint(int a[][10], int R, int C)
{
    int startrow = 0;
    int startcol = 0;
    int endrow = R - 1;
    int endcol = C - 1;

    while (startrow <= endrow && startcol <= endcol)
    {

        //print startrow
        for (int j = startcol; j <= endcol; j++)
        {
            cout << a[startrow][j] << " ";
        }
        startrow++;
        //print end col

        for (int j = startrow; j <= endrow; j++)
        {
            cout << a[j][endcol] << " ";
        }
        endcol--;

        if (endrow > startrow)
        {
            for (int j = endcol; j >= startcol; j--)
            {
                cout << a[endrow][j] << " ";
            }
            endrow--;
        }

        if (startcol < endcol)
        {
            for (int j = endrow; j >= startrow; j--)
            {
                cout << a[j][startcol] << " ";
            }
            startcol++;
        }
    }
}
int main()
{
    int a[10][10];
    int R, C;
    cin >> R >> C;
    readmat(a, R, C);
    printmat(a, R, C);
    cout << "Spiral Print";

    spiralprint(a, R, C);
    return 0;
}
