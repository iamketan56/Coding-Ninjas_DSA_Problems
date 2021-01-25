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
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *insert(Node *head, int data, int positon)
{

    if (head == NULL)
    {
        return head;
    }
    if (positon == 0)
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        return newnode;
    }
    else
    {
        Node *x = insert(head->next, data, positon - 1);
        head->next = x;
        return head;
    }
}
int main()
{
    Node *head = takeinput();
    print(head);
    int data;
    int position;
    cout << "Enter element and postion before where you want to insert" << endl;
    cin >> data >> position;
    head = insert(head, data, position);
    print(head);
}