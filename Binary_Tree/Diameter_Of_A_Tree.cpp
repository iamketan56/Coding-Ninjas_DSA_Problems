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
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int Diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int o1 = height(root->left) + height(root->right);
    int o2 = Diameter(root->left);
    int o3 = Diameter(root->right);
    return max(o1, max(o2, o3));
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << Diameter(root);
    delete root;
}