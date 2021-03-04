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

    bool iscycle(T src)
    {
        map<T, bool> visited;
        map<T, int> parent;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            for (T neb : adjlist[node])
            {
                if (visited[neb] == true && parent[node] != neb)
                {
                    return true;
                }
                else if (!visited[neb])
                {
                    visited[neb] = true;
                    parent[neb] = node;
                    q.push(neb);
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g;
    g.addedges(1, 2);
    g.addedges(1, 4);
    g.addedges(4, 3);
    g.addedges(2, 3);

    if (g.iscycle(1))
    {
        cout << "Contain Cycle" << endl;
    }
    else
    {
        cout << " Not contain any cycle";
    }
}