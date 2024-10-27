#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"

struct Node 
{
    Student student;
    Node* next;
    Node(Student s) : student(s), next(nullptr) {}
};

class LinkedList 
{
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void addStudent(const Student& student);
    bool removeStudent(int id);
    void displayStudents() const;
};

#endif
