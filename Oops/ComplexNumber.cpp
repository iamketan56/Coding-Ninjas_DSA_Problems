#include <iostream>
using namespace std;
class complexnumber
{
private:
    int real;
    int imagnairy;

public:
    complexnumber(int real, int imagnairy)
    {
        this->real = real;
        this->imagnairy = imagnairy;
    }
    void add(complexnumber const &c2)
    {
        this->real = this->real + c2.real;
        this->imagnairy = this->imagnairy + c2.imagnairy;
    }
    void multiply(complexnumber const &c2)
    {
        int x = (this->real * c2.real) - (this->imagnairy * c2.imagnairy);
        int y = (this->real * c2.imagnairy) + (this->imagnairy * c2.real);
        this->real = x;
        this->imagnairy = y;
    }
    void print()
    {
        cout << this->real << "+" << this->imagnairy << "i";
    }
};
int main()
{
    complexnumber c1(3, 2);
    complexnumber c2(1, 7);
    c1.add(c2);
    c1.multiply(c2);
    c1.print();
}