#include <iostream>
using namespace std;
template <typename T>
class queue
{
    T *arr;
    int f, r, ms, cs;

public:
    queue(int ds = 4)
    {
        f = 0;
        ms = ds;
        cs = 0;
        r = ms - 1;
        arr = new T[ms];
    }
    bool isfull()
    {
        return ms == cs;
    }
    bool isempty()
    {
        return cs == 0;
    }
    void enque(T data)
    {
        if (!isfull())
        {
            r = (r + 1) % ms;
            arr[r] = data;
            cs++;
        }
    }
    void deque()
    {
        if (!isempty())
        {
            f = (f + 1) % ms;
            cs--;
        }
    }
    T getFront()
    {
        return arr[f];
    }
};
int main()
{
    queue<int> q(10);
    for (int i = 1; i <= 6; i++)

    {
        q.enque(i);
    }
    q.deque();
    q.enque(7);
    while (!q.isempty())
    {
        cout << q.getFront() << " ";
        q.deque();
    }
}