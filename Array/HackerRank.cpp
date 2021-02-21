#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int arraynum;
    int arrayelement;
    cin >> arraynum >> arrayelement;

    vector<int> res;
    while (arraynum--)
    {
        vector<int> v;
        int element;
        for (int i = 0; i < arrayelement; i++)
        {
            cin >> element;
            v.push_back(element);
        }
        if (res.size() == 0)
        {
            res.insert(res.begin(), v.begin(), v.end());
        }
        else
        {
            res.insert(res.end(), v.begin(), v.end());
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        pq.push(res[i]);
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
