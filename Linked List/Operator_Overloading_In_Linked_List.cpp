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
istream &operator>>(istream &is, Node *&head)
{
    takeinput();
    return is;
}
ostream &operator<<(ostream &os, Node *head)
{
    print(head);
    return os;
}
int main()
{

    Node *head1 = NULL;
    Node *head2 = NULL;
    cin >> head1;
    cin >> head2;
    cout << head1 << endl;
    cout << head2;
}
