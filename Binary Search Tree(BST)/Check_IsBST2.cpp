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
class ISBST
{
public:
    int minimum;
    int maximum;
    bool isBst;
};
ISBST checkforbst(Node *root)
{
    //O(n)
    if (root == NULL)
    {
        ISBST output;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        output.isBst = true;
        return output;
    }
    ISBST leftbst = checkforbst(root->left);
    ISBST rightbst = checkforbst(root->right);
    int minimum = min(root->data, min(leftbst.minimum, rightbst.minimum));
    int maximum = max(root->data, max(leftbst.maximum, rightbst.maximum));
    bool IsBstFinal = ((root->data > leftbst.minimum) && (root->data <= rightbst.maximum) && (leftbst.isBst) && (rightbst.isBst));
    ISBST FinalOutput;
    FinalOutput.minimum = minimum;
    FinalOutput.maximum = maximum;
    FinalOutput.isBst = IsBstFinal;
    return FinalOutput;
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
}