#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

void insertatbottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    else
    {
        int y = s.top();
        s.pop();
        insertatbottom(s, x);
        s.push(y);
    }
}
void reversestackusingrecursion(stack<int> &s1)
{
    if (s1.empty())
    {
        return;
    }
    else
    {
        int x = s1.top();
        s1.pop();
        reversestackusingrecursion(s1);
        insertatbottom(s1, x);
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
    reversestackusingrecursion(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}