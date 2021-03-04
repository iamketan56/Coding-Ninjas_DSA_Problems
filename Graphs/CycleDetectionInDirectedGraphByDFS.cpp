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
    bool iscycleHelper(T node, map<T, bool> &visited, map<T, bool> &instack)
    {
        visited[node] = true;
        instack[node] = true;

        for (auto neb : adjlist[node])
        {
            if (!visited[neb] && iscycleHelper(neb, visited, instack) || instack[neb] == true)
            {
                return true;
            }
        }
        instack[node] = false;
        return false;
    }
    bool iscycle()
    {
        map<T, bool> visited;
        map<T, bool> instack;

        for (auto i : adjlist)
        {
            T node = i.first;
            if (!visited[node])
            {
                bool cycle = iscycleHelper(node, visited, instack);
                if (cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g;
    g.addedges(0, 2, false);
    g.addedges(0, 1, false);
    g.addedges(2, 3, false);
    g.addedges(2, 4, false);
    // g.addedges(3, 0, false);
    g.addedges(4, 5, false);
    g.addedges(1, 5, false);

    if (g.iscycle())
    {
        cout << "Contain Cycle" << endl;
    }
    else
    {
        cout << " Not contain any cycle";
    }
}