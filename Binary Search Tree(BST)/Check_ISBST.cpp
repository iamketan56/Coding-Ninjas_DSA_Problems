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
Node *insertinbst(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    if (data <= root->data)
    {
        root->left = insertinbst(root->left, data);
    }

    else
    {
        root->right = insertinbst(root->right, data);
    }

    return root;
}
Node *Build()
{
    int d;
    cin >> d;
    Node *root = NULL;
    while (d != -1)
    {
        root = insertinbst(root, d);
        cin >> d;
    }
    return root;
}
bool IsBST(Node *root, int minv = INT_MIN, int maxv = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (((root->data >= minv) && (root->data <= maxv)) && (IsBST(root->left, minv, root->data)) && (IsBST(root->right, root->data, maxv)))
    {
        return true;
    }
    return false;
}

void BFS(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *f = q.front();
        if (f == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
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
    }
    return;
}
int main()
{
    Node *root = Build();
    BFS(root);
    if (IsBST(root))
    {
        cout << "Perfectly BST" << endl;
    }
    else
    {
        cout << "Nooooottt a   BST";
    }
}