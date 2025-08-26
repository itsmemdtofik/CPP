#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int data;
        std::unique_ptr<Node> next;

        explicit Node(const int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    std::unique_ptr<Node> head;

public:
    void insertAtBeginning(const int &data) {
        auto newNode = std::make_unique<Node>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
    }

    void insertAtEnd(const int &data) {
        if (!head) {
            head = std::make_unique<Node>(data);
            return;
        }
        Node *currentNode = head.get();
        while (currentNode->next) {
            currentNode = currentNode->next.get();
        }
        currentNode->next = std::make_unique<Node>(data);
    }

    void printList() const {
        if (!head) {
            std::cout << " List is empty!\n";
            return;
        }
        const Node *currentNode = head.get();
        while (currentNode) {
            std::cout << currentNode->data;
            if (currentNode->next) {
                std::cout << " -> ";
            }
            currentNode = currentNode->next.get();
        }
        std::cout << "\n";
    }

    /* Destructor automatically handles the cleanup via unique_ptr*/
    ~LinkedList() = default;
};

int main() {
    try {
        LinkedList list;
        list.insertAtEnd(10);
        list.insertAtEnd(20);

        list.printList();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Memory Allocation Failed: " << e.what() << " \n";
        return EXIT_FAILURE;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
