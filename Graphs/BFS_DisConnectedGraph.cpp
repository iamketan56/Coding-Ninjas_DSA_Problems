#include <iostream>
#include <queue>
using namespace std;
void print(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int currentElement = q.front();
        q.pop();
        cout << currentElement << " ";
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
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print(edges, n, i, visited);
        }
    }
    delete[] visited;
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

    BFS(edges, ver);
}