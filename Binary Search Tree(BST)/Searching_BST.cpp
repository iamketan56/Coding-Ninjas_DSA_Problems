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
// }
// void BFS(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *f = q.front();
//         cout << f->data << " ";
//         q.pop();

//         if (f->left)
//         {
//             q.push(f->left);
//         }
//         if (f->right)
//         {
//             q.push(f->right);
//         }
//     }
//     return;
// // }
// void inorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }
bool searchinbst(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data < root->data)
    {
        return searchinbst(root->left, data);
    }
    else
    {
        return searchinbst(root->right, data);
    }
}
int main()
{
    Node *root = Build();
    int key;
    cin >> key;
    if (searchinbst(root, key))
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Not Present" << endl;
    }
}