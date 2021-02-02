#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; ++i)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reversestack(stack<int> &s1)
{
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2, s1, n - i - 1);
    }
}
int main()
{
    stack<int> s;

    int n;
    cout << "Enter number of element" << endl;
    cin >> n;
    int data;
    cout << "Enter data" << endl;
    for (int i = 1; i <= n; i++)
    {

        cin >> data;
        s.push(data);
    }
    reversestack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}