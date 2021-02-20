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
Node *insertinbst(int *a, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = start + end;
    Node *root = new Node(a[mid]);
    root->left = insertinbst(a, start, mid - 1);
    root->right = insertinbst(a, mid + 1, end);

    return root;
}
Node *Build(int *a, int n)
{
    Node *root = insertinbst(a, 0, n);
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = Build(a, 8);
    inorder(root);
    cout << endl;
}