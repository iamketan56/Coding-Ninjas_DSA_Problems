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
};
int main()
{
    char word[10][100] = {"apple", "Cricket", "Running", "Coding", "eating", "slepping"};
    Tries T;
    for (int i = 0; i < 6; i++)
    {
        T.addword(word[i]);
    }
}