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
bool iflooppresent_then_remove(Node *head)
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
            Node *temp = fast->next;
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            cout << "Starting Point Of Loop was : " << slow->data << " and ending point of loop was " << temp->data << endl;
            temp->next = NULL;
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

    if (iflooppresent_then_remove(First))
    {
        cout << "Loop was present" << endl;
    }
    else
    {
        cout << "Loop was not Present" << endl;
    }
    cout << "After Removal of Loop" << endl;
    while (First != NULL)
    {
        cout << First->data << " ";
        First = First->next;
    }
}