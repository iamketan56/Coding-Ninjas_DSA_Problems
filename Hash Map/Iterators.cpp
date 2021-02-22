#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    //map example
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["def"] = 2;
    ourmap["ghi"] = 3;
    ourmap["jkl"] = 4;
    ourmap["mno"] = 5;
    ourmap["pqr"] = 6;
    ourmap["stu"] = 7;

    unordered_map<string, int>::iterator it;
    it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "Key :" << it->first << " Value :" << it->second << endl;
        it++;
    }
    cout << endl;
    //vector exapmle
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << " ";
        it1++;
    }
}