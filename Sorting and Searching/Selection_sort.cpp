#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Selection_Sort(int *a, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        swap(&a[i], &a[minindex]);
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
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    Selection_Sort(a, n);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}