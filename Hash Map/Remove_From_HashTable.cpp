#include <iostream>
#include <string>
using namespace std;
template <typename T>
class mapNode
{
public:
    string key;
    T value;
    mapNode *next;
    mapNode(string key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode()
    {
        delete next;
    }
};
template <typename T>
class mymap
{
    mapNode<T> **bukets;
    int counter;
    int numbucket;

public:
    mymap()
    {
        counter = 0;
        numbucket = 5;
        bukets = new mapNode<T> *[numbucket];
        for (int i = 0; i < numbucket; i++)
        {
            bukets[i] = NULL;
        }
    }
    ~mymap()
    {
        for (int i = 0; i < numbucket; i++)
        {
            delete bukets[i];
        }
        delete[] bukets;
    }

    int size()
    {
        return count;
    }

private:
    int getindex(string key)
    {
        int hashcode;
        int currrentcoff = 1;
        for (int i = key.length(); i >= 0; i--)
        {
            hashcode += key[i] * currrentcoff;
            hashcode = hashcode % numbucket;
            currrentcoff *= 37;
            currrentcoff = currrentcoff % numbucket;
        }
        return hashcode % numbucket;
    }
    T remove(string key)
    {
        int index = getindex(key);
        mapNode<T> *head = bukets[index];
        mapNode<T> *prev = NULL;
        while ((head != NULL))
        {
            if (head->key = key)
            {
                if (prev == NULL)
                {
                    bukets[index] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }

                V value = head->value;

                head->next = NULL;
                delete head;
                counter--;
                return value;
            }
            prev = head;
            head = head->next;
        }
    }
    return 0;
};

int main()
{
}