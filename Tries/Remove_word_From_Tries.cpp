#include <iostream>
#include <cstring>
using namespace std;
class node
{
public:
    char data;
    node **childrens;
    bool isTerminal;
    node(char d)
    {
        d = data;
        childrens = new node *[26];
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = NULL;
        }
        isTerminal = false;
    }
};
class Tries
{
public:
    node *root;
    Tries()
    {
        root = new node('\0');
    }
    //add
    void addword(node *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a'; // a->1 ,b->2
        node *child;
        if (root->childrens[index] != NULL)
        {
            child = root->childrens[index];
        }
        else
        {
            node *newnode = new node(word[0]);
            root->childrens[index] = child;
        }

        addword(child, word.substr(1));
    }
    void addword(string word)
    {
        addword(root, word);
    }
    //search
    bool IsPresent(node *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        node *child;
        if (root->childrens[index] != NULL)
        {
            child = root->childrens[index];
        }
        else
        {
            return false;
        }
        return IsPresent(child, word.substr(1));
    }
    bool IsPresent(string word)
    {
        return IsPresent(root, word);
    }
    // remove
    void removeword(node *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal == false;
            return;
        }
        node *child;
        int index = word[0] - 'a';
        if (root->childrens[index] != NULL)
        {
            child = root->childrens[index];
        }
        else
        {
            return;
        }
        removeword(child, word.substr(1));

        if (child->isTerminal == false)
        {

            for (int i = 0; i < 26; i++)
            {
                if (child->childrens[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->childrens[index] = NULL;
        }
    }
    void removeword(string word)
    {
        removeword(root, word);
    }
};
int main()
{
    Tries T;
    T.addword("ketan");
    T.addword("sharma");
    T.addword("eat");
    cout << T.IsPresent("ketan") << endl;
    T.removeword("ketan");
    cout << T.IsPresent("ketan");
}