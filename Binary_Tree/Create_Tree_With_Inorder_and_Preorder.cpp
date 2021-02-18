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
Node *buildTreeWithgivenorders(int *inorder, int *pre, int s, int e)
{
    static int i = 0;
    if (s > e)
    {
        return NULL;
    }
    Node *root = new Node(pre[i]);
    //search for index in inorder
    int index = -1;
    for (int j = s; j <= e; j++)
    {
        if (inorder[j] == pre[i])
        {
            index = j;
            break;
        }
    }
    i++;
    root->left = buildTreeWithgivenorders(inorder, pre, s, index - 1);
    root->right = buildTreeWithgivenorders(inorder, pre, index + 1, e);
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
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);
    Node *root = buildTreeWithgivenorders(in, pre, 0, n - 1);
    BFS(root);
}