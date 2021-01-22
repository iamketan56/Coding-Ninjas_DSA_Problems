#include <iostream>
#include <string.h>
using namespace std;
class student
{
private:
    int age;
    char *name;

public:
    student(int age, char *name)
    {

        this->age = age;
        // //shallow copy
        // this->name = name;
        this->name = new char[strlen(name) + 1]; //deep copy
        strcpy(this->name, name);
    }
    void display()
    {
        cout << this->age << " " << this->name << endl;
    }
};
int main()
{
    char name[] = "ketan";
    student s1(21, name);
    s1.display();
    name[4] = 's';
    student s2(22, name);
    s2.display();

    s1.display();
}
