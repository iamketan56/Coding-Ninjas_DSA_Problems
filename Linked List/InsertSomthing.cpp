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
void insert(Node *head, int data, int positon)
{
    Node *temp = head;
    Node *newnode = new Node(data);
    int pos = 0;
    while (temp!= NULL && pos < positon - 1)
    {
        temp = temp->next;
        pos++;
    }
	if(temp!=NULL)
{
    Node *a = temp->next;
    temp->next = newnode;
    newnode->next = a;
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
    insert(head, data, position);
    print(head);
}