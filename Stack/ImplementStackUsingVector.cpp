#include <iostream>
#include <vector>
using namespace std;
class Stack
{
private:
    vector<int> s;

public:
    void push(int d)
    {
        s.push_back(d);
    }
    bool empty()
    {
        return s.size() == 0;
    }
    void pop()
    {
        if (!empty())
        {
            s.pop_back();
        }
    }
    int top()
    {
        return s[s.size() - 1];
    }
};
int main()
{
    Stack s1;
    for (int i = 1; i < 10; i++)
    {
        s1.push(i * i);
    }
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}