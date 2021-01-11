#include <iostream>
using namespace std;

void Insertion_Sort(int *a, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int num = a[i];
        while (j >= 0 && a[j] > num)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = num;
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
    Insertion_Sort(a, n);
    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}