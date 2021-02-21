#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class car
{
public:
    int x;
    int y;
    int id;

    car(int id, int x, int y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int distance()
    {
        return x * x + y * y;
    }

    void print()
    {
        cout << "ID: " << id << " X distance " << x << " y distance " << y << endl;
    }
};
class carcomapre
{
public:
    bool operator()(car a, car b)
    {
        return a.distance() > b.distance();
    }
};

int main()
{

    priority_queue<car, vector<car>, carcomapre> pq; //
    int x[10] = {25, 6, 17, 8, 29, 4};
    int y[10] = {1, 3, 22, 44, 8, 27};

    for (int i = 0; i < 6; i++)
    {
        car c(i, x[i], y[i]);
        pq.push(c);
    }
    while (!pq.empty())
    {
        car p = pq.top();
        p.print();
        pq.pop();
    }
}