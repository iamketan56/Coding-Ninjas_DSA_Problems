#include <iostream>
#include <vector>
using namespace std;
template <typename T, typename U>
class Stack
{
private:
    vector<T> s;
    vector<U> s2;

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
    T top()
    {
        return s[s.size() - 1];
    }
};
int main()
{
    cout << "Character" << endl;
    Stack<char, int> s1;
    for (int i = 65; i < 71; i++)
    {
        s1.push(i);
    }

    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}