#include <iostream>
using namespace std;

class SinglyLinkedList
{
private:
    // Define the Node class
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

    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // 1. Insert at the beginning
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at the end
    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    // 3. Insert after a node
    void insertAfter(int prevData, int data)
    {
        Node *current = head;
        while (current != nullptr && current->data != prevData)
        {
            current = current->next;
        }
        if (current != nullptr)
        {
            Node *newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
        }
        else
        {
            cout << "Node with data " << prevData << " not found." << endl;
        }
    }

    // 4. Delete by value
    void deleteByValue(int data)
    {
        if (head == nullptr)
            return;
        if (head->data == data)
        {
            head = head->next;
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->data != data)
        {
            current = current->next;
        }
        if (current->next != nullptr)
        {
            current->next = current->next->next;
        }
        else
        {
            cout << "Node with data " << data << " not found." << endl;
        }
    }

    // 5. Delete from the beginning
    void deleteFromBeginning()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 6. Delete from the end
    void deleteFromEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    // 7. Delete after a node
    void deleteAfter(int prevData)
    {
        Node *current = head;
        while (current != nullptr && current->data != prevData)
        {
            current = current->next;
        }
        if (current != nullptr && current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            cout << "No node found to delete after " << prevData << endl;
        }
    }

    // 8. Search an element
    bool search(int data)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }

    // 9. Traverse the list
    void traverse()
    {
        if (head == nullptr)
        {
            cout << "The list is empty." << endl;
            return;
        }
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // 10. Reverse the list
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    // 11. Find the length of the list
    int length()
    {
        int count = 0;
        Node *current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    // 12. Find the middle element
    int findMiddle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return (slow != nullptr) ? slow->data : -1;
    }

    // 13. Detect a loop
    bool detectLoop()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // 14. Merge two sorted linked lists
    static SinglyLinkedList mergeSorted(SinglyLinkedList &list1, SinglyLinkedList &list2)
    {
        SinglyLinkedList mergedList;
        Node *current1 = list1.head;
        Node *current2 = list2.head;
        while (current1 != nullptr && current2 != nullptr)
        {
            if (current1->data < current2->data)
            {
                mergedList.insertAtEnd(current1->data);
                current1 = current1->next;
            }
            else
            {
                mergedList.insertAtEnd(current2->data);
                current2 = current2->next;
            }
        }
        while (current1 != nullptr)
        {
            mergedList.insertAtEnd(current1->data);
            current1 = current1->next;
        }
        while (current2 != nullptr)
        {
            mergedList.insertAtEnd(current2->data);
            current2 = current2->next;
        }
        return mergedList;
    }

    // 15. Remove duplicates
    void removeDuplicates()
    {
        Node *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }

    // 16. Remove N-th node from the end
    void removeNthFromEnd(int n)
    {
        int len = length();
        if (n > len)
            return;
        if (n == len)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *current = head;
        for (int i = 1; i < len - n; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // 17. Get N-th node from the end
    int getNthFromEnd(int n)
    {
        int len = length();
        if (n > len)
            return -1;
        Node *current = head;
        for (int i = 1; i < len - n; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    // 18. Check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // 19. Clear the list
    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 20. Clone the list
    SinglyLinkedList cloneList()
    {
        SinglyLinkedList clonedList;
        Node *current = head;
        while (current != nullptr)
        {
            clonedList.insertAtEnd(current->data);
            current = current->next;
        }
        return clonedList;
    }

    // 21. Swap nodes in pairs
    void swapPairs()
    {
        Node *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            current = current->next->next;
        }
    }

    // Main method to drive the operations using switch case
    static void menu()
    {
        SinglyLinkedList list;
        int choice;

        while (true)
        {
            cout << "\nChoose an operation:" << endl;
            cout << "1. Insert at the beginning" << endl;
            cout << "2. Insert at the end" << endl;
            cout << "3. Insert after a node" << endl;
            cout << "4. Delete by value" << endl;
            cout << "5. Delete from the beginning" << endl;
            cout << "6. Delete from the end" << endl;
            cout << "7. Delete after a node" << endl;
            cout << "8. Search an element" << endl;
            cout << "9. Traverse" << endl;
            cout << "10. Reverse" << endl;
            cout << "11. Length" << endl;
            cout << "12. Find middle" << endl;
            cout << "13. Detect loop" << endl;
            cout << "14. Merge two sorted lists" << endl;
            cout << "15. Remove duplicates" << endl;
            cout << "16. Remove N-th node from the end" << endl;
            cout << "17. Get N-th node from the end" << endl;
            cout << "18. Check if empty" << endl;
            cout << "19. Clear the list" << endl;
            cout << "20. Clone the list" << endl;
            cout << "21. Swap pairs" << endl;
            cout << "22. Exit" << endl;

            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter data: ";
                list.insertAtBeginning(std::cin);
                break;
            case 2:
                cout << "Enter data: ";
                list.insertAtEnd(cin);
                break;
            // Continue with other cases...
            case 22:
                cout << "Exiting..." << endl;
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
            }
        }
    }
};

int main()
{
    SinglyLinkedList::menu();
    return 0;
}
