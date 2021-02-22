#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> removedup(int *a, int size)
{
    vector<int> output;
    unordered_map<int, bool> check;
    for (int i = 0; i < size; i++)
    {
        if (check.count(a[i]) > 0)
        {
            continue;
        }
        check[a[i]] = true;
        output.push_back(a[i]);
    }
    return output;
}
int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 4, 5, 6, 1, 2, 3};
    vector<int> result = removedup(a, 12);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
