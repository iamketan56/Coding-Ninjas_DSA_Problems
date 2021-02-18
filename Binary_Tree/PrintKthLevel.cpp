#include <iostream>
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
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsub = height(root->left);
    int rightsub = height(root->right);
    return (max(leftsub, rightsub) + 1);
}
void printKthLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}
void printalllevel(Node *root)
{
    int H = height(root);
    for (int i = 1; i <= H; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
}
int main()
{
    Node *root = buildTree();
    printalllevel(root);
}