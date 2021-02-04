

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
void actualchange(TreeNode<int> *root, int depth)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        actualchange(root->children[i], depth + 1);
    }
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    int depth = 0;
    actualchange(root, depth);
}
TreeNode<int> *takeinputlevelwise()
{
    int rootdata;
    cout << "Enter Data" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "Enter number of child of " << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild; i++)
        {
            int childata;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childata;
            TreeNode<int> *child = new TreeNode<int>(childata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}
int main()
{

    TreeNode<int> *root = takeinputlevelwise();
    printTree(root);
    replaceWithDepthValue(root);
    cout << "After replacing node value with depth  value" << endl;
    printTree(root);
}