#include <iostream>
using namespace std;

int first_index(int *a, int size, int x)
{
    int ans;
    if (size == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }
    ans = first_index(a + 1, size - 1, x);

    return (ans >= 0) ? ans + 1 : ans;
}

int main()
{

    int a[] = {1, 2, 1, 2, 3};
    cout << first_index(a, 5, 2);
}