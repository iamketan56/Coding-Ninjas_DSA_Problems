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
    void dfsHElper(T node, map<T, bool> &visited, list<T> &output)
    {
        visited[node] = true;
        for (T neb : adjlist[node])
        {
            if (!visited[neb])
            {
                dfsHElper(neb, visited, output);
            }
        }
        output.push_front(node);
    }
    void dfsTopologicalSort()
    {
        map<T, bool> visited;
        list<T> output;
        for (auto i : adjlist)
        {
            T node = i.first;

            if (!visited[node])
            {
                dfsHElper(node, visited, output);
            }
        }

        for (T ele : output)
        {
            cout << ele << "-> ";
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
    g.dfsTopologicalSort();
}