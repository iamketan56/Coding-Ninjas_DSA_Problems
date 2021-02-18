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
Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
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
class Bpair
{
public:
    int height;
    bool balanced;
};
Bpair IsHeightBlancedTree(Node *root)
{
    Bpair ch;
    if (root == NULL)
    {
        ch.height = 0;
        ch.balanced = true;
        return ch;
    }
    Bpair leftside = IsHeightBlancedTree(root->left);
    Bpair rightside = IsHeightBlancedTree(root->right);
    ch.height = max(leftside.height, rightside.height) + 1;
    if (abs(leftside.height - rightside.height) <= 1 && leftside.balanced && rightside.balanced)
    {
        ch.balanced = true;
    }
    else
    {
        ch.balanced = false;
    }
    return ch;
}
int main()
{
    Node *root = buildTree();
    if (IsHeightBlancedTree(root).balanced)
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
}