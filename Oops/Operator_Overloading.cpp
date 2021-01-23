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
    Fraction operator+(Fraction const &F2) const
    {
        int lcm = this->deno * F2.deno;
        int x = lcm / this->deno;
        int y = lcm / F2.deno;

        int res = x * (this->num) + (y * F2.num);

        // this->num = res;
        // this->deno = lcm;
        Fraction F3(res, lcm);
        F3.simple();
        return F3;
    }
    Fraction operator*(Fraction const &F2) const
    {
        Fraction F4(this->num * F2.num, this->deno * F2.deno);
        F4.simple();

        return F4;
    }
    Fraction operator/(Fraction const &F2) const
    {
        Fraction F5(this->num * F2.deno, this->deno * F2.num);

        F5.simple();
        return F5;
    }
    bool operator==(Fraction F2) const
    {
        return this->num == F2.num && this->deno == F2.deno;
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
    F1.print();
    F2.print();
    Fraction F3 = F1 + F2;
    F3.print();
    Fraction F4 = F1 * F2;
    F4.print();
    Fraction F5 = F1 / F2;
    F5.print();
    if (F1 == F2)
    {
        cout << "Eqaul";
    }
    else
    {
        cout << "Not Equal";
    }
}