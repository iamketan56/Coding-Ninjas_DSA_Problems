#include <iostream>
#include <map>
#include <set>
#include <list>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> m;

public:
    void addedges(T u, T v, int dis, bool bidirection = true)
    {
        m[u].push_back(make_pair(v, dis));
        if (bidirection)
        {
            m[v].push_back(make_pair(u, dis));
        }
    }
    void Dijkstra(T src)
    {
        map<T, int> distance;
        //all dis is infinty
        for (auto j : m)
        {
            distance[j.first] = INT_MAX;
        }
        set<pair<int, T>> s;
        distance[src] = 0;
        s.insert(make_pair(0, src));
        while (!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());

            for (auto childpair : m[node])
            {
                if (nodedist + childpair.second < distance[childpair.first])
                {
                    T dest = childpair.first;
                    auto f = s.find(make_pair(distance[dest], dest));

                    if (f != s.end())
                    {
                        s.erase(f);
                    }
                    distance[dest] = nodedist + childpair.second;
                    s.insert(make_pair(distance[dest], dest));
                }
            }
        }
        for (auto d : distance)
        {
            cout << d.first << " is at " << d.second << endl;
        }
    }
};
int main()
{
    // Graph<string> g;
    // g.addedges("Amritsir", "Delhi", 1);
    // g.addedges("Amritsir", "Jaipur", 4);
    // g.addedges("Jaipur", "Delhi", 2);
    // g.addedges("Jaipur", "Mumbai", 8);
    // g.addedges("Bhopal", "Agra", 2);
    // g.addedges("Mumbai", "Bhopal", 3);
    // g.addedges("Agra", "Delhi", 1);
    // g.printlist();
    Graph<int> g;
    g.addedges(1, 2, 1);
    g.addedges(1, 3, 4);
    g.addedges(2, 3, 1);
    g.addedges(3, 4, 2);
    g.addedges(1, 4, 7);

    g.Dijkstra(1);
}
