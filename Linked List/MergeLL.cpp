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

Node *mergelist(Node *h1, Node *h2)
{
    Node *finalhead = NULL;
    Node *finaltail = NULL;
    if (h1->data > h2->data)
    {
        finalhead = h2;
        finaltail = h2;

        h2 = h2->next;
    }
    else
    {
        finaltail = h1;
        finalhead = h1;

        h1 = h1->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data > h2->data)
        {
            finaltail->next = h2;
            finaltail = finaltail->next;

            h2 = h2->next;
        }
        else
        {
            finaltail->next = h1;
            finaltail = finaltail->next;
            h1 = h1->next;
        }
    }

    if (h1 == NULL)
    {
        finaltail->next = h2;
    }
    else
    {
        finaltail->next = h1;
    }

    return finalhead;
}
int main()
{
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *FL;
    cout << "First List is: ";
    print(head1);
    cout << endl;
    cout << "Second List is :";
    print(head2);
    cout << endl;
    FL = mergelist(head1, head2);
    cout << "Final merged list is :";
    print(FL);
}