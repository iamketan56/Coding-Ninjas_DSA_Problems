#include <iostream>
using namespace std;
int main()
{
    int n;
    int building[100];
    int left[100];
    int right[100];
    cout << "Enter the number of building" << endl;
    cin >> n;
    cout << "Enter the building" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> building[i];
    }

    left[0] = building[0];
    for (int i = 1; i < n; i++)
    {

        if (building[i] > left[i - 1])
        {
            left[i] = building[i];
        }
        else
        {
            left[i] = left[i - 1];
        }
    }
    right[n - 1] = building[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {

        if (building[i] > right[i + 1])
        {
            right[i] = building[i];
        }
        else
        {
            right[i] = right[i + 1];
        }
    }
    int maxsave = 0;
    for (int i = 0; i < n; i++)
    {
        maxsave += (min(left[i], right[i]) - building[i]);
    }
    cout << "Maximum Saving:" << maxsave;
}