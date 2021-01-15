#include <iostream>
using namespace std;
int main()
{
    int a[] = {6, 7, 2, 3, 4, 5}; // sorted and rotated by 2 factor
    int key;
    cout << "Enter key to search" << endl;
    cin >> key;
    int s = 0;
    int e = 6;
    int mid;
    while (s <= e)
    {
        mid = (s + e) / 2;

        if (a[mid] <= key && key <= a[e])
        {
            s = mid + 1;
        }

        if (!(a[mid] <= key && key <= a[e]))
        {
            e = mid - 1;
        }
        if (a[mid] == key)
        {
            cout << "Element " << key << " is at " << mid;
            return 0;
        }
    }
    cout << key << " is not found";
}