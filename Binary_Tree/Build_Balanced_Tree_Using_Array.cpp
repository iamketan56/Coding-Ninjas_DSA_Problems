#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *buildTreeWithArray(int *a, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    Node *root = new Node(a[mid]);
    root->left = buildTreeWithArray(a, s, mid - 1);
    root->right = buildTreeWithArray(a, mid + 1, e);
    return root;
}

void BFS(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        cout << f->data << " ";
        q.pop();

        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
    return;
}
int main()
{
    int a[] = {2, 4, 6, 8, 10, 11, 14};
    int n = 7;
    Node *root = buildTreeWithArray(a, 0, n - 1);
    BFS(root);
}