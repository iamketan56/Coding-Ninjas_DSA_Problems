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
bool islooppresent(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *First = new Node(10);
    Node *second = new Node(12);
    Node *third = new Node(14);
    Node *fourth = new Node(16);
    Node *Fifth = new Node(17);
    Node *sixth = new Node(18);
    Node *Seventh = new Node(20);
    First->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = Fifth;
    Fifth->next = sixth;
    sixth->next = Seventh;
    Seventh->next = third;

    if (islooppresent(First))
    {
        cout << "Loop Is present" << endl;
    }
    else
    {
        cout << "Loop is not Present" << endl;
    }
}