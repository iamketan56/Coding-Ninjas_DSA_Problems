#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq; // by dafault max heap
    int a[10] = {25, 6, 17, 8, 29, 4};
    for (int i = 0; i < 6; i++)
    {
        pq.push(a[i]);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}