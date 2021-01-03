#include <iostream>
using namespace std;
int last_Index(int *a, int size, int x)
{
    int ans;
    if (size == 0)
    {
        return -1;
    }

    ans = last_Index(a + 1, size - 1, x);

    if (ans == -1)
    {
        if (a[0] == x)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return ans + 1;
}
int main()
{
    int a[] = {10, 2, 1, 2, 3};
    cout << last_Index(a, 5, 3);
}