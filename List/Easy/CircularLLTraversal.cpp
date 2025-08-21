/*
Given a circular linked list, the task is to print all the elements of this circular linked list.

Example:

Input: 1 2 3 4 5 6
Traversal-of-Circular-Linked-List
Output: 1 2 3 4 5 6

Input: 2 4 6 8 10
Traversal-of-Circular-Linked-List
Output: 2 4 6 8 10

*/
#include <iostream>
using namespace std;

/*
 * Node for Circular Linked List
 */
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

/*
 * Function to print a Circular Linked List
 */
void printCLL(Node *head)
{
    if (!head)
        return;

    Node *current = head;
    do
    {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);

    cout << "NULL" << endl;
}

int main()
{

    Node *head = new Node(11);
    Node *second = new Node(2);
    Node *third = new Node(56);
    Node *fourth = new Node(12);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; /* Circular Connection*/

    cout
        << "Traversal of Circular Linked List:" << endl;
    printCLL(head);

    /* Free memory(optional here, but good practice) */
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
