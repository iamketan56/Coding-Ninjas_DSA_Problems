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
int Kthnode(Node *head, int k)
{
    Node *fast = head;
    Node *slow = head;
    int count = 0;
    while (count != k)
    {
        if (fast->next == NULL)
        {
            return -1;
        }
        else
        {

            fast = fast->next;
            count++;
        }
    }
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}
int main()
{
    Node *head = takeinput();
    print(head);
    int k;
    cout << endl;
    cout << "Enter the K value " << endl;
    cin >> k;
    cout << Kthnode(head, k);
}