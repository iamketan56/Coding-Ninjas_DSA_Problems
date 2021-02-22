#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> mymap;
    pair<string, int> p("abc", 1);
    //way to insert key value pair
    //1
    mymap.insert(p);
    //2
    mymap["def"] = 2;
    //find or access
    cout << mymap["abc"] << endl;
    cout << mymap.at("def") << endl;

    //check present
    if (mymap.count("ghi") > 0)
    {
        cout << "ghi is present" << endl;
    }

    //check size
    cout << "size: " << mymap.size();

    //erase
    mymap.erase("def");
}
