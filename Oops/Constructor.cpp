#include <iostream>
using namespace std;
class student
{
public:
    int age;
    int roll;

    student()
    {
        cout << "Default Constructor  is called" << endl;
    }

    student(int roll)
    {
        cout << " Constructor with one argument   is called" << endl;
        this->roll = roll;
    }

    student(int roll, int age)
    {
        cout << "Constructor with two argument  is called" << endl;
        this->age = age;
        this->roll = roll;
    }
};
int main()
{
    //create object statically
    student s1;

    student s2(10);
    cout << s2.age << " " << s2.roll << endl;
    student s3(20, 30);
    cout << s3.age << " " << s3.roll << endl;
}