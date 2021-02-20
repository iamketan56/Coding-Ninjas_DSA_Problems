#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> *takeInput()
{
    cout << "Enter Data" << endl;
    int rootdata;
    cin >> rootdata;
    if (rootdata == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int> *> pending;
    pending.push(root);
    while (pending.size() != 0)
    {
        BinaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter Left child of " << front->data << endl;
        int leftchild;
        cin >> leftchild;
        if (leftchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftchild);
            front->left = child;
            pending.push(child);
        }

        cout << "Enter right child of " << front->data << endl;
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightchild);
            front->right = child;
            pending.push(child);
        }
    }
    return root;
}
vector<int> *getpath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> *leftout = getpath(root->left, data);
    if (leftout != NULL)
    {
        leftout->push_back(root->data);
        return leftout;
    }
    vector<int> *rightout = getpath(root->right, data);
    if (rightout != NULL)
    {
        rightout->push_back(root->data);
        return rightout;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    int d;
    BinaryTreeNode<int> *root = takeInput();
    cin >> d;
    vector<int> *v = getpath(root, d);

    for (int i = 0; i < v->size(); i++)
    {
        cout << v->at(i) << " ";
    }
}