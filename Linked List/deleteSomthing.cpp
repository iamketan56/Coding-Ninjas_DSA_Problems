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
Node *deletesomething(Node *head, int positon)
{
    Node *temp = head;
    int pos = 0;
    if (positon == 0)
    {
        Node *c = temp->next;
        delete temp;
        return c;
    }
    while (temp != NULL && pos < positon - 1)
    {
        temp = temp->next;
        pos++;
    }
    if (positon > pos)
    {
        cout << "Invalid Postion" << endl;
        return head;
    }
    Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    delete a;
    return head;
}
int main()
{
    Node *head = takeinput();
    print(head);

    int position;
    cout << "Enter postion  where you want to delete" << endl;
    cin >> position;
    head = deletesomething(head, position);
    print(head);
}