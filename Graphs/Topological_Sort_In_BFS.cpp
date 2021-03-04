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

    void bfsTopologicalSort()
    {
        queue<T> q;
        map<T, bool> visited;
        map<T, int> indegree;

        for (auto i : adjlist)
        {
            T node = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        for (auto i : adjlist)
        {
            T u = i.first;
            for (T v : adjlist[u])
            {
                indegree[v]++;
            }
        }
        for (auto i : adjlist)
        {
            T node = i.first;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " --> ";
            for (T neb : adjlist[node])
            {
                indegree[neb]--;
                if (indegree[neb] == 0)
                {
                    q.push(neb);
                }
            }
        }
    }
};
int main()
{
    Graph<string> g;
    g.addedges("En", "PL", false);
    g.addedges("M", "PL", false);
    g.addedges("PL", "HT", false);
    g.addedges("PL", "PY", false);
    g.addedges("PL", "JA", false);
    g.addedges("PL", "JS", false);
    g.addedges("HT", "CS", false);
    g.addedges("CS", "JS", false);
    g.addedges("JS", "WD", false);
    g.addedges("JA", "WD", false);
    g.addedges("PY", "WD", false);
    g.bfsTopologicalSort();
}