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
int main()
{
    Node *root = buildTree();
    print(root);
    cout << endl;
    cout << "Height of This Tree will be : " << height(root);
}