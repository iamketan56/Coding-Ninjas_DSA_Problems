#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addedges(int u, int v, bool bidirection = true)
    {
        l[u].push_back(v);
        if (bidirection)
        {
            l[v].push_back(u);
        }
    }
    void printlist()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int ver : l[i])
            {
                cout << ver << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph g(5);
    g.addedges(0, 1);
    g.addedges(0, 4);
    g.addedges(4, 3);
    g.addedges(1, 4);
    g.addedges(1, 2);
    g.addedges(2, 3);
    g.addedges(1, 3);
    g.printlist();
}