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
int sum = 0;
int printsum(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    sum += root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        printsum(root->children[i]);
    }
    return sum;
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

    cout << "Sum of all nodes is :" << printsum(root);
}