#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

void transfer(stack<int> s1, stack<int> s2)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
}
int main()
{
    stack<int> s;
    stack<int> s2;
    stack<int> s3;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    transfer(s, s2);
    transfer(s2, s3);
    transfer(s3, s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}