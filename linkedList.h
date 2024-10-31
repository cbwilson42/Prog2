#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"   // Assuming "Student.h" defines the Student class
#include "ListNode.h"  // "ListNode.h" contains the template class definition for ListNode
#include <iostream>
#include <string>

using namespace std;

class LinkedList {
private:
    ListNode<Student>* head; // Define ListNode specifically as ListNode<Student>
    ListNode<Student>* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void append(const Student& s);
    void display() const;
    void sortByGPA();
    void removeByName(const string& firstName, const string& lastName);
    int getSize() const;

    friend ostream& operator<<(ostream& os, const LinkedList& list);
};

// Constructor
LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor to delete each node and free memory
LinkedList::~LinkedList() {
    ListNode<Student>* current = head;
    while (current) {
        ListNode<Student>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Append a new node with student data to the end of the list
void LinkedList::append(const Student& s) {
    ListNode<Student>* newNode = new ListNode<Student>(s);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Display all students in the list
void LinkedList::display() const {
    ListNode<Student>* current = head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

// Sort the list by GPA in descending order (highest GPA first)
void LinkedList::sortByGPA() {
    if (!head || !head->next) return;

    for (ListNode<Student>* i = head; i != nullptr; i = i->next) {
        for (ListNode<Student>* j = i->next; j != nullptr; j = j->next) {
            if (i->data.getgpa() < j->data.getgpa()) {
                swap(i->data, j->data);
            }
        }
    }
}

// Remove a student by name
void LinkedList::removeByName(const string& firstName, const string& lastName) {
    ListNode<Student>* current = head;
    while (current) {
        if (current->data.getfirstName() == firstName && current->data.getlastName() == lastName) {
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
            } else if (current == tail) {
                tail = tail->prev;
                if (tail) tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            size--;
            return;
        }
        current = current->next;
    }
}

// Get the size of the list
int LinkedList::getSize() const {
    return size;
}

// Overload << operator for easy printing of the list
ostream& operator<<(ostream& os, const LinkedList& list) {
    ListNode<Student>* current = list.head;
    while (current) {
        os << current->data << endl;
        current = current->next;
    }
    return os;
}

#endif
