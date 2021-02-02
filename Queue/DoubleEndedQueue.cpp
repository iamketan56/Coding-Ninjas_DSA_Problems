#include <iostream>
#include <deque>
using namespace std;
void print(const std::deque<int> &dq)
{
    for (int num : dq)
    {
        cout << num << " ";
        cout << endl;
    }
}
int main()
{
    std::deque<int> dqu = {2, 3, 4};
    dqu.push_front(1);
    dqu.push_back(5);
    print(dqu);
    dqu.pop_front();
    dqu.pop_back();
    print(dqu);
}