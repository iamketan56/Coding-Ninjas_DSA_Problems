#include <iostream>
using namespace std;
int main()
{
    int a[100];
    int n;
    int maxsum = 0;
    int currsum = 0;
    int left = -1;
    int right = -1;
    int cs[100] = {0};
    cout << "Enter the number to store :" << endl;
    cin >> n;

    cin >> a[0];
    cs[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        cs[i] = cs[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currsum = 0;
            currsum = cs[j] - cs[i - 1];
            cout << cs[i - 1] << " cs " << currsum << "sum" << endl;

            if (maxsum < currsum)
            {
                maxsum = currsum;
                left = i;
                right = j;
            }
        }
    }
    cout << "Sub array with maximun sum:" << endl;
    for (int i = left; i <= right; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Maximum sum is : " << maxsum;
}