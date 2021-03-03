#include <iostream>
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
    void printlist()
    {
        for (auto i : adjlist)
        {
            cout << i.first << "->";
            for (auto entry : i.second)
            {
                cout << entry << ",";
            }
            cout << endl;
        }
    }
};
int main()
{
    Graph<string> g;
    g.addedges("A", "B", false);
    g.addedges("A", "C", false);
    g.addedges("B", "D", false);
    g.addedges("A", "E", false);
    g.addedges("E", "B", false);
    g.addedges("D", "C");
    g.printlist();

    Graph<int> g1;
    g1.addedges(1, 2);
    g1.addedges(1, 3);
    g1.addedges(2, 4);
    g1.addedges(2, 7);
    g1.addedges(3, 5, false);
    g1.printlist();
}
