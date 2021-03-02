#include <iostream>
#include <queue>
using namespace std;
bool HasPath(int **edges, int n, int sv, int ev)
{
    queue<int> q;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int currentElement = q.front();
        q.pop();
        if (currentElement == ev)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == currentElement)
            {
                continue;
            }
            if (edges[currentElement][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    return false;
}
int main()
{
    int ver, edge;
    cin >> ver >> edge;
    int **edges = new int *[ver];
    for (int i = 0; i < ver; i++)
    {
        edges[i] = new int[ver];
        for (int j = 0; j < ver; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = -0; i < edge; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int sv, ev;
    cout << "Enter the Starting vertex and ending vertex" << endl;
    cin >> sv >> ev;
    if (HasPath(edges, ver, sv, ev))
    {
        cout << "Yes Path is Found Between " << sv << " and  " << ev;
    }
    else
    {
        cout << "No Path Found Between " << sv << " and " << ev;
    }
}