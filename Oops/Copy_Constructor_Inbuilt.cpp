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
    student(int age, int roll)
    {
        this->age = age;
        this->roll = roll;
    }
};
int main()
{
    student s1;
    student s2(10, 101);

    //copy
    student s3(s2);
    cout << s3.age << " " << s3.roll << endl;

    student *s4 = new student(11, 111);
    student *s5 = new student(*s4);

    cout << s5->age << " " << s5->roll << endl;

    student *s6 = new student(s2);
    cout << s6->age << " " << s6->roll << endl;
}