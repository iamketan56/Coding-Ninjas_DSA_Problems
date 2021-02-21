#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> v1 = {0, 2, 4, 6};
    vector<int> v2 = {1, 5, 7, 9};
    vector<int> v3 = {3, 8, 10, 12};

    vector<int> v;
    v.insert(v.begin(), v1.begin(), v1.end());
    v.insert(v.end(), v2.begin(), v2.end());
    v.insert(v.end(), v3.begin(), v3.end());
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}