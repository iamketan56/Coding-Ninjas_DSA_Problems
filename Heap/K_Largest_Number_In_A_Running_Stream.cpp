#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
void print(priority_queue<int, vector<int>, greater<int>> pq)
{
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
int main()
{
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cs = 0;
    int k = 3; // 3 largest element

    while (scanf("%d", &num) != EOF)
    {
        if (num == -1)
        {
            print(pq);
        }
        else if (cs < k)
        {
            pq.push(num);
            cs++;
        }
        else
        {
            if (num > pq.top())
            {
                pq.pop();
                pq.push(num);
            }
        }
    }
}