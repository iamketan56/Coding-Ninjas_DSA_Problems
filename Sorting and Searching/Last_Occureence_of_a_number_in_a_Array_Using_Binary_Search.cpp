#include <iostream>
using namespace std;
int firstoccurece(int *a, int s, int e, int key)
{

    int mid = (s + e) / 2;
    int ans = -1;
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
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {1, 2, 2, 2, 3, 4, 4};
    int key;
    cout << "Enter the number to find the Last occurence location" << endl;
    cin >> key;
    cout << "Last Cccurence of " << key << " is " << firstoccurece(a, 0, 6, key);
}