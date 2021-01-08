#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, -2, 3, 8, 5, -3, 6, -1, 4};
    int maxsum = 0;
    int currsum = 0;
    int left = -1;
    int right = -1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i; j < 9; j++)
        {
            currsum = 0;
            for (int k = i; k <= j; k++)
            {
                currsum += a[k];
            }
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