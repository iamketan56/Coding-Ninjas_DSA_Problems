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
        return counter;
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
    void rehash()
    {
        mapNode<T> **temp = bukets;
        bukets = new mapNode<T> *[2 * numbucket];
        for (int i = 0; i < 2 * numbucket; i++)
        {
            bukets[i] = NULL;
        }
        int oldbucketcount = numbucket;
        numbucket *= 2;
        counter = 0;
        for (int i = 0; i < oldbucketcount; i++)
        {
            mapNode<T> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                T value = head->value;
                insertvalue(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldbucketcount; i++)
        {
            mapNode<T> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insertvalue(string key, T value)
    {
        int index = getindex(key);
        mapNode<T> *head = bukets[index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = bukets[index];
        mapNode<T> *newNode = new mapNode<T>(key, value);
        newNode->next = head;
        bukets[index] = newNode;
        counter++;
        double loadFactor = 1.0 * counter / numbucket;
        if (loadFactor > 0.7)
        {
            rehash();
        }
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

                T value = head->value;

                head->next = NULL;
                delete head;
                counter--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

    T getvalue(string key)
    {
        int index = getindex(key);
        mapNode<T> *head = bukets[index];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    int getloadFactor()
    {
        return 1.0 * counter / numbucket;
    }
};

int main()
{
    mymap<int> m;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        m.insertvalue(key, value);
    }
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;

        cout << m.getvalue(key) << endl;
    }
    cout << m.size();
}