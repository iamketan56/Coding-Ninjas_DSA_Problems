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
Node *deletioninbst(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = deletioninbst(root->left, data);
        return root;
    }
    else if (data == root->data)
    {
        // now three case
        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Node having one child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //Node having 2 child
        //find the inorder scucessor
        Node *change = root->right;
        while (change->left != NULL)
        {
            change = change->left;
        }
        root->data = change->data;
        root->right = deletioninbst(root->right, change->data);
        return root;
    }
    else
    {
        root->right = deletioninbst(root->right, data);
        return root;
    }
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
    inorder(root);
    cout << endl;
    BFS(root);
    cout << endl;
    int key;
    cin >> key;
    cout << endl;
    root = deletioninbst(root, key);
    inorder(root);
    cout << endl;
    BFS(root);
}