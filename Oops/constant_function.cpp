#include <iostream>
using namespace std;
class complex
{
private:
    int real;
    int img;

public:
    int const getreal()
    {
        return this->real;
    }
    int const getimg()
    {
        return this->img;
    }
    void setreal(int real)
    {
        this->real = real;
    }
    void setimg(int img)
    {
        this->img = img;
    }
};
int main()
{
    complex c1;
    c1.setreal(10);
    c1.setimg(2);
    cout << c1.getreal() << endl;
    cout << c1.getimg() << endl;
    complex const c2; // we can do this
    c2.getreal();
    c2.getimg();

    //can't do this
    c2.setreal();
    c3.setreal();
}