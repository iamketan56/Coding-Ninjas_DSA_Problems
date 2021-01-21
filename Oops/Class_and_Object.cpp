#include <iostream>
using namespace std;
class student
{
public:
    int age;
    int roll;
};
int main()
{
    //create object statically
    student s1;
    student s2;

    s2.age = 24;
    s2.roll = 123;

    cout << s2.age << " " << s2.roll << endl;
    //Create object dynamically
    student *s3 = new student;
    student *s4 = new student;

    s3->age = 12;
    s3->roll = 121;

    cout << s3->age << " " << s3->roll << endl;

    s4->age = 123;
    s4->roll = 321;

    cout << s4->age << " " << s4->roll << endl;
}