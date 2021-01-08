#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int n;
    int maxsum = 0;
    int currsum = 0;

    cout << "Enter the number to store :" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        currsum = currsum + a[i];

        if (currsum < 0)
        {
            currsum = 0;
        }
        else
        {
            maxsum = max(currsum, maxsum);
        }
    }
    cout << endl;
    cout << "Maximum sum is : " << maxsum;
}