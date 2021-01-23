#include <iostream>
using namespace std;
class DynamicArray
{
    int *data;
    int capacity;
    int element;
    int nextindex;

public:
    DynamicArray()
    {
        data = new int[5];
        capacity = 5;
        nextindex = 0;
    }
    void add(int element)
    {
        if (nextindex == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            capacity = 2 * capacity;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int get(int index)
    {
        if (index < nextindex)
        {
            return data[index];
        }
        else
        {
            return -1;
        }
    }
    void addelement(int i, int element)
    {
        if (i < nextindex)
        {
            data[i] = element;
        }
        else if (i == nextindex)
        {
            add(element);
        }
        else
        {
            return;
        }
    }
    void print()
    {
        for (int i = 0; i < nextindex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    DynamicArray(DynamicArray const &d2)
    {
        this->data = new int[d2.capacity];
        for (int i = 0; i < d2.nextindex; i++)
        {
            this->data[i] = d2.data[i];
        }
        this->nextindex = d2.nextindex;
        this->capacity = d2.capacity;
    }
    void operator=(DynamicArray const &d)
    {
        this->data = new int[d.capacity];
        for (int i = 0; i < d.nextindex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextindex = d.nextindex;
        this->capacity = d.capacity;
    }
};
int main()
{
    DynamicArray d1;
    d1.add(1);
    d1.add(5);
    d1.add(6);
    d1.add(8);
    d1.add(11);
    d1.add(15);
    d1.print();
    cout << d1.get(5);

    DynamicArray d2(d1);
    d2.addelement(3, 14);

    d1.print();
    d2.print();
    DynamicArray d3;
    d3 = d1;
    d3.print();
}