#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    T data;              // Stores data of template type
    ListNode* next;      // Pointer to the next node
    ListNode* prev;      // Pointer to the previous node (optional for doubly-linked list)

    // Constructor initializes data and sets next and prev pointers to nullptr
    ListNode(const T& d) : data(d), next(nullptr), prev(nullptr) {}
};

#endif
