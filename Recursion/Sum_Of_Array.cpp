#include <iostream>
using namespace std;
int submi = 0;
int sum(int a[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return a[0] + sum(a + 1, size - 1);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 3};
    cout << sum(a, 8);
}