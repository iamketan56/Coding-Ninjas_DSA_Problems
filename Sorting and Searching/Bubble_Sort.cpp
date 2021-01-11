#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *a, int size)
{
    int b = 0;
    for (int f = size - 1; f >= 0; f--)
    {
        for (int i = 0; i < f; i++)
        {
            int j = i + 1;
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
                b++;
            }
        }
        if (b == 0)
        {
            cout << "No need to sort" << endl;
            break;
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
    cout << "Before Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    bubble_sort(a, n);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
