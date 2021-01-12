#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//First method
void wave_sort1(int *a, int size)
{
    int i = 0;
    for (i = 0; i < size; i += 2)
    {
        if (i > 0 && a[i] < a[i - 1])
        {
            swap(&a[i], &a[i - 1]);
        }

        if (i <= size - 2 && a[i] < a[i + 1])
        {
            swap(&a[i], &a[i + 1]);
        }
    }
}
//Second Method
void wave_sort2(int *a, int size)
{
    int i = 0;
    if (a[i] < a[i + 1])
    {
        swap(&a[i], &a[i + 1]);
    }
    for (i = 2; i < size; i += 2)
    {
        if (a[i] < a[i - 1])
        {
            swap(&a[i], &a[i - 1]);
        }

        if (a[i] < a[i + 1])
        {
            swap(&a[i], &a[i + 1]);
        }
    }
}
int main()
{
    int a[100];
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Before Apply wave sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    wave_sort(a, n);
    cout << "After Apply wave sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
