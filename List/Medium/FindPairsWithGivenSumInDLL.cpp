/**
Given a sorted doubly linked list of positive distinct elements,
the task is to find pairs in a doubly-linked list whose sum is equal to the given value x in sorted order.

Input: 1 -> 2 -> 4 -> 5 -> 6 -> 8 -> 9, target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs (1, 6) and (2, 5) with sum 7.

Approach1: Using Hashing - O(n log n) Time and O(n) Space
Approach2: Using Two Pointer Technique - O(n) Time and O(1) Space
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {
    }
};

/* ------------------ Print Pairs ------------------ */
void printPairs(const vector<pair<int, int> > &pairs) {
    if (pairs.empty()) {
        cout << "No pairs found." << endl;
        return;
    }
    for (auto &p: pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

/* ------------------ Approach 1: Using Hashing ------------------ */
vector<pair<int, int> > getPairsUsingHashing(Node *head, int target) {
    vector<pair<int, int> > result;
    unordered_set<int> seen;

    Node *current = head;
    while (current != nullptr) {
        int complement = target - current->data;
        if (seen.count(complement)) {
            result.push_back({complement, current->data});
        }
        seen.insert(current->data);
        current = current->next;
    }

    /* Sort by first element */
    sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });

    return result;
}

/* ------------------ Approach 2: Two Pointer Technique ------------------ */
vector<pair<int, int> > getPairsUsingTwoPointer(Node *head, int target) {
    vector<pair<int, int> > result;
    if (!head) return result;

    Node *first = head;
    Node *second = head;

    /* Move second to the last node */
    while (second->next != nullptr) second = second->next;

    /* Traverse while pointers do not cross */
    while (first != second && second->next != first) {
        int sum = first->data + second->data;
        if (sum == target) {
            result.push_back({first->data, second->data});
            first = first->next;
            second = second->prev;
        } else if (sum < target) {
            first = first->next;
        } else {
            second = second->prev;
        }
    }

    /* Sort by first element */
    sort(result.begin(), result.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    });

    return result;
}


int main() {
    /* Values: 1 -> 2 -> 4 -> 5 -> 6 -> 8 -> 9 */
    vector<int> values = {1, 2, 4, 5, 6, 8, 9};

    /* Create doubly linked list */
    Node *head = new Node(values[0]);
    Node *current = head;
    for (size_t i = 1; i < values.size(); i++) {
        Node *new_node = new Node(values[i]);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
    }

    int target = 7;

    cout << "Using Two Pointer Technique:" << endl;
    vector<pair<int, int> > pairs = getPairsUsingTwoPointer(head, target);
    printPairs(pairs);

    cout << "Using Hashing Technique:" << endl;
    pairs = getPairsUsingHashing(head, target);
    printPairs(pairs);

    return 0;
}
