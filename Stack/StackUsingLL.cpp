#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *head = NULL;
int size = 0;
void push(int data)
{

    Node *newnode = new Node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    size++;
}
int pop()
{
    if (!empty())
    {
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }
}
bool empty()
{
    return size == 0;
}
int top()
{
    return head->data;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    cout << pop() << " ";
    cout << top();
}
