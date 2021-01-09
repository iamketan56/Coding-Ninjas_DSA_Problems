#include <iostream>
using namespace std;
int main()
{
    char a[100];
    // it will  show the garbage value in output char b[] = {'a', 'b', 'c', 'd'};
    char b[] = {'a', 'b', 'c', 'd', '\0'}; // now it will print abcd
    cout << b;
    cout << endl;
    //  cin >> a;
    // it wil show only one word
    cin.getline(a, 100); // it will print whole sentence
    cout << a;

    //if we want to terminate the sentenence will a spacific char
    char c[100];
    cin.getline(c, 100, '.');
    cout << c; // it will print upto a '.'
}