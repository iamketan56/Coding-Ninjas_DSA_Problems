#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n;
    int a[100];
    int k;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> a[j];
    }
    cin >> k;
    deque<int> dq(k);
    //first k element work
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && a[i] > a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //remaining part
    for (; i < n; i++)
    {
        cout << a[dq.front()] << " ";

        //contraction
        while (!dq.empty() && (dq.front() <= i - k))
        {
            dq.pop_front();
        }
        while (!dq.empty() && (a[i] >= a[dq.back()]))
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << a[dq.front()];
}