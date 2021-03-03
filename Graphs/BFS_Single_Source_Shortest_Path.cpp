#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> adjlist;

public:
    void addedges(T u, T v, bool bidirection = true)
    {
        adjlist[u].push_back(v);
        if (bidirection)
        {
            adjlist[v].push_back(u);
        }
    }

    void BFSPath(T src)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for (auto i : adjlist)
        {
            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();
            for (int neighbour : adjlist[node])
            {
                if (dist[neighbour] == INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        for (auto i : adjlist)
        {
            T node = i.first;
            cout << "Distance of " << node << " From " << src << " is " << dist[node] << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addedges(0, 1);
    g.addedges(1, 2);
    g.addedges(0, 4);
    g.addedges(2, 4);
    g.addedges(2, 3);
    g.addedges(3, 5);
    g.addedges(3, 4);
    g.addedges(1, 3);
    g.BFSPath(0);
}
