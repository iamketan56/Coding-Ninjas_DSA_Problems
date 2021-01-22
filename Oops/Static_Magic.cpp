#include <iostream>
using namespace std;
class student
{
private:
    static int totalstudent;

public:
    int roll;
    int age;

    student(int roll, int age)
    {
        this->roll = roll;
        this->age = age;
        totalstudent++;
    }
    static int getstudentcount()
    {
        return totalstudent;
    }
};
int student::totalstudent = 0;

int main()
{
    student s1(1, 12);
    student s2(3, 12);
    cout << s1.age << endl;
    cout << s2.roll << endl;
    cout << s1.getstudentcount();
}
