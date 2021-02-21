#include <iostream>
#include <vector>
using namespace std;
class heap
{
    vector<int> v;
    bool minheap;

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
    void heapify(int i)
    {
        int leftchild = 2 * i;
        int rightchild = 2 * i + 1;
        //assume current elment is the min element
        int minindex = i;
        if (leftchild < v.size() && compare(v[leftchild], v[i]))
        {
            minindex = leftchild;
        }
        if (rightchild < v.size() && compare(v[rightchild], v[minindex]))
        {
            minindex = rightchild;
        }
        if (minindex != i)
        {
            swap(v[i], v[minindex]);
            heapify(minindex);
        }
    }

public:
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
    void pop()
    {
        int lastindex = v.size() - 1;
        swap(v[1], v[lastindex]);
        v.pop_back();
        heapify(1);
    }
};
int main()
{
    heap h(false); //min heap
                   // heap(false) h; max heap

    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(4);
    while (!h.isempty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}