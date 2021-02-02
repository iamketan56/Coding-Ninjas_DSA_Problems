#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    char a[] = "abcdeaghb";
    int n = strlen(a);
    int cl = 1;
    int ml = 1;

    int visited[256];
    for (int i = 0; i < 256; i++)
    {
        visited[i] = -1;
    }

    visited[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        int lastoccur = visited[a[i]];
        //not occuring before
        if ((lastoccur == -1) || (i - cl > lastoccur))
        {
            cl++;
            ml = max(cl, ml);
        }
        //expense + contraction
        else
        {
            if (cl > ml)
            {
                ml = cl;
            }
            cl = i - lastoccur;
        }
        visited[a[i]] = i;
    }

    if (cl > ml)
    {
        ml = cl;
    }
    cout << ml << " ";
}