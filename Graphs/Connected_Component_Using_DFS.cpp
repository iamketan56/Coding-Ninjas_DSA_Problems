#include <iostream>
#include <queue>
#include <map>
#include <list>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> adjlist;
    void dfsHelper(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        for (T neb : adjlist[node])
        {
            if (!visited[neb])
            {
                dfsHelper(neb, visited);
            }
        }
    }

public:
    void addedges(T u, T v, bool bidirection = true)
    {
        adjlist[u].push_back(v);
        if (bidirection)
        {
            adjlist[v].push_back(u);
        }
    }
    void dfs(T src)
    {
        map<T, bool> visited;
        int compo = 1;

        dfsHelper(src, visited);
        for (auto i : adjlist)
        {
            T city = i.first;
            if (!visited[city])
            {
                dfsHelper(city, visited);
                compo++;
            }
        }
        cout << "This garph has " << compo << " Components";
    }
};
int main()
{
    Graph<string> g;
    g.addedges("AM", "JA");
    g.addedges("AM", "DE");
    g.addedges("JA", "DE");
    g.addedges("MU", "JA");
    g.addedges("MU", "BH");
    g.addedges("DE", "BH");
    g.addedges("MU", "BH");
    g.addedges("AG", "DE");
    g.addedges("AN", "NI");
    g.dfs("AM");
}