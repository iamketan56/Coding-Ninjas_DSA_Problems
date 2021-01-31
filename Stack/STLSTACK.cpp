#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    stack<string> s1;
    s1.push("My");
    s1.push("Name");
    s1.push("Is");
    s1.push("Ketan");
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }
}