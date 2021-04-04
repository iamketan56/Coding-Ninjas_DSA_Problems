#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int a[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int sixe = 8;
    int window_size = 3;
    queue<int> q;
    int start = 0;
    int end = 0;
    while (end < sixe)
    {
        if (a[end] < 0)
        {
            q.push(a[end]);
        }
        if (end - start + 1 < window_size)
        {
            end++;
        }
        else if (end - start + 1 == window_size)
        {
            if (q.empty())
            {
                cout << " 0 ";
            }
            else
            {
                cout << q.front() << " ";
                if (a[start] == q.front())
                {
                    q.pop();
                }
            }
            start++;
            end++;
        }
    }
}