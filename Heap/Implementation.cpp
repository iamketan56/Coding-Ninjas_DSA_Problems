#include <iostream>
#include <vector>
using namespace std;
class heap
{
    vector<int> v;
    bool minheap;

public:
    bool compare(int a, int b)
    {
        if (minheap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }
    heap(bool type = true)
    {
        minheap = type;
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;
        while (index > 1 && compare(v[index], v[parent]))
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
    bool isempty()
    {
        return v.size() == 1;
    }
    int top()
    {
        return v[1];
    }
};
int main()
{
    heap h; //min heap
            // heap(false) h; max heap

    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(4);
    cout << h.top();
}