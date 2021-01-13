#include <iostream>
using namespace std;
int binary_search(int *a, int s, int e, int key)
{
    int mid = (s + e) / 2;
    if (e >= s)
    {
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            s = mid + 1;
            return binary_search(a, s, e, key);
        }
        if (a[mid] > key)
        {
            e = mid - 1;
            return binary_search(a, s, e, key);
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 21, 31, 42, 50, 79, 90, 121, 123, 190};

    int res = binary_search(a, 0, 9, 190);
    if (res < 0)
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Found at " << res + 1 << " Postion";
    }
}