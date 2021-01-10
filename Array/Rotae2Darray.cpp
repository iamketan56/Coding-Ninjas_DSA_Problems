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
void Transpose(int a[][10], int R, int C)
{
    int temp;
    for (int i = 0; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            if (i != j)
            {
                temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int a[][10], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        int start = 0;
        int end = C - 1;
        while (start < end)
        {
            swap(&a[i][start], &a[i][end]);
            start++;
            end--;
        }
    }
}
int main()
{
    int a[10][10];
    int R, C;
    cout << "Enter row" << endl;
    cin >> R;

    cout << "Enter col" << endl;
    cin >> C;

    readmat(a, R, C);
    cout << "Before Rotation" << endl;
    printmat(a, R, C);
    Transpose(a, R, C);
    reverse(a, R, C);
    cout << "After Rotation (90 deg clockwise)" << endl;
    printmat(a, R, C);
}