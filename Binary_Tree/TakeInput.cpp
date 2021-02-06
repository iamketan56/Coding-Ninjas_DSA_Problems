#include <iostream>
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
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
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
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printBinaryTree(root);
    delete root;
}