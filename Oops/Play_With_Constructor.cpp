#include <iostream>
#include <algorithm>
using namespace std;
class Fraction
{
private:
    int num;
    int deno;

public:
    Fraction(int numrator, int denominature)
    {
        this->num = numrator;
        this->deno = denominature;
    }
    void simple()
    {
        int gcd = 1;
        int j = min(this->num, this->deno);
        for (int i = 1; i <= j; i++)
        {
            if ((this->num % i == 0) && (this->deno % i == 0))
            {
                gcd = i;
            }
        }
        this->num = this->num / gcd;
        this->deno = this->deno / gcd;
    }
    void add(Fraction const &F2)
    {
        int lcm = this->deno * F2.deno;
        int x = lcm / this->deno;
        int y = lcm / F2.deno;

        int res = x * (this->num) + (y * F2.num);

        this->num = res;
        this->deno = lcm;
        simple();
    }
    void multiple(Fraction const &F2)
    {
        this->num = this->num * F2.num;
        this->deno = this->deno * F2.deno;
        simple();
    }
    void divide(Fraction const &F2)
    {
        this->num = this->num * F2.deno;
        this->deno = this->deno * F2.num;
        simple();
    }
    void print()
    {
        cout << this->num << "/" << this->deno << endl;
    }
};
int main()
{
    Fraction F1(7, 10);
    Fraction F2(11, 12);

    F1.add(F2);
    F1.print();
    F2.print();

    //F1.num and deno now changed
    F1.multiple(F2);
    F1.print();
    F2.print();
    F1.divide(F2);
    F1.print();
}