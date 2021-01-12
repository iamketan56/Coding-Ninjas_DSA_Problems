#include <iostream>
#include <algorithm>
using namespace std;
bool compare(pair<string, int> p1, pair<string, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}
int main()
{
    int min_sal, n;
    cout << "Enter the min salary" << endl;
    cin >> min_sal;
    cout << "Enter the number of Employee" << endl;
    cin >> n;

    pair<string, int> emp[10005];
    string name;
    int salary;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        cin >> salary;
        emp[i].first = name;
        emp[i].second = salary;
    }
    sort(emp, emp + n, compare);

    for (int i = 0; i < n; i++)
    {
        if (emp[i].second > min_sal)
        {
            cout << emp[i].first << " " << emp[i].second;
            cout << endl;
        }
    }
}