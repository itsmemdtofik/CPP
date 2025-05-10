#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to create the binary tree
Node *createTree()
{
    int data;
    cout << "\nEnter the data (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    Node *root = new Node(data);

    cout << "Enter the left child of " << root->data << ": ";
    root->left = createTree();

    cout << "Enter the right child of " << root->data << ": ";
    root->right = createTree();

    return root;
}

// Inorder traversal
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
}

// Postorder traversal
void postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " -> ";
}

// Preorder traversal
void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " -> ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int choice;

    while (true)
    {
        cout << "\nSelect the operation:\n";
        cout << "------------------------------\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "------------------------------\n";

        switch (choice)
        {
        case 1:
            root = createTree();
            break;
        case 2:
            if (root == nullptr)
            {
                cout << "Tree is empty. Please create a tree first.\n";
            }
            else
            {
                cout << "\nInorder Traversal:\n";
                inorder(root);
                cout << endl;
            }
            break;
        case 3:
            if (root == nullptr)
            {
                cout << "Tree is empty. Please create a tree first.\n";
            }
            else
            {
                cout << "\nPreorder Traversal:\n";
                preorder(root);
                cout << endl;
            }
            break;
        case 4:
            if (root == nullptr)
            {
                cout << "Tree is empty. Please create a tree first.\n";
            }
            else
            {
                cout << "\nPostorder Traversal:\n";
                postorder(root);
                cout << endl;
            }
            break;
        case 5:
            cout << "Exiting...\n";
            // Clean up memory (optional for program exit)
            return 0;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    }

    return 0;
}