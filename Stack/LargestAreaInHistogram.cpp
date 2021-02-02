#include <iostream>
#include <stack>
using namespace std;
int largestarea(int arr[], int n)
{
    stack<int> s;
    int area;
    int largest = 0;
    int top;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i++);
        }
        else
        {
            top = s.top();
            s.pop();
            area = arr[top] * (s.empty() ? i : i - s.top() - 1);

            if (largest < area)
            {
                largest = area;
            }
        }
    }

    while (s.empty() == false)
    {
        top = s.top();
        s.pop();
        area = arr[top] * (s.empty() ? i : i - s.top() - 1);
        if (largest < area)
            largest = area;
    }
    return largest;
}

int main()
{
    int n = 7;
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    cout << largestarea(arr, 8);
}