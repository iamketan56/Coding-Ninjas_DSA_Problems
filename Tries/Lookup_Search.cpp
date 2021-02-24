#include <iostream>
#include <unordered_map>
using namespace std;
#define hashmap unordered_map<char, node *>

class node
{
public:
    char data;
    hashmap h;
    bool isTerminal;
    node(char d)
    {
        d = data;
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
    void addword(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
            {
                temp = temp->h[ch];
            }
        }
        temp->isTerminal = true;
    }
    bool IsPresent(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch))
            {
                temp = temp->h[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isTerminal;
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
    char searchkey[100];
    cin.getline(searchkey, 100);

    if (T.IsPresent(searchkey))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}