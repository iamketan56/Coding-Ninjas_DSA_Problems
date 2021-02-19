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
class LinkedList
{
public:
    Node *head;
    Node *tail;
};
LinkedList flatten(Node *root)
{
    LinkedList l;
    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    if (root->left != NULL && root->right == NULL)
    {
        LinkedList leftside = flatten(root->left);
        leftside.tail->right = root;

        l.head = leftside.head;
        l.tail = root;
        return l;
    }

    if (root->left == NULL && root->right != NULL)
    {
        LinkedList rightside = flatten(root->right);
        root->right = rightside.head;

        l.head = l.head;
        l.tail = rightside.tail;
        return l;
    }
    LinkedList leftside = flatten(root->left);
    LinkedList rightside = flatten(root->right);
    leftside.tail->right = root;
    root->right = rightside.head;

    l.head = leftside.head;
    l.tail = rightside.tail;
    return l;
}
int main()
{
    Node *root = Build();
    BFS(root);
    cout << endl;
    inorder(root);

    LinkedList l = flatten(root);
    cout << endl;
    Node *temp = l.head;
    while (temp != NULL)
    {
        cout << temp->data << " ---> ";
        temp = temp->right;
    }
}