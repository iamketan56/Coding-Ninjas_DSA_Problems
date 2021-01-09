#include <iostream>
using namespace std;

void staircaseSearch(int a[][10], int R, int C, int key)
{
    int i = 0;
    int j = C - 1;
    while (j >= 0 && i < R)
    {
        if (a[i][j] == key)
        {
            cout << key << " Found at :" << i << " " << j;
            return;
        }
        else if (a[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "Element is not found";
}
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
int main()
{
    int a[10][10];
    int R, C, key;
    cin >> R >> C;
    readmat(a, R, C);
    printmat(a, R, C);
    cout << "enter value to search" << endl;
    cin >> key;
    staircaseSearch(a, R, C, key);
    return 0;
}
