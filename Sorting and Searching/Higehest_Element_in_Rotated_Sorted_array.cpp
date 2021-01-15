#include <iostream>
using namespace std;
int main()
{
    int a[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    int s = 0;
    int e = 8;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if ((mid < e) && (a[mid] > a[mid + 1]))
        {
            cout << " Pivot Element is " << a[mid];
            break;
        }

        if ((mid > s) && (a[mid] < a[mid - 1]))
        {
            cout << " Pivot Element is " << a[mid - 1];
            break;
        }
        //now find the unsorted part
        if (a[s] >= a[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
}