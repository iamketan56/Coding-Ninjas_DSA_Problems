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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
    {
        return false;
    }
    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size()))
    {
        return false;
    }

    int i = 0;

    while (i < root1->children.size())
    {
        TreeNode<int> *child1 = root1->children[i];
        TreeNode<int> *child2 = root2->children[i];
        if (isIdentical(child1, child2))
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
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
    TreeNode<int> *root1 = takeinputlevelwise();

    cout << isIdentical(root, root1);
}