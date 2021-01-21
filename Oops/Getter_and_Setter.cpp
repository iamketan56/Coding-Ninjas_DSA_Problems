#include <iostream>
using namespace std;
class student
{
public:
    int age;

private:
    int roll;

public:
    int getroll()
    {
        return roll;
    }
    void setroll(int a)
    {
        roll = a;
    }
};
int main()
{
    //create object statically
    student s1;
    student s2;

    s2.age = 24;
    s2.setroll(10);
    cout << s2.age << " " << s2.getroll() << endl;
    //Create object dynamically
    student *s3 = new student;
    student *s4 = new student;

    s3->age = 12;
    s3->setroll(22);

    cout << s3->age << " " << s3->getroll() << endl;

    s4->age = 123;
    s4->setroll(111);
    cout << s4->age << " " << s4->getroll() << endl;
}