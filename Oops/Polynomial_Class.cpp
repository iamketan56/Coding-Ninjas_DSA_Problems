#include <iostream>
using namespace std;
class Polynomial
{
    int *degreecoff;
    int capacity;

public:
    Polynomial()
    {
        degreecoff = new int[5];
        capacity = 5;
        for (int i = 0; i < capacity; i++)
        {
            degreecoff[i] = 0;
        }
    }
    void setcofficient(int degree, int value)
    {
        if (degree == capacity)
        {
            int *newdata = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newdata[i] = degreecoff[i];
            }
            delete[] degreecoff;
            degreecoff = newdata;
            capacity = 2 * capacity;
        }
        degreecoff[degree] = value;
    }
    void print()
    {
        for (int i = 0; i < this->capacity; i++)
        {
            if (this->degreecoff[i] > 0 || this->degreecoff[i] < 0)
            {
                cout << this->degreecoff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
    Polynomial operator+(Polynomial const &Poly)
    {
        Polynomial Pnew;
        for (int i = 0; i < capacity; i++)
        {
            Pnew.degreecoff[i] = this->degreecoff[i] + Poly.degreecoff[i];
        }
        return Pnew;
    }

    Polynomial operator-(Polynomial const &Poly)
    {
        Polynomial Pnew;
        for (int i = 0; i < capacity; i++)
        {
            Pnew.degreecoff[i] = this->degreecoff[i] - Poly.degreecoff[i];
        }
        return Pnew;
    }
};
int main()
{
    Polynomial p1;
    p1.setcofficient(3, 4);
    p1.setcofficient(2, 3);
    p1.setcofficient(1, 2);
    p1.setcofficient(0, 4);
    p1.print();
    Polynomial p2;
    p2.setcofficient(3, 6);
    p2.setcofficient(2, 5);
    p2.setcofficient(1, 3);
    p2.setcofficient(0, 1);
    p2.print();

    Polynomial P3;
    // // P3 = p1 + p2;
    // P3.print();
    Polynomial P4;
    P4 = p1 - p2;
    P4.print();
}
