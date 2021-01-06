#include <iostream>
using namespace std;
int partition(int *a, int si, int ei)
{
    int count = 0;
    int i, j;
    int x = a[si];
    for (int i = si + 1; i <= ei; i++)
    {
        if (x >= a[i])
        {
            count++;
        }
    }
    swap(a[si], a[si + count]);

    i = si;
    j = ei;

    while (i <= (si + count) && j >= (si + count))
    {

        if (a[i] <= x)
        {
            i++;
        }
        else if (a[j] > x)
        {
            j--;
        }
        else
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    return si + count;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int *a, int si, int ei)
{
    int c;
    if (si >= ei)
        return;
    c = partition(a, si, ei);
    quicksort(a, si, c - 1);
    quicksort(a, c + 1, ei);
}
int main()
{
    int a[] = {11, 7, 5, 3, 2, 53, 21, 4, 0};
    cout << "Without Sorting" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    quicksort(a, 0, 8);
    cout << "Sorted array\n";
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
}