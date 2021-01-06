#include <iostream>
using namespace std;
int All_Index(int *a, int size, int x, int o[])
{
    int ans;
    if (size == 0)
    {
        return 0;
    }

    ans = All_Index(a + 1, size - 1, x, o);
    if (a[0] == x)
    {
        for (int i = ans - 1; i >= 0; i--)
        {
            o[i + 1] = o[i] + 1;
        }

        // Put the start index in front
        // of the array
        o[0] = 0;
        ans++;
    }
    else
    {

        // If the element at index 0 is not equal
        // to x then add 1 to the array values
        for (int i = ans - 1; i >= 0; i--)
        {
            o[i] = o[i] + 1;
        }
    }
    return ans;
}
int main()
{
    int a[] = {10, 2, 1, 2, 4, 2, 3};
    int out[6] = {0};
    cout << All_Index(a, 7, 2, out);
}