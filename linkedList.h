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
    void removeByName(string, string);
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

    if (!head) {  // If the list is empty
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;  // Update tail to the new node
    }
}


// Display all students in the list
void LinkedList::display() const {
    ListNode<Student>* current = head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

void LinkedList::sortByGPA()
{
    ListNode<Student>* sorted = nullptr;
    ListNode<Student>* current = head;

    while (current != nullptr) 
    {
        ListNode<Student>* next = current->next;
        current->prev = nullptr; // Reset previous pointer for each node

        if (!sorted || sorted->data.getgpa() >= current->data.getgpa()) 
        {
            current->next = sorted;
            if (sorted) sorted->prev = current;
            sorted = current;
        } 
        else 
        {
            ListNode<Student>* temp = sorted;
            while (temp->next && temp->next->data.getgpa() < current->data.getgpa()) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next) temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }

        current = next;
    }

    head = sorted;
    tail = head;
    while (tail && tail->next) tail = tail->next; // Ensure tail is updated
} 


// Remove a student by name
void LinkedList::removeByName(string firstName, string lastName) 
{
    ListNode<Student>* current = head;

    // Traverse to find the target node
    while (current) 
    {
        if (current->data.getfirstName() == firstName && current->data.getlastName() == lastName) 
        {
            // Case 1: Node is the head
            if (current == head) {
                head = current->next;
                if (head) 
                    head->prev = nullptr;  // Update the new head's prev pointer
            } 
            // Case 2: Node is the tail
            else if (current == tail) {
                tail = current->prev;
                if (tail) 
                    tail->next = nullptr;  // Update the new tail's next pointer
            } 
            // Case 3: Node is in the middle
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;  // Delete the target node
        }
        current = current->next;  // Move to the next node if no match
    }

    // Optional: Node not found
    cout << "Node not found with name: " << firstName << " " << lastName << "\n";
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
