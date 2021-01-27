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
class Pair
{
public:
    Node *head;
    Node *tail;
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
// O(N^2) approch
Node *reverselist(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *small = reverselist(head->next);
    Node *temp = small;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;

    return small;
}

// O(N) approach
Pair reverselist_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallans = reverselist_2(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallans.head;
    ans.tail = head;
    return ans;
}
Node *reverselistbetter(Node *head)
{
    return reverselist_2(head).head;
}
int main()
{
    Node *head = takeinput();
    print(head);
    cout << "Reverse List : ";
    head = reverselistbetter(head);
    print(head);
}