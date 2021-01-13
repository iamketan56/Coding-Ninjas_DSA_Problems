#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int s = 0, e = 6, mid;
    int key = 8;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] > key)
        {
            e = mid - 1;
        }
        if (a[mid] < key)
        {
            s = mid + 1;
        }
        if (a[mid] == key)
        {
            cout << key << " is present at " << mid + 1 << " index";
            return 0;
        }
    }
    cout << key << " is not found";
}