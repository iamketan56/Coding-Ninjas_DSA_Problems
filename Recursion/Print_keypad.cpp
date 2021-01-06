#include <iostream>
#include <string>
using namespace std;

void printKeypadseq(int n, string o, string options[10])
{
    if (n == 0)
    {
        cout << o << endl;
        return;
    }
    int digit = n % 10;
    int i = 0;
    while (i < options[digit].length())
    {
        printKeypadseq(n / 10, options[digit][i] + o, options);
        i++;
    }
    return;
}
void printKeypad(int num)
{
    string options[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printKeypadHelper(num, "", options);
    return;
}

int main()
{
    int n;
    cin >> n;
    printKeypad(n);
}