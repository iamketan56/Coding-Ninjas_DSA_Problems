#include <iostream>
using namespace std;
class student
{
public:
    int age;
    const int roll;
    int &x; //reference varriable for age

public:
    student(int r, int age) : roll(r), age(age), x(this->age) //here we are changin value of constant variable
    {
    }
    void print()
    {
        cout << "age :" << this->age << endl;
        cout << "roll : " << this->roll << endl;
        cout << "Value of ref varriable: " << x;
    }
};
int main()
{
    student s1(10, 20);
    s1.print();
}