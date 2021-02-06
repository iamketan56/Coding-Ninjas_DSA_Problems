#include <iostream>
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
void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " :";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;

    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
BinaryTreeNode<int> *helper(int *in, int *pre, int is, int ie, int ps, int pe)
{
    if (is > ie)
    {
        return NULL;
    }
    int rootdata = pre[ps];
    int rootindex = -1;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == rootdata)
        {
            rootindex = i;
            break;
        }
    }
    int lins = is;
    int line = rootindex - 1;
    int lpres = ps + 1;
    int lpree = line - lins + lpres;
    int rpres = lpres + 1;
    int rpree = pe;
    int rins = rootindex + 1;
    int rine = ie;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = helper(in, pre, lpres, lpree, lins, line);
    root->right = helper(in, pre, rpres, rpree, rins, rine);
}
BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return helper(in, pre, 0, size - 1, 0, size - 1);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printBinaryTree(root);
    delete root;
}